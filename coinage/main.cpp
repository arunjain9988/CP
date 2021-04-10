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

ll choose[20000][5];

void pre() {
    choose[0][0] = 1;
    for (int i=1; i<20000; i++) {
        if (i<5) {
            choose[0][i] = 0;
            choose[i][i] = 1;
        }
        choose[i][0] = 1;
    }
    for (int i=1; i<20000; i++) {
        for (int j=1; (j<i) && (j<5); j++){
            choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%MOD;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t;
    // int coins[]{1,2,5,10};
    int input[5];
    cin>>t;
    pre();
    int n;
    // for (int i=0; i<40; i++) {
    //     for (int j=0; j<5; j++) {
    //         cout<<"choose "<<i<<" "<<j<<" "<<choose[i][j]<<endl;
    //     }
    //     cout<<endl;
    // }
    // int a,b,c,d;
    while(t--) {
        cin>>n;
        for (int i=0; i<4; i++) {
            cin>>input[i];
        }
        ll ans = 0;
        for (int i =1; i<(1<<4); i++) {
            int cnt = 0;
            ll num = n+3;
            for (int j=0; j<4; j++) {
                if (i&(1<<j)) {
                    cnt++;
                    num -= input[j]+1;
                }
            }
            if (num < 3) continue;
            if (cnt&1) {
                ans += choose[num][3];
            }
            else ans -= choose[num][3];
            cout<<"choose "<<num<<" "<<ans<<' '<<"ans"<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
