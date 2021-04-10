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
#define MOD 998244353
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

vector<vector<int> > G;
bool can;
int cnt[2];
vector<int> color;
int pw2[300001];

void fillpw2() {
    pw2[0] = 1;
    floop(i,1,300000) {
        pw2[i] = (pw2[i-1]*2)%MOD;
    }
}

void dfs(int node,int col) {
    if (color[node]) {
        if (color[node] == col) return;
        else {
            can = false;
            return;
        }
    }
    color[node] = col;
    cnt[col-1]++;
    for (int u:G[node]) {
        dfs(u,3-col);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    fillpw2();
    int n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        G = vector<vector<int> >(n,vector<int>());
        loop(i,m) {
            int a,b;
            cin>>a>>b;
            a--,b--;
            G[a].pb(b);
            G[b].pb(a);
        }
        ll ans=1;
        color.resize(n);
        fill(all(color),0);
        loop(i,n) {
            if (!color[i]) {
                can = true;
                cnt[0] = 0;
                cnt[1] = 0;
                // fill(all(color),0);
                dfs(i,1);
                // trace3(cnt[0],cnt[1],can);
                if (!can) {
                    ans = 0;
                    break;
                }
                ans = (ans * (pw2[cnt[0]] + pw2[cnt[1]]))%MOD;
            }
        }   
        cout<<ans<<'\n';
    }
    return 0;
}
