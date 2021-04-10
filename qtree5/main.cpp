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

const int N = 100005;
const int LOGN = 20;
vector<int> Tree[N];
bool visited[N];
int sz[N];
int par[N];
int dis[LOGN][N];
int levels[N];
multiset<int> ans[N];
int color[N];
void update_helper(int,int,int);

void sizedfs(int node,int par=-1) {
    sz[node] = 1;
    for (int u:Tree[node]) {
        if (u==par || visited[u]) continue;
        sizedfs(u,node);
        sz[node] += sz[u];
    }
}

int find_centroid(int node,int par,int ssz) {
    for (int u:Tree[node]) {
        if (u==par || visited[u]) continue;
        if (sz[u] > ssz/2) return find_centroid(u,node,ssz);
    }
    return node;
}

void calc_dis(int node,int par,int lvl,int ds=0) {
    dis[lvl][node] = ds;
    for (int u:Tree[node]) {
        if (u==par || visited[u]) continue;
        calc_dis(u,node,lvl,ds+1);
    }
}

int distance(int n1,int n2) {
    if (n1==n2) return 0;
    if (levels[n1]>levels[n2]) return dis[levels[n2]][n1];
    else return dis[levels[n1]][n2];
}

void centroid_decomposition(int node,int pr,int lvl=1) {
    // cout<<node<<'\n';
    sizedfs(node);
    int ssz = sz[node];
    int centroid =find_centroid(node,-1,ssz);
    levels[centroid] = lvl;
    par[centroid] = pr;
    calc_dis(centroid,-1,lvl);
    visited[centroid] = true;
    for (int u:Tree[centroid]) {
        if (visited[u]) continue;
        centroid_decomposition(u,centroid,lvl+1);
    }
}

void update(int t) {
    if (color[t]) update_helper(t,t,0);
    else update_helper(t,t,1);
    color[t] = 1^color[t];
}

void update_helper(int node,int t,int uord) {
    if (node == -1) return;
    if (uord) ans[node].insert(distance(node,t));
    else ans[node].erase(ans[node].find(distance(node,t)));
    update_helper(par[node],t,uord);
}

int query(int node,int t) {
    if (node == -1) return 1<<30;
    if (ans[node].begin() != ans[node].end()) return min(*ans[node].begin()+distance(node,t),query(par[node],t));
    else return query(par[node],t);
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
    loop(i,n-1) {
        int a,b;
        cin>>a>>b;
        Tree[a].pb(b);
        Tree[b].pb(a);
    }
    int q;
    centroid_decomposition(1,-1);
    // for (int i=1; i<=n; i++) cout<<par[i]<<' ';
    cin>>q;
    while(q--)  {
        int type,node;
        cin>>type>>node;
        if (type == 0) {
            update(node);
        }
        else {
            int ans = query(node,node);
            if (ans == 1<<30) cout<<-1<<'\n';
            else cout<<ans<<'\n';
        }
    }
    return 0;
}
