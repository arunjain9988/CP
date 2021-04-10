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

ll bfs(vector<vector<ll> > &adjMatrix,int src,int dest,int* parent) {
    queue<pair<int,ll> > q;
    int n = adjMatrix.size();
    int* visited = new int[n];
    fill(visited,visited+n,false);
    visited[src] = true;
    q.push({src,(1ll)<<50});
    while(!q.empty()) {
        pair<int,ll> node=q.front();
        // cout<<node.first<<' '<<node.second<<'\n';
        if (node.first == dest) return node.second;
        q.pop();
        for (int i=0; i<adjMatrix.size(); i++) {
            if (!visited[i] && adjMatrix[node.first][i] > 0) {
                visited[i] = true;
                parent[i] = node.first;
                q.push({i,min(node.second,adjMatrix[node.first][i])});
            }
        }
    }
    // cerr<<endl;
    return 0;
}

ll maxFlow(vector<vector<ll> > &adjMatrix,int src,int dest) {
    int n= adjMatrix.size();
    int* parent = new int[adjMatrix.size()];
    ll total_flow = 0,flow;
    fill(parent,parent+adjMatrix.size(),-1);
    while(flow = bfs(adjMatrix,src,dest,parent)) {
    //     cout<<flow<<endl;
    // cout<<endl<<endl;
    //     loop(i,n) cout<<parent[i]<<' ';
        total_flow+=flow;
        int cur = dest;
        int prev = parent[dest];
        while(cur!=src) {
            // cout<<cur<<" <-- ";
            adjMatrix[prev][cur] -= flow;
            adjMatrix[cur][prev] += flow;
            prev = parent[prev];
            cur = parent[cur];
        }
        // cout<<cur<<'\n'<<flow<<'\n';
    }
    return total_flow;
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
    int a,b,c;
    vector<vector<ll> > adjMatrix(n,vector<ll>(n,0));
    loop(i,m) {
        cin>>a>>b>>c;
        a--,b--;
        adjMatrix[a][b] += c;
    }
    // loop(i,n) {
    //     loop(j,n) cout<<adjMatrix[i][j]<<' '; cout<<endl;
    // }
    cout<<maxFlow(adjMatrix,0,n-1);
    return 0;
}
