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
const int LOGN = 30;

int ST[N*LOGN];
int L[N*LOGN];
int R[N*LOGN];
int A[N];
int V[N];
int assigned = 0;

void build(int start,int end,int idx) {
    if (start == end) return;
    int mid = (start+end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    L[idx] = idx*2;
    R[idx] = idx*2+1;
    assigned = max(assigned,idx*2+1);
}

int update(int start,int end,int idx,int pos) {
    if (start>pos || end<pos) return idx;
    int id = ++assigned;
    if (start>=pos && end<=pos) {
        ST[id] = ST[idx]+1;
        return id;
    }
    int mid = (start+end)/2;
    L[id] = update(start,mid,L[idx],pos);
    R[id] = update(mid+1,end,R[idx],pos);
    ST[id] = ST[L[id]]+ST[R[id]];
    return id;
}

int query(int start,int end,int idx1,int idx2,int k) {
    // return 1;
    if (start == end) return start;
    int mid = (start+end)/2;
    int cnt = ST[L[idx1]]-ST[L[idx2]];
    if (cnt>=k) {
        return query(start,mid,L[idx1],L[idx2],k);
    }
    return query(mid+1,end,R[idx1],R[idx2],k-cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    // scanf("%d%d", &n,&m);
    cin>>n>>m;
    vector<int> permute;
    loop(i,n) {
        cin>>A[i];
        permute.pb(i);
    }
    sort(all(permute),[](const int &a,const int &b){return A[a]<A[b];});
    map<int,int> realtocompressed;
    loop(i,permute.size()) {
        // cout<<A[permute[i]]<<" "<<i<<endl;
        realtocompressed[A[permute[i]]] = i;
    }
    build(0,permute.size()-1,1);
    V[0] = 1;
    loop(i,permute.size()) {
        // cout<<realtocompressed[A[i]]<<" ";
        V[i+1] = update(0,permute.size()-1,V[i],realtocompressed[A[i]]);
    }
    // for (int i=0; i<5; i++) {
    //     cout<<V[i]<<'\n';
    // }
    // cout<<endl;
    // for (int i=0; i<50; i++) {
    //     cout<<i<<" "<<ST[i]<<" "<<L[i]<<" "<<R[i]<<'\n';
    // }
    
    int l,r,k;
    loop(i,m) {
        cin>>l>>r>>k;
        // trace3(l,r,k);
        cout<<A[permute[query(0,permute.size()-1,V[r],V[l-1],k)]]<<'\n';
    }
    return 0;
}
