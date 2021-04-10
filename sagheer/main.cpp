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

int dp[16][2];

int get_min(string building[], int row,int startorend,int leftmost[],int rightmost[]) {
    // trace2(row,startorend);
    if (dp[row][startorend] != -1) return dp[row][startorend];
    if (row == 0) {
        if (startorend == 0) {
            return dp[row][0]=rightmost[0]*2;
        }
        else {
            return dp[row][1]=building[0].size()-1;
        }
    }
    if (startorend == 0) {
        // trace1(row);
        return dp[row][0] = min(rightmost[row]*2 + get_min(building,row-1,0,leftmost,rightmost) +1,
        get_min(building,row-1,1,leftmost,rightmost)+(int)building[row].size());
    }
    else {
        return dp[row][1] = min(leftmost[row]*2+get_min(building,row-1,1,leftmost,rightmost)+1,
        get_min(building,row-1,0,leftmost,rightmost)+(int)building[row].size());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    m+=2;
    string building[n];
    for (int i=n-1; i>=0; i--) {
        cin>>building[i];
        // trace1(building[i]);
    }
    for (int i=n-1; i>=0; i--) {
        if (building[i] == string(m,'0')){
            n--;
        }
        else break;
    }
    int leftmost[n];
    int rightmost[n];
    for (int i=0;i<n; i++) {
        leftmost[i] = 0;
        rightmost[i] = 0;
        for (int j=0; j<m; j++) {
            if (building[i][j] == '1') {
                if (leftmost[i] == 0) leftmost[i] = j;
                rightmost[i] = j;
            }
        }
        if (leftmost[i] != 0) leftmost[i] = m-leftmost[i]-1;
        // trace2(leftmost[i],rightmost[i]);
    }
    memset(dp,-1,sizeof(dp));
    if (n==0) cout<<"0";
    else if (n==1) cout<<rightmost[0];
    else cout<<min(get_min(building,n-2,0,leftmost,rightmost)+rightmost[n-1]+1,get_min(building,n-2,1,leftmost,rightmost)+leftmost[n-1]+1);
    // for (int i=n-1; i>=0; i--) {
    //     for (int j=0; j<2; j++) {
    //         cout<<dp[i][j]<<" " ;
    //     }
    //     cout<<endl;
    // }
    return 0;
}
