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
// template <typename T>
// using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

// Custom Hash for unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};

const int N=10005;
const int LOGN = 15;
vii tree[N];
int subsize[N],parent[N][LOGN];
int hldarr[N];
int arridx=0,chainidx=1,chainno[N],depth[N],chainhead[N],posinhld[N],segment[4*N];
int curchainhead = 1;
vii edges;

void dfs(int node,int par=1,int dep=0) {
    depth[node] = dep;
    parent[node][0] = par;
    subsize[node] = 1;
    for (ii u:tree[node]) {
        if (u.first==par) continue;
        dfs(u.first,node,dep+1);
        subsize[node] += subsize[u.first];
    }
}

void buildhld(int node,int par=1,int cost=0) {
    chainhead[node] = curchainhead;
    chainno[node] = chainidx;
    hldarr[++arridx] = cost;
    posinhld[node] = arridx;
    int heavy_child = -1;
    int mxsize = 0;
    int c;
    for (ii u:tree[node]) {
        if (u.first == par) continue;
        if (subsize[u.first]>mxsize) {
            heavy_child = u.first;
            mxsize = subsize[u.first];
            c = u.second;
        }
    }
    if (heavy_child !=-1) {
        buildhld(heavy_child,node,c);
    }
    for (ii u:tree[node]) {
        if (u.first != par && u.first != heavy_child) {
            ++chainidx;
            curchainhead = u.first;
            buildhld(u.first,node,u.second);
        }
    }
}

int lca(int n1,int n2) {
    if (depth[n1] > depth[n2]) {
        swap(n1,n2);
    }
    int dif = depth[n2]-depth[n1];
    int curbit = 0;
    while(dif) {
        if (dif&1){
            n2 = parent[n2][curbit];
            curbit++;
        }
        dif>>=1;
    }
    if (n1 == n2) return n1;
    for (int i=LOGN-1; i>=0; i--) {
        if (parent[n1][i] != parent[n2][i]) {
            n1 = parent[n1][i];
            n2 = parent[n2][i];
        }
    }
    return parent[n1][0];
}

void buildsegment(int st,int ed,int idx) {
    if (st == ed) {
        segment[idx] = hldarr[st];
        return;
    }
    int mid = (st+ed)/2;
    buildsegment(st,mid,idx*2);
    buildsegment(mid+1,ed,idx*2+1);
    segment[idx] = max(segment[idx*2],segment[idx*2+1]);
}

int querysegment(int st,int ed,int idx,int qst,int qed) {
    if (qst > ed || qed < st) {
        return INT_MIN;
    }
    if (st >= qst && ed <= qed) return segment[idx];
    int mid = (st+ed)/2;
    return max(querysegment(st,mid,idx*2,qst,qed),querysegment(mid+1,ed,idx*2+1,qst,qed));
}

void updsegment(int st,int ed,int idx,int updidx,int val) {
    if (st == ed) {
        segment[idx] = val;
        return;
    }
    if (st > updidx || ed < updidx) return;
    int mid = (st+ed)/2;
    updsegment(st,mid,idx*2,updidx,val);
    updsegment(mid+1,ed,idx*2+1,updidx,val);
    segment[idx] = max(segment[idx*2],segment[idx*2+1]);
}


inline int getsum(int a,int b){
    return querysegment(1,arridx,1,a,b);
}

int queryup(int a,int b) {
    if (a==b) return INT_MIN;
    // Assuming b has more depth than a
    int achain = chainno[a];
    int bchain = chainno[b];
    int ans = INT_MIN;
    while(bchain!=achain) {
        ans = max(ans,getsum(posinhld[chainhead[b]],posinhld[b]));
        b = parent[chainhead[b]][0];
        bchain = chainno[b];
    }
    // cout<<posinhld[a]<<' '<<posinhld[b]<<'\n';
    ans = max(ans,getsum(posinhld[a]+1,posinhld[b]));
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        edges.clear();
        for (int i=1; i<=n; i++) {
            tree[i].clear();
        }
        loop(i,n-1) {
            int a,b,c;
            cin>>a>>b>>c;
            tree[a].pb({b,c});
            tree[b].pb(mp(a,c));
            edges.pb(mp(a,b));
        }
        arridx = 0,chainidx=curchainhead=1;
        dfs(1);
        for (int i=1; i<LOGN; i++) {
            for (int j=1; j<=n; j++) {
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
        buildhld(1);
        buildsegment(1,arridx,1);
        string s;
        int a,b;
        while(cin>>s) {
            // for (int i=1; i<=arridx; i++) cout<<querysegment(1,arridx,1,i,i)<<' ';cout<<endl;
            if (s == "DONE") break;
            if (s=="QUERY") {
                cin>>a>>b;
                int lc = lca(a,b);
                // cout<<lc<<' ';
                cout<<max(queryup(lc,a),queryup(lc,b))<<'\n';
            }
            else {
                cin>>a>>b;
                ii edge = edges[a-1];
                if (parent[edge.first][0] == edge.second) {
                    updsegment(1,arridx,1,posinhld[edge.first],b);
                }
                else {
                    // cout<<'a';
                    // cout<<posinhld[edge.second];
                    updsegment(1,arridx,1,posinhld[edge.second],b);
                }
            }
        }
        // cout<<arridx<<' '<<chainidx;

    }
    return 0;
}
