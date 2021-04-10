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
        cerr.write(names, comma - names) << " : " << arg1 <<" | "; __f(comma+1,args...);
    }
#else
#define trace(...)
#endif

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

int t,n;
vii inputs;
vi all_numbers;
vvll dp;

ll check(int p) {
    // return 0;
    // trace(p,t);
    int sum = 0;
    int tmp=p;
    for (int u=0; u<inputs.size(); u++) {
        ii par = inputs[u];
        // if (p==25) trace(inputs[u].first,inputs[u].second);
        while(p%par.first==0) {
            p/=par.first;
            par.second--;
        }
        while(par.second>0){
            sum += par.first;
            par.second--;
        }
    }
    // cerr<<'\n';
    // if (tmp==25) cerr<<sum<<'\n';
    if (sum==tmp) return tmp;
    return 0;
}

ll ans(int n,int p) {
    if (p>100000) return 0;
    if (n==0) {
        return check(p);
    }
    if (dp[n][p] != -1) return dp[n][p];
    return dp[n][p] = max(ans(n-1,p*all_numbers[n-1]),ans(n-1,p));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    int _t = t;
    while(t--) {
        ll as=0;
        cin>>n;
        inputs.clear();
        all_numbers.clear();
        loop(i,n) {
            int p,n;
            cin>>p>>n;
            inputs.pb({p,n});
            while(n>0) {
                all_numbers.pb(p);
                n--;
            }
        }
        // if ((_t-t)!=2) continue;
        // for (ii u:inputs) cout<<u.first<<" "<<u.second<<'\n';
        dp = vector<vll>(all_numbers.size()+1,vll(100001,-1));
        as = ans(all_numbers.size(),1);
        cout<<"Case #"<<_t-t<<": "<<as<<'\n';
    }
    return 0;
}
