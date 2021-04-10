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

// typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int bit[1000001];

void update(int idx) {
    while(idx<=1000000) {
        bit[idx] ++;
        idx += (idx&-idx);
    }
}

int query(int idx) {
    int ret = 0;
    while(idx>=1) {
        ret += (bit[idx]);
        idx -=(idx&-idx);
    }
    return ret;
}

int A[1000001];
ll ans[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    // cin>>t;
    int n,x;
    t = 1;
    while(t--){
        int n;
        cin>>n>>x;
        vector<int> permute;
        permute.reserve(n);
        loop(i,n) {
            cin>>A[i];
            permute.pb(i);
        }
        sort(all(permute),[](const int& a,const int& b){return A[a]<A[b];});
        unordered_map<int,int> compress;
        loop(i,permute.size()) {
            compress[A[permute[i]]] = i+1;
        }
        // ll ans = (ll)n*x;
        rloop(i,n-1,0){
            int lss = query(permute[i]+1);
            // trace2(query(permute.size()),query(compress[A[i]]));
            update(permute[i]+1);
            ans[i] = lss;
        }
        ll aa = ((ll)n*x);
        ll cur = 0;
        // floop(i,0,n-1) cout<<ans[i]<<' ';
        rloop(i,n-1,0) {
            cur += ans[i];
            aa = min(aa,cur+((ll)i*x));
        } 
        // aa = min(aa,cur);
        cout<<aa;
    }
    return 0;
}
