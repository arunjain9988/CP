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

int n,q,tmp;
int pre[100005][31];

void fillxorsum(int v1,int v2[],int ret[]) {
    for (int i=0; i<31; i++) {
        ret[i] += v2[i] + (bool)(v1&(1<<i));
        // cout<<ret[i]<<" ";
    }
    // cout<<'\n';
}

ll solve(int l,int r,int x) {
    int ans[31];
    for (int i=0; i<31; i++) {
        ans[i] = pre[r][i]-pre[l-1][i];
        if ((bool)(x&(1<<i))) {
            ans[i] = r-l+1-ans[i];
        }
            // cout<<ans[i]<<" ";
    }
    ll result = 0;
    ll carry = 0;
    ll i=0;
    for (i=0; i<31; i++) {
        ll sm = ans[i]+carry;
        if (sm&1) {
            result |= ((1<<i));
        }
        carry = (sm>>1);
    }
    while (carry) {
        if (carry&1) {
            result |= ((1ll<<i));
        }
        carry = (carry>>1);
        i++;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>q;
    for (int i=0; i<31; i++) {
        pre[0][i] = 0;
    }
    loop(i,0,n) {
        cin>>tmp;
        fillxorsum(tmp,pre[i],pre[i+1]);
    }
    int l,r,x;
    loop(i,0,q) {
        cin>>l>>r>>x;
        cout<<solve(l,r,x)<<'\n';
    }
    return 0;
}