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


template<class T>
class Graph{
    public:
    int V;
    map<T,vector<T> > G;
    Graph(int n) : V(n) {}
    void addEdge(T x,T y) {
        G[x].pb(y);
        G[y].pb(x);
    }
    void bfsprint(T src) {
        unordered_map<T,bool> visited;
        queue<T> q;
        visited[src] = true;
        q.push(src);
        while(!q.empty()) {
            T f = q.front();
            q.pop();
            cout<<f<<' ';
            for (T a:G[f]) {
                if (!visited[a]) {
                    q.push(a);
                    visited[a] = true;
                } 
            }
        }
    }

    int shortestCycle() {
        int ans = V+1;
        for (int i='a'; i<'e'; i++) {
            unordered_map<T,int> dis;
            dis[i] = 0;
            queue<T> q;
            q.push(i);
            while (!q.empty())
            {
                T f = q.front();
                q.pop();
                for (T u:G[f]) {
                    if (dis.find(u) == dis.end()) {
                        dis[u] =  dis[f]+1;
                        q.push(u);
                    }
                    else if (dis[u] >= dis[f]) {
                        ans = min(ans,dis[u]+dis[f]+1);
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    Graph<char> gr(5);
    gr.addEdge('a','b');
    gr.addEdge('b','c');
    gr.addEdge('c','d');
    gr.addEdge('d','a');
    // gr.addEdge(1,3);
    // gr.bfsprint(1);
    // shortest cycle in the graph
    cout<<gr.shortestCycle();

    return 0;
}
