#include <bits/stdc++.h>  // This will work only for g++ compiler.

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

int t;
int n;
ll l,r;
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
	vi primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    while(t--) {
        cin>>n>>l>>r;
        ans=0;
		int lb=0;
		int rb = upper_bound(primes.begin(),primes.end(),n) - primes.begin();
        rb--;
        floop(i,l,r) {
            floop(j,0,rb) {
                if (l%primes[j]){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
