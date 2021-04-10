#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, r) for (int i = (int)(0); i < (int)(r); ++i)
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

// useful constants
#define MOD 1000000007
#define EPS (double)1e-6

using namespace std;


// Important header files   ordered set
// #include <ext/pb_ds/assoc_container.hpp> // Common file  
// #include <ext/pb_ds/tree_policy.hpp>  
// #include <functional> // for less

// using namespace __gnu_pbds;
// template <typename T>
// using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};

int dp[25][25];

// int lcs(string a,string b,int n,int m,int cnt) {
//     if (dp[n][m]!=-1) return dp[n][m];
//     if (n==0 || m==0) return cnt;
//     if (a[n-1] == b[m-1])
//     return max(lcs(a,b,n-1,m-1,cnt+1),max(cnt,max(lcs(a,b,n-1,m,0),lcs(a,b,n,m-1,0))));
//     return max(cnt,max(lcs(a,b,n-1,m,0),lcs(a,b,n,m-1,0)));
// }]
string X,Y;
int ans=0;

int lcs(int n, int m)   
{                        
  if(n == 0 || m == 0) return 0;   
  if(dp[n][m] != -1) return dp[n][m];

  lcs(n-1,m);          
  lcs(n,m-1);         

  if(X[n-1] == Y[m-1])
  {

    dp[n][m] =  lcs(n-1,m-1) + 1;
    ans = max(ans, dp[n][m]);
    return dp[n][m];
  }
    return dp[n][m] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    string a,b;
    cin>>t;
    while(t--) {
        // memset(dp,-1,sizeof(dp));
        for (int i=0; i<25; i++) {
            for (int j=0; j<25; j++) dp[i][j] = -1;
        }
        cin>>a>>b;
        X=a,Y=b;
        ans = 0;
        // cout<<a.size()<<' '<<b.size()<<'\n';
        int lc = lcs(a.size(),b.size());
        // cout<<lc<<' ';
        cout<<a.size()+b.size()-ans-ans<<'\n';
    }
    return 0;
}
