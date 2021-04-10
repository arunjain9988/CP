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

void timefilldfs(vector<int> G[],int node,int par,int tin[],int tout[],int &timer) {
    tin[node] = timer++;
    for (int u:G[node]) {
        timefilldfs(G,u,node,tin,tout,timer);
    }
    tout[node] = timer;
}

void fillparent(vector<int> G[],int node,int parent,int par[]) {
    par[node] = parent;
    for (int u:G[node]) {
        if (u==parent) continue;
        fillparent(G,u,node,par);
    }
}

struct sparse_table{
    int n,m;
    vector<vector<int> > table;
    sparse_table(int n,int logn) : n(n),m(logn) {
        table = vector<vector<int> >(n+1,vector<int>(m+1,0));
    }
    void fill_for_lca(int parent[]) {
        for(int i=1; i<=n; i++){
            table[i][0] = parent[i];
        }
        table[0][0] = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                table[j][i] = table[table[j][i-1]][i-1];
            }
        }
    }

    void printTable() {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                cout<<table[i][j]<<' ';
            }
            cout<<'\n';
        }
    }

    int getlca(int a,int b) {
        if (a==b) return 0;
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m,a,b;
    cin>>n>>m;
    vector<int> G[n+1];
    loop(i,m) {
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int par[n+1];
    fill(par,par+n,-1);
    fillparent(G,1,1,par);
    // floop(i,1,n) cout<<par[i]<<' ';
    sparse_table t(n,3);
    t.fill_for_lca(par);
    t.printTable();
    return 0;
}
