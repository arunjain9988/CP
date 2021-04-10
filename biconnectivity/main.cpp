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
int cur_time=0;
const int N = 1000;
vector<int> G[N];

int visit_time[N];
int lw[N];
vector<ii> bridges;
vector<int> bridge_less_tree[N];
int comp_no[N];
bool visited[N];
vector<vector<int> > bridge_tree;
bool art_vertex[N];

void art_dfs(int node,int par=0) {
    visit_time[node] = ++cur_time;
    lw[node] = cur_time;
    int nd2 = false;
    for (int u:G[node]) {
        if (visit_time[u] == 0) {
            art_dfs(u,node);
            if (par == 0 and nd2) art_vertex[1] = true;
            else if (par==0) nd2=true; 
        }
        if (u!=par)  {
            lw[node] = min(lw[node],lw[u]);
        }
        if (par!=0 && u!= par && lw[u]>=visit_time[node]) {
            art_vertex[node] = true;
        }
    }
}

//bridges add
void dfs(int node,int par=0) {
    visit_time[node] = ++cur_time;
    lw[node] = cur_time;
    for (int u:G[node]) {
        if (u==par) continue;
        if (visit_time[u] == 0) {
            dfs(u,node);
        }
        lw[node] = min(lw[node],lw[u]);
    }
    if (par != 0 && lw[node] >= visit_time[node]) {
        bridges.pb({par,node});
    }
    else if (par!=0) {
        bridge_less_tree[node].pb(par);
        bridge_less_tree[par].pb(node);
    }
}

void comp_dfs(int node,int comp) {
    comp_no[node] = comp;
    visited[node] = true;
    for (int u:bridge_less_tree[node]) {
        if (!visited[u]) {
            comp_dfs(u,comp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    loop(i,m) {
        int a,b;
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1);
    // for(int i=1;i<=n;i++) {
    //     cout<<visit_time[i]<<' '<<lw[i]<<'\n';
    // }
    //Finding bridges
    // cout<<endl;
    // for (auto u:bridges) {
    //     cout<<u.first<<' '<<u.second<<'\n';
    // }
    int comp = 0;
    fill(visited,visited+n,false);
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            comp_dfs(i,++comp);
        }
    }
    // comp = no of vertices in bridge tree
    // bridge_tree.resize(comp);
    bridge_tree = vector<vector<int> > (comp+1,vector<int>());
    for (ii u:bridges) {
        bridge_tree[comp_no[u.first]].pb(comp_no[u.second]);
        bridge_tree[comp_no[u.second]].pb(comp_no[u.first]);
    }
    for (int i=1; i<=comp; i++) {
        for (int u:bridge_tree[i]) {
            cout<<u<<' '<<i<<'\n';
        }
    }
    cout<<endl;
    for (int i=1; i<=comp; i++) {
        cout<<"comp "<<i<<"--> ";
        for (int j=1; j<=n; j++) {
            if (comp_no[j] == i) cout<<j<<' ';
        }
        cout<<endl;
    }

    // finding articulation points in graph G
    fill(art_vertex,art_vertex+n+1,false);
    cur_time=0;
    fill(visit_time,visit_time+n+1,0);
    art_dfs(1);
    // if (G[1].size()>1) art_vertex[1] = true; else art_vertex[1] = false;
    for (int i=1; i<=n; i++) {
        cout<<art_vertex[i]<<' ';
    }
    return 0;
}
