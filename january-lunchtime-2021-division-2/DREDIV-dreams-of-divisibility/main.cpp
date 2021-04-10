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

ll A[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    ll t,n;
    ll k,tmp;
    cin>>t;
    //
    while(t--) {
        cin>>n>>k;
        bool done = true;
        loop(i,0,n) {
            cin>>A[i];
            ll md = A[i]%k;
            if ((md ==0)) {
                continue;
            }
            if (k-md < md) {
                if (((k%(k-md)) == 0) && (__builtin_popcountll(k/(k-md)) == 1)) {
                    continue;
                }
                else done = false;
            }
            else {
                if (((k%(md)) == 0) && (__builtin_popcountll(k/md) == 1)) {
                    continue;
                }
                else done = false;
            }
            // else done = false;
        }
        if (done) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
