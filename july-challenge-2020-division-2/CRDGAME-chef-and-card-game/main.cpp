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

pair<ll,ll> solve(ll a,ll b) {
    ll powa=0;
    ll powb=0;
    while(a>0) {
        powa += a%10;
        a/=10;
    }
    while(b>0) {
        powb += b%10;
        b/=10;
    }
    if (powa>powb) return {1,0};
    else  if (powa<powb) return {0,1};
    else return {1,1};
}

ll t;
ll n;
ll tmp1,tmp2;
ll poa,pob;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n;
        poa=0;
        pob=0;
        loop(i,0,n) {
            cin>>tmp1>>tmp2;
            pair<ll,ll> t = solve(tmp1,tmp2);
            poa+= t.first;
            pob+= t.second;
        }
        if (poa>pob) cout<<0<<" "<<poa;
        else if (poa<pob) cout<<1<<" "<<pob;
        else cout<<2<<" "<<poa;
        cout<<'\n';
    }
    return 0;
}
