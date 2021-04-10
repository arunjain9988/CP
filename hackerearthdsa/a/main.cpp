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

// useful constants
#define MOD 1000000007
#define EPS (double)1e-6

using namespace std;


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1) {
        cerr<<name<<" : " <<arg1<<std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* comma = strchr(names + 1, ','); 
        cerr.write(names, comma - names) << " : " << arg1 <<" | "; __f(comma+1,args...);
    }
#else
#define trace(...)
#endif

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

int n,q;
vvi tree;
const int LOGN = 20;
vvi parent;
vvi mx;
vi costs;
vi par;
vi depth;

void pre() {
    for (int i=1;i<=n; i++) {
        parent[i][0] = par[i];
    }
    for (int j=1; j<LOGN; j++) {
        for (int i=1; i<=n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    for (int i=1;i<=n; i++) {
        mx[i][0] = costs[i];
    }
    for (int j=1; j<LOGN; j++) {
        for (int i=1; i<=n; i++) {
            // parent[i][j] = parent[parent[i][j-1]][j-1];
            mx[i][j] = max(mx[i][j-1],mx[parent[i][j-1]][j-1]);
        }
    }
    // for (int i=1; i<=n; i++) {
    //     for (int j=0; j<LOGN; j++) {
    //         cout<<mx[i][j]<<' '; 
    //     }
    //     cout<<'\n';
    // }
}

void dfs(int node,int p,int d = 1) {
    depth[node] = d;
    par[node] = p;
    for (int u:tree[node]) {
        if (u==p) continue;
        dfs(u,node,d+1);
    }
}

int get_parent(int a,int b) {
    if (depth[b]>depth[a]) swap(a,b);
    int maaa = 0;
    if (depth[a]>depth[b]) {
        int dif = depth[a]-depth[b]+1;
        int cur = 0;
        while(dif) {
            // trace(dif,maaa,cur,a,q,mx[a][cur]);
            if (dif&1) {
                maaa = max(maaa,mx[a][cur]);
                a = parent[a][cur];
            }
            cur++;
            dif>>=1;
        }
    }
    if (a==b) return maaa;
    for (int i=19; i>=0; i--) {
        if (parent[a][i] != parent[b][i]) {
            maaa = max(max(maaa,mx[a][i]),mx[b][i]);
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return max(maaa,parent[a][0]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>q;
    tree.resize(n+1);
    costs.pb(0);
    loop(i,n) {
        int a;
        cin>>a;
        costs.pb(a);
    }
    loop(i,n-1) {
        int a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    par.resize(n+1);
    parent = vector<vi>(n+1,vi(LOGN,0));
    mx = vector<vi>(n+1,vi(LOGN,0));
    depth.resize(n+1);
    dfs(1,1);
    pre();
    while(q--) {
        int a,b;
        cin>>a>>b;
        int paaa = get_parent(a,b);
        cout<<paaa<<'\n';
    }
    return 0;
}
