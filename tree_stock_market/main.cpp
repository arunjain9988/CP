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

const int N = 100005;
const int LOGN = 15;
const int B=500;
int val[N];
vector<int> tree[N];
int stime[N];
int etime[N];
int curtime = 0;
int tour[N];
int freq[N];
int base[N];

void dfs(int node,int par=1) {
    stime[node] = ++curtime;
    tour[curtime] = val[node];
    for (int u:tree[node]) {
        if (u==par) continue;
        dfs(u,node);
    }
    etime[node] = curtime;
}

struct qr{
    int st,ed,l,r,idx;
    qr(int st,int ed,int l,int r,int idx) : st(st),ed(ed),l(l),r(r),idx(idx) {

    }
};

vector<qr> queries;

void add(int idx) {
    base[freq[tour[idx]]]--;
    freq[tour[idx]]++;
    base[freq[tour[idx]]]++;
}

void rmv(int idx) {
    base[freq[tour[idx]]]--;
    freq[tour[idx]]--;
    base[freq[tour[idx]]]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    loop(i,n-1) {
        int a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    floop(i,1,n) {
        cin>>val[i];
    }
    dfs(1);
    loop(i,q) {
        int u,l,r;
        cin>>u>>l>>r;
        queries.pb({stime[u],etime[u],l,r,i});
    }
    sort(all(queries),[](qr& a,qr& b) {
        if (a.st/B == b.st/B) return a.ed<b.ed;
        return a.st<b.st; 
    });
    int s=1,e=0;
    for (auto u:queries) {
        // cout<<u.st<<' '<<u.ed<<' '<<u.l<<' '<<u.r<<' '<<u.idx<<'\n';
        while(e<u.ed) add(++e);
        while(s<u.st) rmv(s++);
        while(s>u.st) add(--s);
        while(e>u.ed) rmv(e--);
        int ans = 0;
        for (int i=u.l; i<=u.r; i++) {
            ans += base[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
