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

int t;
__int128_t n;
vector<int> primes;

void pre() {
    bitset<100000001> *bs = new bitset<100000001>();
    for (ll i=2; i<=100000000; i++) {
        if (bs->test(i)) continue;
        primes.pb(i);
        for (ll j=i*i; j<=100000000; j+=i) {
            bs->set(j);
        }
    }
}

__int128_t modularExp(__int128_t a,__int128_t b){
    __int128_t res = 1;
    while(b) {
        if (b&1) res = res*a;
        a = a*a;
        b>>=1;
    }
    return res;
}

void print_uint128(__int128_t n)
{
    // trace1(n);
    if (n == 0) {
      return;
    }

    print_uint128(n/10);
    // cout<<(ll)(n%10)<<endl;
    cout<<(char)(n%10+0x30);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    pre();
    while(t--) {
        // cin>>n;
        ll k;
        cin>>k;
        n = (__int128_t)k;
        __int128_t ncp = n;
        if (n==1){
            cout<<0<<'\n';
            continue;
        }
        __int128_t i=0;
        __int128_t ans = 1;
        while(n>1 && i<primes.size() && (__int128_t)primes[i]*primes[i]<=n) {
            __int128_t cur_pow = 0;
            while (n%primes[i] == 0) {
                cur_pow++;
                n/=primes[i];
            } 
            if (cur_pow>0) {
                // p1^a1+1 -1/p1-1
                __int128_t num = (modularExp(primes[i],cur_pow+1)-1);
                __int128_t den = primes[i]-1;
                ans = (__int128_t)ans* (num/den);
            }
            i++;
        }
        if (n>1) {
            ans = (__int128_t)ans* ( ((n*n)-1)/(n-1));
        }
        // cout<<(ans-ncp)<<'\n';
        // printf("__int128 max  %016"PRIans64"%016"PRIx64"\n",(__int64_t)(x>>64),(__int64_t)x);
        print_uint128(ans-ncp);
        cout<<'\n';
        // print_uint128(1000000000000000ll*(__int128_t)(10000000000000000ll));
    }
    return 0;
}
