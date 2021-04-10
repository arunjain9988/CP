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

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int n;

vector<int> gcd(int a,int m) {
    vector<int> res(3);
    if (m==0) {
        res[0] = 1;
        res[1] = 0;
        res[2] = a;
        return res;
    }
    res = gcd(m,a%m);
    int x = res[1];
    int y = res[0] - (a/m)*res[1];
    res[0] = x;
    res[1] = y;
    return res;
}

ll moduloInverse(int a,int m) {
    // if (__gdc(a,m) != 1) not possible
    vector<int> triplet(3);
    triplet = gcd(a,m);
    return triplet[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n;
    const ll mod = 109546051211LL;
    const ll m1 = 186583;
    const ll m2 = 587117;
    ll x1 = 1;
    ll x2 = 1;
    ll fact = 1;
    ll fact1 = 1;
    ll fact2 = 1;
    ll validans = 1;
    for (int i=2; i<=n; i++) {
        fact1 = (fact1*i)%m1;
        fact2 = (fact2*i)%m2;
        fact = (fact*i)%mod;
        x1 = (x1*fact1)%m1;
        x2 = (x2*fact2)%m2;
        validans = ((__int128_t)validans*fact)%mod;
    }
    // cout<<validans<<'\n';

    // Will Apply CRT
    ll val1 = m2*moduloInverse(m2,m1)*x1;
    ll val2 = m1*moduloInverse(m1,m2)*x2;
    ll ans = val1+val2;
    cout<<ans%mod<<'\n';
    return 0;
}
