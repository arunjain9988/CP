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

char Matrix[100][100];
int* mx[100][100];
int n,m;
int xdir[] = {-1,0,1,0};
int ydir[] = {0,1,0,-1};

void getmax(int i,int j,int* a){
    if (i<0 || i>=n || j<0 || j>=m) return;
    if (Matrix[i][j] == '0') return;
    Matrix[i][j] = '0';
    mx[i][j] = a;
    *(mx[i][j]) = (*(mx[i][j])+1);
    for (int k=0; k<4; k++) {
        getmax(i+xdir[k],j+ydir[k],a);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>Matrix[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            mx[i][j] = new int(0);
            // cout<<M[i][j];
        }
        // cout<<endl;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (Matrix[i][j] == '1') {
                int* a = new int;
                *a = 0;
                // mx[i][j] = a;
                getmax(i,j,a);
            }
            // else mx[i][j] = new int(0);
        }
    }
    int ans = INT_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<4; k++) {
                for (int q=k+1; q<4; q++) {
                    int r1 = i+xdir[k];
                    int c1 = j+ydir[k];
                    int r2 = i+xdir[q];
                    int c2 = j+ydir[q];
                    if (r1>=0 && r1<n && c1>=0 && c1<m && r2>=0 && r2<n && c2>=0 && c2<m) {
                        if (mx[r1][c1] == mx[r2][c2]) continue;
                        ans = max(ans,*(mx[r1][c1])+*(mx[r2][c2]));
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout<<*(mx[i][j]);
    //     }
    //     cout<<endl;
    // }
    return 0;
}
