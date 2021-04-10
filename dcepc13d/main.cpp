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

int t;

void get_num(int m,vector<int>& num) {
    for (ll i=2; i*i<=m; i++) {
        if (m%i==0){
            num.pb(i);
            m/=i;
        }
    }
    if (m>1) num.pb(m);
}

int ncr(int n,int r,int m) {
    int C[r+1];
    // memset(C,0,sizeof(C));
    for (int i=0; i<r+1; i++) C[i] = 0;
    C[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=min(i,r); j>0; j--) {
            C[j] = (C[j]+(ll)C[j-1])%m;
        }
    }
    return C[r];
}

int lucas(int n,int r,int m) {
    // (nCr mod m = n/mCr/m mod m * n%mCr%m mod m)
    if (r==0) return 1;
    int ans = ((ll)lucas(n/m,r/m,m) * ncr(n%m,r%m,m))%m;
    return ans;
}

int moduloExp(int a,int b,int m) {
    int res = 1;
    while(b) {
        if (b&1) res = (res*(ll)a)%m;
        b>>=1;
        a = ((ll)a*a)%m;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,r,m;
    // int num[50];
    // int rem[50];
    vector<int> num;
    vector<int> rem;
    // vector<int> prod;
    cin>>t;
    while(t--) {
        num.clear();
        // prod.clear();
        rem.clear();

        cin>>n>>r>>m;
        get_num(m,num);
        int prod = m;
        for (int i=0; i<num.size(); i++) {
            rem.pb(lucas(n,r,num[i]));
        }
        int ans = 0;
        for (int i=0; i<num.size(); i++) {
            // cout<<num[i]<<" "<<rem[i]<<endl;
            ans = ((ll)ans + ((prod/num[i])*(ll)moduloExp(prod/num[i],num[i]-2,num[i])*(ll)rem[i])%m)%m;
        }
        cout<<ans%m<<'\n';
    }
    return 0;
}
