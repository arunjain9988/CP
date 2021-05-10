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

ll t,n;
vector<ll> inputs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    ll k;
    ll _t = t;
    while(t--) {
        cin>>n>>k;
        inputs.clear();
        loop(i,n) 
        {
            ll a;
            cin>>a;
            inputs.pb(a);
        }
        sort(all(inputs));
        ll ans = 0;
        for (ll i=0; i<inputs.size()-1; i++) {
            for (ll j=i; j<inputs.size()-1; j++) {
                // let i and j are selecting polls
                if (i==j) {
                    ans = max(ans,inputs[i+1]-inputs[i]-1);
                }
                else {
                    ll a = (inputs[i+1]-inputs[i])/2;
                    ll b= (inputs[j+1]-inputs[j])/2;
                    ans = max(ans,a+b);
                }
            }
            ll a = (inputs[0]-1);
            ll b = (k-inputs[n-1]);
            ll c = (inputs[i+1]-inputs[i])/2;
            ans = max(ans,max(a+c,b+c));
        }
        ll a = (inputs[0]-1);
        ll b = (k-inputs[n-1]);
        ans = max(ans,a+b);
        cout<<"Case #"<<_t-t<<": "<<(double)ans/k<<'\n';
    }
    return 0;
}
