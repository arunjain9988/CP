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

set<int> x2;
vector<int> y4;
vector<int> primes;
vector<int> paul_nos;


void pre() {
    for (int k=1; (k*k*k*k)<10000000; k++) {
        y4.push_back(k*k*k*k);
    }
    for (int i=1; i*i<10000000; i++) {
        x2.insert(i*i);
    }
    int *lp = new int[10000000];
    for (int i=2; i<10000000; i++) lp[i] = i;
    for (int i=2; i<10000000; i++) {
        if (lp[i] == i) primes.push_back(i);
        for (int j=0; j<primes.size() && primes[j]*i<10000000; j++) {
            lp[primes[j]*i] = primes[j];
            if (primes[j] == lp[i]) break;
        }
    }
    for (int i=0; i<primes.size(); i++){
        for (int j=0; j<y4.size() && y4[j]<primes[i]; j++) {
            if (x2.find(primes[i]-y4[j]) != x2.end()) {
                paul_nos.push_back(primes[i]);
                break;
            }
        }
    }
    // for (int i=0; i<10; i++) {
    //     cout<<paul_nos[i]<<endl;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    pre();
    cin>>t;
    int n;
    while(t--) {
        cin>>n;
        cout<<upper_bound(all(paul_nos),n) - paul_nos.begin()<<'\n';
    }
    return 0;
}
