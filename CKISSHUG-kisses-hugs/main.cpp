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

int MOD = 1000000007;

ll power(ll base,ll exp) {
    ll ans=1;
    while(exp>0) {
        if (exp&1) {
            ans= (ans*base)%MOD;
        }
        base=(base*base)%MOD;
        exp/=2;
    }
    return ans%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t,n;
    ll ans;
    cin>>t;
    while(t--) {
        cin>>n;
        ans = 2*(power(2,n/2+1)-1);
        if (!(n&1)) {
            ans-=power(2,n/2);
        }
        cout<<ans%MOD<<'\n';
    }
    return 0;
}
