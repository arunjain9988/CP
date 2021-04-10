#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
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
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

// useful constants
#define MOD 1000000007

using namespace std;


// Important header files   ordered set
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less

using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;
    ordered_set oss;
    while(t--) {
        cin>>n;
        int A[n+1];
        vector<ii> qq;
        oss.clear();
        floop(i,1,n) {
            cin>>A[i];
            qq.pb(mp(A[i],i));
        }
        sort(all(qq));
        int idx = 0;
        while(idx<qq.size()) {
            int already_removed = oss.order_of_key(qq[idx].second);
            int cur_remove_size =    qq[idx].second - already_removed;
            int to_remove = ((qq[idx].first/cur_remove_size) + 1)*cur_remove_size;
            while(idx<qq.size() && qq[idx].first-to_remove < 0) {
                oss.insert(qq[idx].second);
                idx++;
            }
            if (idx == qq.size()-1) {
                break;
            }
        }
        if (idx == qq.size()-1) {
            cout<<"Ladia\n";
        }
        else cout<<"Kushagra\n";
    }
    return 0;
}
