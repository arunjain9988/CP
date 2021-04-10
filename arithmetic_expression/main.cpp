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


int dp[10005][102];

int pw(int a,int b,int m) {
    if (a==0) return 0;
    int res = 1;
    while(b) {
        if (b&1) res = (res*a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return res;
}

int inv(int n,int m) {
    return pw(n,m-2,m);
}

bool solve(int n,int s,int* A) {
    s = (s+101)%101;
    if (n==0) {
        if (s==A[0]) {
            cout<<A[0];
            return true;
        }
        return false;
    }
    if (dp[n][s] != -1) return dp[n][s]==1;
    if (solve(n-1,(s-n[A])%101,A)) {
        cout<<'+'<<A[n];
        return dp[n][s]=true;
    }
    else if (solve(n-1,(s+n[A])%101,A)) {
        cout<<'-'<<A[n];
        return dp[n][s]=true;
    }
    else if (solve(n-1,(s*inv(A[n],101))%101,A)) {
        cout<<'*'<<A[n];
        return dp[n][s]=true;
    }
    return dp[n][s]=false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int A[n];
    loop(i,0,n) {
        cin>>A[i];
    }
    solve(n-1,101,A);
    return 0;
}
