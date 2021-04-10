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

ll n;
ll k;
ll buildings[16];

ll** matrixmul(ll** m1,ll**m2) {
    ll **res = new ll*[16];
    for (ll i=0; i<16; i++) {
        res[i] = new ll[16];
        for (ll j=0; j<16; j++) {
            res[i][j] = 0;
        }
    }
    for (ll i=1; i<16; i++) {
        for (ll j=1; j<16; j++) {
            res[i][j] = 0;
            for (ll _k=1; _k<16; _k++) {
                res[i][j] += m1[i][_k]*m2[_k][j];
                res[i][j]%=MOD;
            }
        }
    }
    // swap(res,m1);
    // for (ll i=0; i<16; i++) {
    //     for (ll j=0; j<16; j++) {
    //         cout<<m1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return res;
}

ll** matrix_exp(ll** matrix,ll pow) {
    if (pow == 1) return matrix;
    ll** res = new ll*[16];
    for (ll i=0; i<16; i++) {
        res[i] = new ll[16];
        for (ll j=0; j<16; j++) {
            if (i==j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
    while(pow>1) {
        if (pow&1) {
            res = matrixmul(res,matrix);
        }
        matrix = matrixmul(matrix,matrix);
        pow>>=1;
    }
    return matrixmul(matrix,res);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    cin>>k;
    ll mx = 0;
    ll tmp;
    ll H[16]{0};
    loop(i,0,k) {
        cin>>tmp;
        buildings[tmp] = 1;
        mx = max(mx,tmp);
    }
    buildings[0] = 1;
    H[0] = 1;
    for(ll i=1; i<=15; i++) {
        for (ll j=1; j<=i; j++) {
            H[i] += buildings[j]*H[i-j];
            H[i]%=MOD;
        }
    }

    if (n<=15) {
        cout<<(2*H[n])%MOD;
        return 0;
    }

    // for (ll i=1; i<=15; i++) {
    //     cout<<H[i]<<" ";
    // }
    // cout<<'h'<<endl;
    ll** matrix = new ll*[16];
    for (ll j=0; j<16; j++) {
        matrix[j] = new ll[16];
        for (int _k=0; _k<16; _k++) {
            if (j==1) {
                matrix[j][_k] = buildings[_k];
            }
            else if (j==_k+1) {
                matrix[j][_k] = 1;
            }
            else matrix[j][_k] = 0;
        }
    }

    // for (ll i=1; i<16; i++) {
    //     for (ll j=1; j<16;j++) {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    matrix = matrix_exp(matrix,n-15);


    // for (ll i=1; i<16; i++) {
    //     for (ll j=1; j<16;j++) {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // ll ans[16]{0};

    ll llans = 0;
    for (ll i=1; i<=15; i++) {
        llans += matrix[1][i]*H[15-i+1]; 
        llans%=MOD;
    }
    // for (ll i=1; i<=15; i++) {
    //     cout<<ans[i]<<" ";
    // }
    cout<<(2*llans)%MOD;
    return 0;
}
