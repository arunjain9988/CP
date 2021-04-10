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

//debug
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

#define MOD 1000000007

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

vector<pair<ll,int> > t_primes;
int lp[1000001];
vector<int> primes;

void pre() {
    for (ll i=2; i<=1000000; i++) {
        t_primes.push_back(make_pair(i*i,i));
    }
    // bool seive[1000001];
    // memset(seive,true,sizeof(seive));
    // seive[0] = false;
    // seive[1] = false;
    for (int i=2; i<=1000000; i++) lp[i] = i;
    for (int i=2; i<=1000000; i++) {
        if (lp[i] == i) {
            primes.push_back(i);
        }
        for (int j=0; (j<primes.size() && primes[j]*i<=1000000 ); j++) {
            lp[primes[j]*i] = primes[j];

            if (lp[i] == primes[j]) break;
        }
    }
    // for (int i=0; i<primes.size(); i++) {
    //     cout<<primes[i]<<"\n";
    // }
}


void solve(ll x) {
    int idx = lower_bound(all(t_primes),make_pair(x,0)) - t_primes.begin();
    // int idx2 = lower_bound(all())
    if (idx != t_primes.size() && t_primes[idx].first == x && lp[t_primes[idx].second] == t_primes[idx].second) {
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    pre();
    int n;
    cin>>n;
    ll x;
    loop(i,0,n) {
        cin>>x;
        solve(x);
    }
    // cout<<1e12;
    return 0;
}