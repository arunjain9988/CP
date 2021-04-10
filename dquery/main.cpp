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

int prv[1000005];
int A[30005];
int ans[200005];
int bit[1000005];

void update(int idx,int val) {
    while(idx<=1000000) {
        bit[idx] += val;
        idx += (idx&-idx);
    }
}

int query(int idx) {
    int ret = 0;
    while(idx>=1) {
        ret += bit[idx];
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
    int n,q;
    cin>>n;
    loop(i,n) cin>>A[i+1];
    memset(prv,-1,sizeof(prv));
    vector<pair<int,ii> > queries;
    cin>>q;
    int a,b,c;
    loop(i,q) {
        cin>>a>>b;
        queries.pb(mp(i,mp(a,b)));
    }
    sort(all(queries),[](const pair<int,ii>& a,const pair<int,ii>& b){
        return a.second.second<b.second.second;
    });
    int cur = 0;
    loop(i,queries.size()) {
        while(queries[i].second.second > cur){
            ++cur;
            if (prv[A[cur]] != -1){
                update(prv[A[cur]],-1);
            }
            update(cur,1);
            prv[A[cur]] = cur;
        }
        ans[queries[i].first] = query(queries[i].second.second) - query(queries[i].second.first-1);
    }
    floop(i,0,q-1) cout<<ans[i]<<'\n';
    return 0;
}
