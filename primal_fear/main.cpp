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

// int lp[1000000];
int presum[1000000];

void pre() {
    bool isPrime[1000000];
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = false;
    for (int i=2; i<1000000; i++) {
        if (!isPrime[i]) continue;
        // if (isPrime[i]) {
        for (ll j=(ll)i*i; j<1000000; j+=i) {
            isPrime[j] = false;
        }
        // }
        int cur = 1;
        int copy = i;
        while(copy>9) {
            cur*=10;
            if (copy%10 == 0) {
                isPrime[i] = false;
                break;
            }
            copy/=10;
        }
        if (isPrime[i])
        isPrime[i] = isPrime[i%cur];
    }
    // for (int i=1; i<2000; i++) {
    //     if (isPrime[i]) cout<<i<<'\n';
    // }
    presum[1] = 0;
    for (int i=2; i<1000000; i++) {
        presum[i] = presum[i-1] + isPrime[i];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    int n;
    pre();
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<presum[n]<<'\n';
    }
    return 0;
}
