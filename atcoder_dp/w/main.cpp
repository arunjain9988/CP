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

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1) {
        cerr<<name<<" : " <<arg1<<std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1 <<" | ";
        __f(comma+1,args...);
    }
#else
#define trace(...)
#endif

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

struct segment{
    int l;
    int r;
    int cost;
};

const int N = 200005;
int n,m;

ll ST[4*N];
ll lazy[4*N];
vll dp;
vector<vector<segment> > segs;

void upd(int st,int ed,int idx,int updst,int upded,ll val) {
    if (lazy[idx]) {
        ST[idx] = ST[idx] + lazy[idx];
        if (st!=ed) {
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (st>upded || ed<updst) {
        return;
    }
    if (st>=updst && ed<=upded) {
        ST[idx] += val;
        if (st!=ed) {
            lazy[idx*2] +=val;
            lazy[idx*2+1] += val;
        }
        return;
    }
    int mid = (st+ed)/2;
    upd(st,mid,idx*2,updst,upded,val);
    upd(mid+1,ed,idx*2+1,updst,upded,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

ll query(int st,int ed,int idx,int qst,int qed) {
    if (lazy[idx]) {
        ST[idx] = ST[idx] + lazy[idx];
        if (st!=ed) {
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (st>qed || ed<qst) {
        return -(1ll<<60);
    }
    if (st>=qst && ed<=qed) {
        return ST[idx];
    }
    int mid = (st+ed)/2;
    ll a = query(st,mid,idx*2,qst,qed);
    ll b = query(mid+1,ed,idx*2+1,qst,qed);
    // trace(st,ed,idx,qst,qed,a,b);
    return max(a,b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    segs.resize(n+1);
    loop(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        if (c==0) continue;
        segs[b].pb({a,b,c});
    }
    // dp.resize(n+1);
    for (int i=1; i<=n; i++) {
        ll mx = max(0ll,query(1,n,1,1,i-1));
        // trace(mx);
        upd(1,n,1,i,i,mx);
        for (auto p:segs[i]) {
            upd(1,n,1,p.l,p.r,p.cost);
        }
    }
    cout<<max(query(1,n,1,1,n),0ll);
    return 0;
}
