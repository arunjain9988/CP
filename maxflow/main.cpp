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

class Maxflow{
    public:
    vector<vector<ll> > capacity;
    vector<vector<int> > adj;
    int n;
    Maxflow(int n) :n(n) {
        capacity = vector<vector<ll> > (n+1,vector<ll>(n+1,0));
        adj.resize(n+1);
    }

    void addEdge(int a,int b,ll flow,bool isadd=false) {
        if (isadd) capacity[a][b] += flow;
        else capacity[a][b] = flow;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll bfs(int src,int dest,vector<int> &parent) {
        fill(all(parent),-1);
        parent[src] = -2;
        queue<pair<int,ll> > q;
        q.push({src,(1ll)<<35});
        while(!q.empty()) {
            pair<int,ll> node = q.front();
            q.pop();
            if (node.first == dest) return node.second;
            for (int i:adj[node.first]) {
                if (parent[i] == -1 && capacity[node.first][i]>0) {
                    parent[i] = node.first;
                    q.push({i,min(node.second,capacity[node.first][i])});

                }
            }
        }
        return 0;
    }


    ll getMaxflow(int src,int dest) {
        vector<int> parent(n+1,-1);
        ll total_flow = 0;
        ll flow;
        while(flow = bfs(src,dest,parent)){
            // cout<<flow<<'\n';
            total_flow += flow;
            int cur = dest;
            while(cur != src) {
                // cout<<cur<<" <-- ";
                int prev = parent[cur];
                capacity[prev][cur] -= flow;
                capacity[cur][prev] += flow;
                cur = prev;
            }
            // cout<<src<<'\n';
        }
        return total_flow;
    }
};

void add_primes(int a,vector<int>& ls) {
    for (int i=2; i*i<=a && a>1; i++) {
        if (a%i==0) {
            ls.pb(i);
            while(a%i==0) a/=i;
        }
    }
    if (a>1) ls.pb(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    int a,b,c;
    cin>>n>>m;
    int A[n];
    vector<int> neccessary_primes;
    vector<ii> edges;
    loop(i,n) {
        cin>>A[i];
        add_primes(A[i],neccessary_primes);
    }
    sort(all(neccessary_primes));
    neccessary_primes.resize(distance(neccessary_primes.begin(),unique(all(neccessary_primes))));
    // cerr<<'w';
    loop(i,m) {
        cin>>a>>b;
        edges.pb({a,b});
    }
    ll ans = 0;
    for (int p:neccessary_primes) {
        // cerr<<p<<'\n';
        vector<vector<int> > assigned_vertices(n);
        int src = 1;
        int dest = 2;
        int nodecount = 2;
        for (int i=0; i<n; i++) {
            while (A[i]%p == 0){
                assigned_vertices[i].pb(++nodecount);
                A[i]/=p;
            }
        }
        // cerr<<nodecount<<' ';
        Maxflow mxfl(nodecount);
        loop(i,m) {
            a = edges[i].first;
            b = edges[i].second;
            // cerr<<a<<' '<<b<<'\n';
            if (b&1) swap(a,b);
            // assert(a&1);
            for (int u:assigned_vertices[a-1]) {
                for (int v:assigned_vertices[b-1]) {
                    // cerr<<u<<' '<<v<<'\n';
                    mxfl.addEdge(u,v,1,false);
                    // mxfl.addEdge(v,u,0,true);
                }
            }
            for(int u:assigned_vertices[a-1]) {
                mxfl.addEdge(src,u,1,false);
                // mxfl.addEdge(u,src,0,false);
            }
            for(int u:assigned_vertices[b-1]) {
                mxfl.addEdge(u,dest,1,false);
                // mxfl.addEdge(dest,u,0);
            }
        }
        ans += mxfl.getMaxflow(src,dest);
        // cout<<ans<<'\n';
    }
    cout<<ans;

    // loop(i,m) {
    //     cin>>a>>b>>c;
    //     mx.addEdge(a,b,c,true);
    // }
    // cout<<mx.getMaxflow(1,n);
    return 0;
}
