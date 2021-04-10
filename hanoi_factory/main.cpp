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

const int N = 200005;
ll bit[N+1];

void update(int idx,ll val) {
    while(idx<=N) {
        bit[idx] = max(bit[idx],val);
        idx += (idx&-idx);
    }
}

ll query(int idx) {
    ll ret = 0;
    while(idx>=1) {
        ret = max(ret,bit[idx]);
        idx -= (idx&-idx);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    set<int> radiuses;
    int a,b,h;
    vector<pair<int,ii> > inputs;
    loop(i,n) {
        cin>>a>>b>>h;
        inputs.pb(mp(h,mp(a,b)));
        radiuses.insert(a);
        radiuses.insert(b);
    }
    unordered_map<int,int> compress;
    int cur = 0;
    for (int u:radiuses) {
        compress[u] = ++cur;
        // cout<<u<<' ';
    }
    sort(all(inputs),[](pair<int,ii>& a,pair<int,ii>& b) {
        if (a.second.second == b.second.second) 
        return a.second.first>b.second.first;
        return a.second.second>b.second.second;
    });
    ll ans = 0;
    loop(i,n) {
        ll mx = query(compress[inputs[i].second.second]-1);
        // trace2(compress[inputs[i].second.second],compress[inputs[i].second.first]);
        ans = max(ans,mx+inputs[i].first);
        // if(mx+inputs[i].first > query(compress[inputs[i].second.first]))
        // for (int i=1; i<=30; i++) cout<<i<<' '<<bit[i]<<'\n';cout<<'\n'<<mx<<'\n'<<compress[inputs[i].second.first]<<'\n';
        update(compress[inputs[i].second.first],mx+inputs[i].first);
    }
    cout<<ans;
    return 0;
}
