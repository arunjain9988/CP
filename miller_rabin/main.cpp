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

void seivefill(vector<int>& primes12,int mx) {
    int lp[100];
    for (int i=1; i<=99; i++) lp[i] = i;
    for (int i=2; primes12.size()<mx; i++) {
        if (lp[i] == i) primes12.pb(i);
        for (int j=0; j<primes12.size() && primes12[j]*i<=99; j++) {
            lp[primes12[j]*i] = primes12[j];
            if (primes12[j] == lp[i]) break;
        }
    }
}

ll modular_multiplication(unsigned long long a,unsigned long long b,unsigned long long n) {
    // trace3(a,b,n);
    unsigned long long res = 0;
    while (b) {
        if (b&1) {
            res = (res+a)%n;
        }
        a = (2*a)%n;
        b>>=1;
    }
    // trace3(a,b,n);
    return res;
}


unsigned long long modular_Exponentiation(unsigned long long a,unsigned long long b,unsigned long long m) {
    if (a==0) return 0;
    unsigned long long res = 1;
    while(b){
        // if (b&1) res = ((__uint128_t)res * a)%m;
        if (b&1) res = modular_multiplication(res,a,m);
        // a = ((__uint128_t)a*a)%m;
        a = modular_multiplication(a,a,m);
        b>>=1;
        // trace1(b);
    }
    return (res+m)%m;
}

bool millerPrime(unsigned long long n) {
    if (n<=4) return (n==2 || n==3); 
    vector<int> primes12;
    seivefill(primes12,13);
    unsigned long long s=0;
    unsigned long long d=n-1;
    while(d%2==0) {
        s++;
        d/=2;
    }
    // for (int i=0; i<primes12.size(); i++) cout<<primes12[i]<<' ';
    for (int i=0; i<13; i++) {
        // int s=0;
        unsigned long long atod = modular_Exponentiation(primes12[i],d,n);
        if (atod == 1) continue;
        int curpow = 0;
        while(curpow < s) {
            if (atod == n-1) break;
            // atod = ((__uint128_t)atod*atod)%n;
            atod = modular_multiplication(atod,atod,n);
            curpow++;
        }
        if (curpow == s) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        unsigned long long n;
        cin>>n;
        if (millerPrime(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
