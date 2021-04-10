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

vector<int> primes;

void pre() {
    primes.reserve(57614552);
    int *lp = new int[100000001];
    for(int i=2; i<=100000000; i++) lp[i] = i;
    for (int i=2; i<=100000000; i++) {
        if (lp[i] == i) primes.pb(i);
        for (int j=0; j<primes.size() && primes[j]*i<=100000000; j++) {
            lp[primes[j]*i] = primes[j];
            if (lp[i] == primes[j]) break;
        }
    }
    // primes.pb(2);
    // bitset<100000001> *isPrime = new bitset<100000001>();
    // for (ll i=3; i<=100000000; i+=2) {
    //     if (!isPrime->test(i)) {
    //         primes.pb(i);
    //         for (ll j=i*i; j<=100000000; j+=i) {
    //             isPrime->set(j);
    //         }
    //     }
    // }
    // cout<<primes.size();
}

int bs(int n) {
    int low = 0,high = 100000;
    while(low<high) {
        int mid = (low+high+1)/2; 
        if ((ll)mid*(mid+1) < 2*n) {
            low = mid;
        }
        else high = mid-1;
    }
    return low;
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
        // k*(k+1) <n
        int idx = lower_bound(all(primes),n) - primes.begin();
        // cout<<"idx "<<idx<<'\n';
        if (idx == primes.size() || primes[idx] != n) {
            cout<<"-1\n";
            continue;
        }
        idx++;
        int row = bs(idx);
        row++;
        cout<<row<<" "<<idx - (((ll)row*(row-1)/2)) <<'\n';
    }
    return 0;
}
