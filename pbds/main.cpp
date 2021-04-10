#include <bits/stdc++.h>  // This will work only for g++ compiler. 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

using namespace __gnu_pbds;
using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

typedef tree<pair<int, int>,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    ordered_set os;
    int n;
    cin>>n;
    int* A = new int[n];
    int* B = new int[n];
    for (int i=0; i<n; i++) {
        cin>>A[i];
    }
    loop(i,0,n) {
        cin>>B[i];
    }
    unsigned_int idx = 0;
    ll sum = 0;
    rloop(i,n-1,0) {
        sum += os.order_of_key(make_pair(A[i]-B[i],0));
        os.insert(make_pair(B[i]-A[i],idx++));
    }
    cout<<sum;
    return 0;
}