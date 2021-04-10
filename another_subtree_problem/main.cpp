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

#pragma comment(linker, "/STACK:2000000")
// #pragma comment(linker, "/HEAP:2000000")

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

const int N = 50005;
int A[N];
int entry[N];
// int dfsentry[N];
int ext[N];
int parent[N];
vector<int> Tree[N];
int S[N];
int timee = 0;
int ST[4*N];
int lazy[4*N];

void build(int start,int end,int idx) {
    // trace3(start,end,idx);
    if (start == end) {
        ST[idx] = A[S[start]-1];
        return;
    }
    int mid = (start+end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    ST[idx] = (ST[idx*2]*(ll)ST[idx*2+1])%MOD;
}

ll pw(int a,int b,int m) {
    ll ret = 1;
    while(b) {
        if (b&1) ret = (ret*a)%m;
        a = (a*(ll)a)%m;
        b>>=1;
    }
    return ret;
}

void update(int start,int end,int idx,int qstart,int qend,int val) {
    if (lazy[idx] != 0) {
        ST[idx] = (ST[idx] * (ll)(pw(lazy[idx],end-start+1,MOD)))%MOD;
        if (start != end) {
            lazy[idx*2] = ((ll)lazy[idx*2]*lazy[idx])%MOD;
            lazy[idx*2+1] = ((ll)lazy[idx*2+1]*lazy[idx])%MOD;
        }
        lazy[idx] = 0;
    }
    if (start>qend || end<qstart) return;
    if (start >= qstart && end <= qend){
        ST[idx] = (ST[idx] * (ll)(pw(val,end-start+1,MOD)))%MOD;
        if (start != end) {
            lazy[idx*2] = ((ll)lazy[idx*2]*lazy[idx])%MOD;
            lazy[idx*2+1] = ((ll)lazy[idx*2+1]*lazy[idx])%MOD;
        }
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,idx*2,qstart,qend,val);
    update(mid+1,end,idx*2+1,qstart,qend,val);
    ST[idx] = (ST[idx*2]*(ll)ST[idx*2+1])%MOD;
}

int query(int start,int end,int idx,int qstart,int qend) {
    if (lazy[idx] != 0) {
        ST[idx] = (ST[idx] * (ll)(pw(lazy[idx],end-start+1,MOD)))%MOD;
        if (start != end) {
            lazy[idx*2] = ((ll)lazy[idx*2]*lazy[idx])%MOD;
            lazy[idx*2+1] = ((ll)lazy[idx*2+1]*lazy[idx])%MOD;
        }
        lazy[idx] = 0;
    }
    if (qstart > end || qend < start) return 1;
    if (start >= qstart && end <= qend) {
        return ST[idx];
    }
    int mid = (start+end)/2;
    int  l = query(start,mid,idx*2,qstart,qend);
    int r = query(mid+1,end,idx*2+1,qstart,qend);
    return (l*(ll)r)%MOD;
}

void dfs(int node=1,int par=-1) {
    // dfsentry[node] = ++tm;
    // trace3(timee,node,par);
    entry[node] = ++timee;
    S[timee] = node;
    parent[node] = par;
    // for (int u:Tree[node]){
    //     if (u == par) continue;
    //     dfs(u,node);
    // }
    for (int i=0; i<Tree[node].size(); i++) {
        if (Tree[node][i] == par) continue;
        dfs(Tree[node][i],node);
    }
    ext[node] = timee;
}

bool test[50004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    int a,b;
    loop(i,n) {
        cin>>A[i];
        Tree[n+1].clear();
    }
    loop(i,n-1){
        cin>>a>>b;
        if (a<=0 || b<=0) {
            // Tree[a].pb(1);
            // Tree[1].pb(a);
            continue;
        }
        test[a] = true;
        test[b] = true;
        Tree[a].pb(b);
        Tree[b].pb(a);
    }
    // floop(i,1,50000) {
    //     if (!test[i]) cout<<i<<endl;
    // }
    // cout<<endl;
    dfs();
    build(1,timee,1);
    // for (int i=0; i<n+1; i++) {
    //     cout<<i<<" "; 
    //     for (int u:Tree[i]) cout<<u<<" ";
    //     cout<<endl;
    // }
    // loop(i,n+1) cout<<entry[i]<<" "<<ext[i]<<" "<<parent[i]<<" "<<S[i]<<endl;
    int t,x,v;
    // for (int i=1;i<=20; i++) cout<<i<<" "<<ST[i]<<"\n";
    while(q--) {
        cin>>t;
        if (t<=2) {
            cin>>x>>v;
            if (t==2) {
                v = pw(v,MOD-2,MOD);
            }
            update(1,timee,1,entry[x],ext[x],v);
        }
        else {
            cin>>x;
            cout<<(query(1,timee,1,entry[x],ext[x])+MOD)%MOD<<'\n';
        }
    }
    return 0;
}
