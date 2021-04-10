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


struct Node{
    ll maxpre;
    ll maxsuf;
    ll sum;
    ll ans;
    Node() {
        maxpre = 0,maxsuf=0,sum=0,ans=0;
    }
    Node(int para) {
        maxpre = INT_MIN;
        maxsuf = INT_MIN;
        sum = 0;
        ans = INT_MIN;
    }
};


Node ST[50000*4+1];
int A[50001];

void init(int start,int end,int idx) {
    if (start>end) return;
    if (start==end) {
        // ST[idx] = A[start];
        ST[idx].ans = ST[idx].maxpre = ST[idx].maxsuf = ST[idx].sum = A[start];
        return;
    }
    int mid = (start+end)/2;
    init(start,mid,idx*2);
    init(mid+1,end,idx*2+1);
    ST[idx].ans = max(max(ST[idx*2].ans,ST[idx*2+1].ans),ST[idx*2].maxsuf+ST[idx*2+1].maxpre);
    ST[idx].maxpre = max(ST[idx*2].maxpre,ST[idx*2].sum+ST[idx*2+1].maxpre);
    ST[idx].maxsuf = max(ST[idx*2+1].maxsuf,ST[idx*2+1].sum+ST[idx*2].maxsuf);
    ST[idx].sum = ST[idx*2].sum+ST[idx*2+1].sum;
}

Node query(int start,int end,int qstart,int qend,int idx) {
    if (qstart>end || qend<start){
        return Node(1);
    }
    if (qstart<=start && qend>=end) {
        return ST[idx];
    }
    int mid = (start+end)/2;
    Node left = query(start,mid,qstart,qend,idx*2);
    Node right = query(mid+1,end,qstart,qend,idx*2+1);
    Node ret;
    ret.ans = max(max(left.ans,right.ans),left.maxsuf+right.maxpre);
    ret.maxpre = max(left.maxpre,left.sum+right.maxpre);
    ret.maxsuf = max(right.maxsuf,right.sum+left.maxsuf);
    ret.sum = left.sum+right.sum;
    return ret;
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
    // int A[n];
    loop(i,n) cin>>A[i];
    init(0,n-1,1);
    int q;
    cin>>q;
    int l,r;
    while(q--) {
        cin>>l>>r;
        Node p = query(0,n-1,l-1,r-1,1);
        cout<<p.ans<<'\n';
    }
    return 0;
}
