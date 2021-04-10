#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

//debug
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

#define MOD 1000000007

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int done;
int ans[11][11];

bool nqueen(int A[],int n,int row,int col,int ld,int rd) {
    // trace4(row,col,ld,rd);
    // for (int i=0; i<n; i++) cout<<A[i]<<" ";
    // cout<<endl;
    // cout<<row<<" "<<col<<" "<<ld<<" "<<rd<<"\n";
    if (row == n) {
        // print
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (A[i] == j){
                    ans[i][j] = 1;
                }
                else ans[i][j] = 0;
            }
            cout<<endl;
        }
        return true;
    }
    for (int i=0; i<n; i++) {
        if ((!(col&(1<<i))) && (!(ld&(1<<i))) && (!(rd&(1<<i)))){
            // trace1(row);
            A[row] = i;
            if (nqueen(A,n,row+1,col|(1<<i),done&((ld|(1<<i))>>1),done&(((rd|(1<<i))<<1))))
                return true;
        }
    }
    return false;
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
    done = (1<<n)-1;
    int A[n];
    memset(A,-1,sizeof(A));
    if (nqueen(A,n,0,0,0,0)){
        cout<<"YES\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    else cout<<"NO\n";
    return 0;
}