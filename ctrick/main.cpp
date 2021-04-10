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

int bit[(1<<15)+1]; // as 1<<15 > 20000

void update(int idx) {
    while(idx<=(1<<15)) {
        bit[idx] -=1;
        idx += (idx&-idx);
    } 
}

int query(int idx) {
    int sum = 0;
    while(idx>=1) {
        sum+=bit[idx];
        idx -= (idx&-idx);
    }
    return sum;
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
    while(t--) {
        cin>>n;
        if (n==1){
            cout<<"1\n";
            continue;
        }
        floop(i,1,1<<15) {
            bit[i] = (i&-i);
        }
        // for (int i=1; i<=16; i++) cout<<bit[i]<<' '; cout<<endl;
        int ans[n+1];
        ans[2] = 1;
        int curdis = 2;
        int curidx = 2;
        update(2);
        int toput = 2;
        while(toput<=n) {
            int tillherefree = query(curidx);
            int tofind = tillherefree+curdis+1;
            tofind = ((tofind-1)%(n-toput+1))+1;
            // trace1(tofind);
            // bs on bit
            int mid = 1<<15;
        // for (int i=1; i<=16; i++) cout<<bit[i]<<' '; cout<<endl;
            int aa = -1;
            while(true) {
                // if (query(mid)==tofind) {
                //     aa = mid;
                // }
                if (mid&1) {
                    if (bit[mid] >= tofind) {
                        aa = mid;
                    }
                    break;
                }
                if (bit[mid]>=tofind) {
                    aa = mid;
                    mid -= ((mid&-mid)>>1);
                }
                else {
                    tofind -= bit[mid];
                    mid += ((mid&-mid)>>1);
                }

            }
            // trace1(aa);
            update(aa);
            curidx = aa;
            ans[curidx] = toput;
            toput++;
            curdis ++;
        }
        floop(i,1,n) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}

