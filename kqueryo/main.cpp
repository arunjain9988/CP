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
vector<int> ST[100005*4+1];

void init(int start,int end,int idx) {
    // if (start>end) return;
    if (start == end) {
        ST[idx].push_back(A[start]);
        return;
    }
    int mid = (start+end)/2;
    init(start,mid,idx*2);
    init(mid+1,end,idx*2+1);
    merge(all(ST[idx*2]),all(ST[idx*2+1]),back_inserter(ST[idx]));
}

int query(int start,int end,int qstart,int qend,int idx,int k) {
    if (qstart>end || qend<start) return 0;
    if (qstart<=start && qend >=end) {
        return (ST[idx].size() - (upper_bound(all(ST[idx]),k)-ST[idx].begin()));
    }
    int mid = (start+end)/2;
    int l = query(start,mid,qstart,qend,idx*2,k);
    int r = query(mid+1,end,qstart,qend,idx*2+1,k);
    return l+r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    loop(i,n) {
        cin>>A[i];
    }
    init(0,n-1,1);
    int q,l,r,k;
    cin>>q;
    int ans = 0;
    while(q--) {
        cin>>l>>r>>k;
        l = l^ans;
        r = r^ans;
        k = k^ans;
        if (l<1) l = 1;
        if (r>n) r = n;
        if (r<l){
            cout<<"0\n";
            ans=0;
            continue;
        }
        ans = query(0,n-1,l-1,r-1,1,k);
        cout<<ans<<'\n';
    }
    return 0;
}
