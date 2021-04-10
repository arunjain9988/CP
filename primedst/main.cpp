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

const int N=50005;
const int LOGN = 20;
list<int> Tree[N];
int level[N],sz[N],dis[LOGN][N],parent[N];
bool visited[N];
vector<int> centroid_tree[N];
vector<int> primes;

void preprimes(int n) {
    bool P[n+1];
    fill(P,P+n+1,true);
    for (int i=2; i*i<=n; i++) {
        if (P[i]) for (int j=i*i; j<=n; j+=i) P[j]=false; 
    }
    for (int i=2; i<=n; i++) if (P[i]) primes.pb(i);
}


void szdfs(int node,int par=-1) {
    sz[node] = 1;
    for (int u:Tree[node]) {
        if (u==par || visited[u]) continue;
        szdfs(u,node);
        sz[node] += sz[u];
    }
}

int get_centroid(int node,int par,int mysz) {
    for (int u:Tree[node]) {
        if (u==par || visited[u]) continue;
        if (sz[u]>mysz/2) return get_centroid(u,node,mysz);
    }
    return node;
}

void calc_dis(int node,int par,int lvl,int ds=0) {
    dis[lvl][node] = ds;
    for (int i:Tree[node]) {
        if (i==par || visited[i]) continue;
        calc_dis(i,node,lvl,ds+1);
    }
}

int centroid_decomposition(int node,int par=-1,int lvl=1) {
    szdfs(node);
    // for (int i=1;i<=5; i++) cout<<sz[i]<<'\n';
    int mysz=sz[node];
    int centroid = get_centroid(node,par,mysz);
    calc_dis(centroid,-1,lvl);
    // cout<<mysz<<' '<<centroid<<'\n';
    level[centroid] = lvl;
    visited[centroid] = true;
    parent[centroid] = par;
    // if (par!=-1) Tree[par].pb(centroid);
    // vector<list<int>::iterator> vv;
    tr(Tree[centroid],it) {
        if (*it==par || visited[*it]) continue;
        centroid_decomposition(*it,centroid,lvl+1);
        // vv.pb(it);
    }
    // for (auto t:vv) Tree[node].erase(t);
    return centroid;
}

unordered_map<int,int> um;

int get_dis(int n1,int n2) {
    if (n1==n2) return 0;
    if (level[n1]>level[n2]) return dis[level[n2]][n1];
    else return dis[level[n1]][n2];
}

void update(int node,int pr,int t) {
    um[get_dis(node,t)]++;
    for (int u:centroid_tree[node]) {
        if (u==pr || visited[u]) continue;
        update(u,node,t);
    }
}

void ansdfs(int node,int par=-1) {
    visited[node] = true;
    if (centroid_tree[node].size()==1) return;
    um.clear();
    int i=0;
    for(; i<centroid_tree[node].size(); i++) {
        if (centroid_tree[node][i]!=par && (!visited[i])) {
            update(i,node,node);
            um[0]++;
            i++;
            break;
        }
    }
    while(i<centroid_tree[node].size()) {
        if (centroid_tree[node][i]!=par && (!visited[i])) {
            
            update(i,node,node);
            um[0]++;
            i++;
            break;
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
    int n;
    cin>>n;
    preprimes(n);
    loop(i,n-1) {
        int a,b;
        cin>>a>>b;
        Tree[a].pb(b);
        Tree[b].pb(a);
    }
    int root = centroid_decomposition(1);
    for (int i=1; i<=n; i++) {
        if (parent[i]!=-1) {
            centroid_tree[i].pb(parent[i]);
            centroid_tree[parent[i]].pb(i);
        }
    }
    fill(visited,visited+n+1,false);
    ansdfs(root);
    // for (int i=1; i<=n; i++) {
    //     cout<<parent[i]<<' ';
    // }
    return 0;
}
