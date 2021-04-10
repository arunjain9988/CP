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

int** ncrprefill(int maxn,int maxr) {
        int** ans = new int*[maxn+1];
        for (int i=0; i<=maxn; i++) {
            ans[i] = new int[maxr+1];
            for (int j=0; j<=maxr; j++) {
                ans[i][j] = 0;
            }
        }
        // memset(ans,0,sizeof(ans));
        for (int i=0; i<=maxn; i++){
            ans[i][0] = 1;
            for (int j=1; j<=min(maxr,i); j++) {
                ans[i][j] = (ans[i-1][j-1] + ans[i-1][j])%MOD;
            }
        }
        // for (int i=1; i<=n; i++) {
        //     for (int j=min(i,fixr); j>=1; j--) {
        //         ans[j] = (ans[j] + ans[j-1])%MOD;
        //     }
        // }
        return ans;
    }
    
    int nr(int n,int r,int** ans) {
        if (n<0 || r<0) return 0;
        return ans[n][r];
    }
    
    int numRollsToTarget(int d, int f, int t) {
        int** ncr = ncrprefill(t,d);
        int cur = 1;
        long long ans = 0;
        long long newans = 0;
        for (int i=0; i<=d; i++) {
            newans = (ll)nr(d,i,ncr)*nr(t-(i*f)-1,d-1,ncr);
            if (newans == 0) break;
            ans = ans+ (cur*newans)%MOD;
            cur = -cur;
        }
        return (ans+MOD)%MOD;
        
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
    int d,f,target;
    ll n,r;
    while(t--) {
        cin>>d>>f>>target;
        // int** ncr = ncrprefill(target,10);
        cout<<numRollsToTarget(d,f,target)<<'\n';
    }
    return 0;
}
