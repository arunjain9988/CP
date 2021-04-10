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

int bit[1025][1025];

void update(int x,int y,int val,int n) {
    for (int i=x; i<=n; i += (i&-i)) {
        for (int j=y; j<=n; j += (j&-j)) {
            bit[i][j] += val;
        }
    }
}

int sum(int x,int y) {
    int ret = 0;
    for (int i=x; i>=1; i-=(i&-i)) {
        for (int j=y; j>=1; j-=(j&-j)) {
            ret += (bit[i][j]);
        }
    }
    return ret;
}

int query(int x0,int y0,int x,int y) {
    return sum(x,y) - sum(x0-1,y) - sum(x,y0-1) + sum(x0-1,y0-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;
    string qq;
    int x0,y0,x,y,val;
    while(t--) {
        cin>>n;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                bit[i][j] = 0;
            }
        }
        // cin>>qq;
        while(cin>>qq) {
            if (qq == "SET") {
                cin>>x>>y>>val;
                // trace3(x,y,val);
                int dif = val-query(x+1,y+1,x+1,y+1);
                update(x+1,y+1,dif,n);
            }
            else if (qq == "SUM") {
                cin>>x0>>y0>>x>>y;
                cout<<query(x0+1,y0+1,x+1,y+1)<<'\n';
            }
            else break;
        }
    }
    return 0;
}
