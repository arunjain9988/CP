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


int used;

void initST(int ST[],int L[],int R[],int start,int end,int idx) {
    if (start>end) return;
    used = max(used,idx);
    if (start==end){
        ST[idx] = 0;
        return;
    }
    int mid = (start+end)/2;
    initST(ST,L,R,start,mid,2*idx);
    initST(ST,L,R,mid+1,end,(2*idx)+1);
    L[idx] = 2*idx;
    R[idx] = (2*idx)+1;
    ST[idx] = ST[L[idx]]+ST[R[(idx)]]; 
}

int update(int ST[],int L[],int R[],int start,int end,int val,int idx) {
    if (val<start || val>end) return idx;
    if (start == end) {
        ++used;
        ST[used] = ST[idx]+1;
        return used;
    }
    // partial overlap
    ++used;
    int mid = (start+end)/2;
    int copy = used;
    L[copy] = update(ST,L,R,start,mid,val,L[idx]);
    R[copy] = update(ST,L,R,mid+1,end,val,R[idx]);
    return (ST[copy] = ST[L[copy]]+ST[R[copy]],copy);
}

int query(int ST[],int L[],int R[],int start,int end,int qstart,int qend,int idx) {
    if (qstart>end || qend<start) return 0;
    if (start>=qstart && end<=qend) {
        return ST[idx];
    }
    int mid = (start+end)/2;
    return query(ST,L,R,start,mid,qstart,qend,L[idx])+query(ST,L,R,mid+1,end,qstart,qend,R[idx]);
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
    int A[n];
    vector<ii> ar;
    map<int,int> mapping;
    int freq[n+1];;;
    loop(i,n) {
        cin>>A[i];
        ar.pb(mp(A[i],i+1));
    } 
    ar.pb(mp(2000000000,n+1));
    sort(all(ar));
    mapping[ar[0].first] = 1;
    int cur = 1;
    floop(i,1,n) {
        if (ar[i].first == ar[i-1].first) mapping[ar[i].first] = mapping[ar[i-1].first];
        else mapping[ar[i].first] = ++cur;
    }
    // for (auto u:mapping) {
    //     cout<<u.first<<" "<<u.second<<'\n';
    // }
    int const N = cur;
    int const LOGN = 65;
    int ST[N*LOGN];
    memset(ST,0,sizeof(ST));
    int L[N*LOGN];
    int R[N*LOGN];
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    used = 0;
    initST(ST,L,R,1,cur,1);
    int versions[n+2];
    versions[0] = 1;
    loop(i,n+1) {
        versions[i+1] = update(ST,L,R,1,cur,mapping[A[i]],versions[i]);
        // cout<<query(ST,L,R,1,cur,1,1,versions[i+1])<<" "<<query(ST,L,R,1,cur,2,2,versions[i+1])
        // <<" "<<query(ST,L,R,1,cur,3,3,versions[i+1])<<" "<<query(ST,L,R,1,cur,4,4,versions[i+1])
        // <<" "<<query(ST,L,R,1,cur,5,5,versions[i+1])<<" "<<query(ST,L,R,1,cur,5,5,versions[i+1])<<endl;
    }

    int q;
    cin>>q;
    int l,r,k;
    while(q--) {
        cin>>l>>r>>k;
        int ans = 0;
        int tos = mapping[(*upper_bound(all(ar),mp(k,1000000009))).first];
        // cout<<tos<<" ";
        ans += query(ST,L,R,1,cur,tos,cur,versions[r]);
        ans -= query(ST,L,R,1,cur,tos,cur,versions[l-1]);
        cout<<ans<<'\n';
    }
    // for (int i=0; i<20; i++) {
    //     cout<<i<<' '<<ST[i]<<' '<<L[i]<<' '<<R[i]<<endl;
    // }
    return 0;
}
