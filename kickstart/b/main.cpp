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

int t,n;
ll ans;
vector<vector<int> > input;
int r,c;

struct cell{
    int left;
    int right;
    int top;
    int down;
    
};

vector<vector<cell> > dp;

void filldp(vector<vector<cell> > &dp) {
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (input[i][j] == 0){
                dp[i][j] = {0,0,0,0};
            }
            else {
                dp[i][j].top = input[i][j] + dp[i-1][j].top;
                dp[i][j].left = input[i][j] + dp[i][j-1].left;
            }
        }
    }

    for (int i=r; i>=1; i--) {
        for (int j=c; j>=1; j--) {
            if (input[i][j] == 0){
                dp[i][j] = {0,0,0,0};
            }
            else {
                dp[i][j].down = input[i][j] + dp[i+1][j].down;
                dp[i][j].right = input[i][j] + dp[i][j+1].right;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    vector<vector<cell> > dp;
    loop(_t,t) {
        cin>>r>>c;
        input = vector<vector<int> >(r+2,vector<int>(c+2,0));
        for (int i=1; i<=r; i++) {
            floop(j,1,c) {
                cin>>input[i][j];
            }
        }
        // dp = vector<vector<cell> >(r+1,vector<cell>(c+1,0));
        // dp.resize(r+2);
        // for (int i=0; i<=r+1; i++) dp[i].resize(c+2);
        // vector<vector<cell> > dp(r+1,vector<cell>(c+1,0));
        dp.resize(r+3);
        for (int i=0; i<=r+2; i++) {
            dp[i].resize(c+3);
            for (int j=0; j<=c+2; j++) {
                dp[i][j] = {0,0,0,0};
            }
        }
        filldp(dp);
        ll ans = 0;
        for (int i=1; i<=r; i++) {
            for (int j=1; j<=c; j++) {
                int new_ans = 0;
                int calc = min(max(dp[i][j].top,dp[i][j].left)/2,min(dp[i][j].top,dp[i][j].left))-1;
                if (calc>0) new_ans+=calc;
                calc = min(max(dp[i][j].top,dp[i][j].left),min(dp[i][j].top,dp[i][j].left)/2)-1;
                if (calc>0) new_ans+=calc;
                // cout<<i<<' '<<j<<' '<<calc<<'\n';
                calc = min(max(dp[i][j].top,dp[i][j].right)/2,min(dp[i][j].top,dp[i][j].right))-1;
                if (calc>0) new_ans+=calc;
                calc = min(max(dp[i][j].top,dp[i][j].right),min(dp[i][j].top,dp[i][j].right)/2)-1;
                if (calc>0) new_ans+=calc;
                // cout<<i<<' '<<j<<' '<<calc<<'\n';
                calc = min(max(dp[i][j].down,dp[i][j].left)/2,min(dp[i][j].down,dp[i][j].left))-1;
                if (calc>0) new_ans+=calc;
                calc = min(max(dp[i][j].down,dp[i][j].left),min(dp[i][j].down,dp[i][j].left)/2)-1;
                if (calc>0) new_ans+=calc;
                // cout<<i<<' '<<j<<' '<<calc<<'\n';
                calc = min(max(dp[i][j].down,dp[i][j].right)/2,min(dp[i][j].down,dp[i][j].right))-1;
                if (calc>0) new_ans+=calc;
                calc = min(max(dp[i][j].down,dp[i][j].right),min(dp[i][j].down,dp[i][j].right)/2)-1;
                if (calc>0) new_ans+=calc;
                // cout<<i<<' '<<j<<' '<<calc<<'\n';
                // cout<<i<<' '<<j<<' '<<new_ans<<'\n';
                ans += new_ans;
            }
        }
        // floop(i,0,r) {
        //     floop(j,0,c) {
        //         cout<<dp[i][j].top<<' ';
        //     }
        //     cout<<'\n';
        // }
        //     cout<<'\n';
        // floop(i,0,r) {
        //     floop(j,0,c) {
        //         cout<<dp[i][j].left<<' ';
        //     }
        //     cout<<'\n';
        // }
        //     cout<<'\n';
        // floop(i,0,r) {
        //     floop(j,0,c) {
        //         cout<<dp[i][j].down<<' ';
        //     }
        //     cout<<'\n';
        // }
        //     cout<<'\n';
        // floop(i,0,r) {
        //     floop(j,0,c) {
        //         cout<<dp[i][j].right<<' ';
        //     }
        //     cout<<'\n';
        // }
        cout<<"Case #"<<_t+1<<": "<<ans<<'\n';
    }
    return 0;
}
