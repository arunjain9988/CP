#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, r) for (int i = (int)(0); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back
#define mp make_pair

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)


// trace program
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl

// useful constants
#define MOD 1000000007
#define EPS (double)1e-6

using namespace std;


// Important header files   ordered set
// #include <ext/pb_ds/assoc_container.hpp> // Common file  
// #include <ext/pb_ds/tree_policy.hpp>  
// #include <functional> // for less

// using namespace __gnu_pbds;

// typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

const int N = 100005;

int st[4*N+10];
int pw2[N+10];
int lazy[N+10];

void update(int start,int end,int idx,int bit,int ustart,int uend) {
    if (lazy[idx] != -1) {
        if (lazy[idx] == 0){
            st[idx] = 0;
            if (start != end) {
                lazy[idx*2] = 0;
                lazy[idx*2+1] = 0;
            }
        }
        else {
            st[idx] = pw2[end-start+1]-1;
            if (start != end) {
                lazy[idx*2] = 1;
                lazy[idx*2+1] = 1;
            }
        }
        lazy[idx] = -1;
    }
    if (ustart > end || uend < start) return;
    if (ustart <= start && uend >= end) {
        if (bit == 0){
            st[idx] = 0;
            if (start!=end) {
                lazy[idx*2] = 0;
                lazy[idx*2+1] = 0;
            }
        }
        else {
            st[idx] = pw2[end-start+1]-1;
            if (start!=end) {
                lazy[idx*2] = 1;
                lazy[idx*2+1] = 1;
            }
        }
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,idx*2,bit,ustart,uend);
    update(mid+1,end,idx*2+1,bit,ustart,uend);
    st[idx] = ((st[idx*2] * (ll)pw2[end-mid]) + st[idx*2+1])%MOD;
}

int query(int start,int end,int idx,int qstart,int qend) {
    if (lazy[idx] != -1) {
        if (lazy[idx] == 0){
            st[idx] = 0;
            if (start != end) {
                lazy[idx*2] = 0;
                lazy[idx*2+1] = 0;
            }
        }
        else {
            st[idx] = pw2[end-start+1]-1;
            if (start != end) {
                lazy[idx*2] = 1;
                lazy[idx*2+1] = 1;
            }
        }
        lazy[idx] = -1;
    }
    if (qstart >end || qend < start) {
        return 0;
    }
    if (qstart<=start and qend>=end) {
        return st[idx];
    }
    int mid = (start+end)/2;
    int l = query(start,mid,idx*2,qstart,qend);
    int r= query(mid+1,end,idx*2+1,qstart,qend);
    if (qend-mid > 0) {
        return (((l*(ll)pw2[qend-mid])%MOD) + r)%MOD;
    }
    else {
        return l;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    memset(lazy,-1,sizeof(lazy));
    pw2[0] = 1;
    for (int i=1; i<=n; i++) {
        pw2[i] = (pw2[i-1]*(ll)2)%MOD;
    }
    int type,l,r;
    while(q--) {
        cin>>type>>l>>r;
        if (type <= 1) {
            update(0,n-1,1,type,l,r);
        }
        else {
            cout<<query(0,n-1,1,l,r)<<'\n';
        }
        // for (int i=0; i<12; i++) cout<<i<<" i "<<st[i]<<'\n';
        // cout<<query(0,n-1,1,0,0)<<' '<<query(0,n-1,1,1,1)<<' '<<query(0,n-1,1,2,2)<<endl;
    }
    return 0;
}
