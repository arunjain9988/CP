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

int h,w,n;
ll fact[200005];
ll inverse_fact[200005];

ll pw2(ll a,ll b,ll m) {
    ll ret = 1;
    while(b) {
        if (b&1) {
            ret = (ret*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return ret;
}

void pre() {
    fact[0] = 1;
    for (int i=1; i<=200000; i++) {
        fact[i] = (i*fact[i-1])%MOD;
    }
    inverse_fact[0]  = 1;
    inverse_fact[1] = pw2(1,MOD-2,MOD);
    for (int i=2; i<=200000; i++) {
        inverse_fact[i] = (inverse_fact[i-1]*pw2(i,MOD-2,MOD))%MOD;
    }
}

struct point{
    int r;
    int c;

    bool operator<(point& a) {
        if (r==a.r) return c<a.c;
        return r<a.r;
    }
};

vector<point> points;

ll choose(int n,int k) {   
    // trace3(n,k,1);
    if (k==0) return 1;
    if (n==0) return 0;
    if (n==k) return 1;
    return (((fact[n]*inverse_fact[k])%MOD)*inverse_fact[n-k])%MOD;
}

//              1       1       1       4
ll num_of_ways(int sr,int sc,int er,int ec) {
    if (er<sr || ec<sc) return 0;
    return choose(er-sr+ec-sc,er-sr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>h>>w>>n;
    pre();
    loop(i,n) {
        int a,b;
        cin>>a>>b;
        points.pb({a,b});
    }
    points.pb({h,w});
    sort(all(points));
    vll dp(n+1,0);
    loop(i,n+1) {
        dp[i] = num_of_ways(1,1,points[i].r,points[i].c);
        // trace3(points[i].r,points[i].c,dp[i]);
        for (int j=0; j<i; j++) {
            // trace5(points[j].r,points[j].c,points[i].r,points[i].c,num_of_ways(points[j].r,points[j].c,points[i].r,points[i].c));
            dp[i] = dp[i] - (dp[j]*num_of_ways(points[j].r,points[j].c,points[i].r,points[i].c))%MOD;
            dp[i] = (dp[i]+MOD)%MOD;
            // dp[i] -= 
        }
    }
    cout<<dp[n];
    return 0;
}
