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

map<int,int> bit[100005];

void add(int idx,int val,int n) {
    while(idx<=n) {
        bit[idx][val]++;
        idx += (idx&-idx);
    }
}



void rmv(int idx,int val,int n) {
    // while(bit[idx].find(val) == bit[idx].end()) {
    //     idx -= 
    // }
    while(idx<=n) {
         bit[idx][val]--;
        idx += (idx&-idx);
    }
}

int query(int idx,int val) {
    int cnt = 0;
    while(idx>=1) {
        cnt += (bit[idx][val]);
        idx -= (idx&-idx);
    }
    return cnt;
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
    int a,t,x;
    pair<int,ii> queries[n];
    set<int> times;
    loop(i,n) {
        cin>>a>>t>>x;
        times.insert(t);
        queries[i] = mp(a,mp(t,x));
    }
    // sort(all(times));
    map<int,int> compress;
    int cur=0;
    for(int u:times) {
        compress[u] = ++cur;
    }
    for (int i=0; i<n; i++) {
        if (queries[i].first == 1) {
            add(compress[queries[i].second.first],queries[i].second.second,cur);
        }
        else if (queries[i].first == 2) {
            rmv(compress[queries[i].second.first],queries[i].second.second,cur);
        }
        else  {
            cout<<query(compress[queries[i].second.first],queries[i].second.second)<<'\n';
        }
    }
    return 0;
}
