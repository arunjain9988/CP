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

ll** matrixMul(ll** A,ll** B) {
    ll** res = new ll*[2];
    loop(i,0,2) res[i] = new ll[2];
    for (ll i=0; i<2;i++) {
        for (ll j=0; j<2; j++) {
            res[i][j] = 0;
            for (ll k=0; k<2; k++) {
                res[i][j] += (A[i][k] * B[k][j])%MOD;
            }
        }
    }
    return res;
}

ll** matrixExp(ll** M,ll n) {
    ll **res = new ll*[2];
    res[0] = new ll[2];
    res[1] = new ll[2];
    res[0][0]=1,res[0][1]=0,res[1][0]=0,res[1][1]=1;
    while(n) {
        if (n&1) res = matrixMul(res,M);
        M = matrixMul(M,M);
        n>>=1;
    }
    return res;
}

int gcd1(int a,int b) {
    if (b==0) return 0;
    return (gcd1(b,a%b)+1);
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
    ll n;
    while(t--) {
        cin>>n;
        if (n==0){
            cout<<1<<'\n';
            continue;
        }
        ll **M  = new ll*[2];
        loop(i,0,2) {
            M[i] = new ll[2];
        }
        M[0][0]=0,M[0][1]=1,M[1][0]=1,M[1][1]=1;
        ll** mtopown = matrixExp(M,n);
        ll ans = (mtopown[0][1] + mtopown[1][1])%MOD;
        cout<<ans<<'\n';
        // cout<<gcd1(mtopown[0][1],mtopown[1][1])<<'\n';
    }
    return 0;
}
