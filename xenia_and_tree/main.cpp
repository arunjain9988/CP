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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};

const int N=100005;
const int LOGN=20;
vector<int> Tree[N];
int par[N];
int sz[N];
int dis[LOGN][N];
bool visited[N];
int levels[N];
int ans[N];

void dfs(int node,int par=-1) {
    /**
     * @brief for calculating size of subtrees including node
     * @param node = node of tree
     * @param par = parent of node
     */
    sz[node] = 1;
    for (int u:Tree[node]){
        if (u==par || visited[u]) continue;
        dfs(u,node);
        sz[node] += sz[u];
    }
}

int centroid(int node,int par,int mysz) {
    /**
     * @brief Find and returns centroid of tree
     * 
     * @param node: root of tree
     * @param par: parent of node
     * @param mysz: size of node
     */
    for (int u:Tree[node]) {
        if (u == par || visited[u]) continue;
        if (sz[u] > mysz/2) {return centroid(u,node,mysz);}
    }   
    return node;
}

void dfs2(int node,int pr,int lvl,int ds=0) {
    /**
     * @brief Fills distance of all nodes in subtree rooted at node in original tree.
     * @param node: root of tree
     * @param pr: parent of tree
     * @param lvl: level of root
     * @param ds: provide if distance of node to node is not zero.
     */
    dis[lvl][node] = ds;
    for (int u:Tree[node]) {
        if (u==pr || visited[u]) continue;
        dfs2(u,node,lvl,ds+1);
    }
}

void centroid_decomposition(int node,int pr=-1,int lvl=1){
    par[node] = pr;
    levels[node] = lvl;
    visited[node] = true;
    // dfs(node,pr);
    dfs(node,pr);
    dfs2(node,pr,lvl,0);
    for (int u:Tree[node]) {
        if (visited[u]) continue;
        int c = centroid(u,node,sz[u]);
        centroid_decomposition(c,node,lvl+1);
    }
}
    
int calc_dis(int a,int b) {
    if (a==b) return 0;
    if (levels[a] > levels[b]) {
        return (dis[levels[b]][a]);
    }
    else return (dis[levels[a]][b]);
}

void update(int node,int t) {
    if (par[node]==-1){
        ans[node] = min(ans[node],calc_dis(node,t));
        return;
    }
    ans[node] = min(ans[node],calc_dis(node,t));
    update(par[node],t);
}

int query(int node,int t) {
    if (par[node] == -1) return ans[node]+calc_dis(node,t);
    return min(ans[node]+calc_dis(node,t),query(par[node],t));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q;
    int a,b;
    cin>>n>>q;
    loop(i,n-1) {
        cin>>a>>b;
        Tree[a].pb(b);
        Tree[b].pb(a);
    }
    dfs(1,-1);
    int c = centroid(1,-1,sz[1]);
    centroid_decomposition(c,-1);
    fill(ans,ans+n+1,1<<20);
    update(1,1);
    loop(i,q) {
        cin>>a>>b;
        if (a==1){
            update(b,b);
        }
        else{
            cout<<query(b,b)<<'\n';
        }
    }
    return 0;
}
