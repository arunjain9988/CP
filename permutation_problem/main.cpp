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

ll moduloexp(ll a,ll b,ll m) {
    if (b==0) return 1;
    if (b<0) return 0;
    ll res = 1;
    while(b>1) {
        if (b&1) res = (res*a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return (a*res)%m;
}


ll** prechoose() {
    ll** choose = new ll*[1001];
    for (ll i=0; i<1001; i++) {
        choose[i] = new ll[i+1];
    }
    choose[0][0] = 1;
    choose[1][0] = 1;
    choose[1][1] = 1;
    for (ll i=0; i<1001;i++) {
        choose[i][0] = 1;
    }
    for (ll i=1; i<=1000; i++) {
        for (ll j=1; j<=i; j++) {
            if (i==j) choose[i][j] = 1;
            else 
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;
        }
    }
    return choose;
}

ll nck(ll** choose,ll n,ll k) {
    if (k<0) return 0;
    if (k<=n) return choose[n][k]%MOD;
    return 0;
}

ll calc(ll n,ll k,ll i,ll** choose) {
    ll ret =  (((nck(choose,n,i*k)*moduloexp(10,n-(i*k),MOD))%MOD)*nck(choose,9,i))%MOD;
    if (ret<0) return 0;
    return ret;
}

void next_permutation(string &s) {
        int i=s.size()-1;
        while(i>0) {
            if (s[i]-'0'  > s[i-1]-'0') break;
            i--;
        }
        int llll = s.size()-1;
        while(llll>=0) {
            if (s[llll] > s[i-1]) break;
            llll--;
        }
        swap(s[llll],s[i-1]);
        int st = i;
        int l = s.size()-1;
        while(st<l) {
            swap(s[st],s[l]);
            st++;
            l--;
        }
    }
string getPermutation(int n, int k) {
    string s;
    for (int i=1; i<=n; i++){
        s.push_back((char)(i+'0'));
    }
    for (int i=1; i<k; i++) {
        next_permutation(s);
        cout<<s<<endl;
    }
    return s;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // int tmp[]{7,8,6,5,4,2,1};
    // next_permutation(tmp,tmp+7);
    // for (int i=0 ;i<7; i++) {cout<<tmp[i];}
    // string p = "7865421";
    // getPermutation(4,5);
    // cout<<p;

    ll t,n,k;
    ll** choose = prechoose();
    // for (int i=0; i<10; i++) {
    //     for (int j=0; j<=i; j++) {
    //         cout<<choose[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if ((n+k-1)/k>10){
            cout<<k<<" "<<0<<'\n';
            continue;
        }
        ll sign = -1;
        ll i=1;
        ll ans = (moduloexp(10,n-1,MOD)*9)%MOD;
        while(i<=10) {
            // ans =  (ans + (sign)*( (9*nck(choose,n,i*(k+1))*moduloexp(10,n-(i*(k+1)),MOD))%MOD + (nck(choose,n-1,i*(k+1)*moduloexp(10,n-1-(i*(k+1)),MOD)*9))%MOD))%MOD;
            ans = (ans+((sign)*(calc(n,k+1,i,choose))))%MOD;
            ans = (ans+((sign)*calc(n-1,k+1,i,choose)))%MOD;
            // ans = (ans+MOD)%MOD;
            i++;
            sign = sign * -1;
        }
        cout<<k<<" "<<ans<<'\n';
    }
    return 0;
}
