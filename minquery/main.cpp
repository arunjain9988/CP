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

int A[100005];
int st[100005*4+1];

void build(int start,int end,int idx) {
    if (start == end) {
        st[idx] = A[start];
        return;
    }
    int mid   = (start+end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    st[idx] = min(st[idx*2],st[idx*2+1]);
}

void update(int start,int end,int idx,int updidx,int val) {
    if (start > updidx || end < updidx) return;
    if (start == end){
        st[idx] = val;
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,idx*2,updidx,val);
    update(mid+1,end,idx*2+1,updidx,val);
    st[idx] = min(st[idx*2],st[idx*2+1]);
}

int query(int start,int end,int idx,int qstart,int qend) {
    if (qstart >end || qend < start) {
        return INT_MAX;
    }
    if (qstart <= start && qend >= end) {
        return st[idx];
    }
    int mid = (start+end)/2;
    int l = query(start,mid,idx*2,qstart,qend);
    int r = query(mid+1,end,idx*2+1,qstart,qend);
    return min(l,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q,l,r;
    char type;
    cin>>n>>q;
    loop(i,n) cin>>A[i];
    build(0,n-1,1);
    while(q--) {
        cin>>type>>l>>r;
        if (type == 'q'){
            cout<<query(0,n-1,1,l-1,r-1)<<'\n';
        }
        else {
            update(0,n-1,1,l-1,r);
        }
    }
    return 0;
}
