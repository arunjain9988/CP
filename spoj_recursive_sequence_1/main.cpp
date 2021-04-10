#include <bits/stdc++.h>  // This will work only for g++ compiler. 
#define MOD 1000000000

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

template <typename T>
vector<vector<ll> > multiply(vector<vector<ll> > m1,T m2) {
    vector<vector<ll> > res(m1.size(),vector<ll>(m1.size()));
    for (int i=0; i<m1.size(); i++) {
        for (int j=0; j<m1[i].size(); j++) {
            res[i][j] = 0;
            for (int k=0; k<res.size(); k++) {
                res[i][j] += m1[i][k]*m2[k][j];
                res[i][j]%= MOD;
            }
        }
    }
    return res;
}


vector< vector<ll> > matrixPower(ll** m,int pow,int k) {
    if (pow == 1){
        vector<vector<ll> > ret(k,vector<ll>(k));
        loop(i,0,k) {
            loop(j,0,k) {
                ret[i][j] = m[i][j];
            }
        }
        return ret;
    }
    vector< vector<ll> > ans = matrixPower(m,pow/2,k);
    vector<vector<ll> > res  = multiply(ans,ans);
    if (pow&1) {
        res = multiply(res,m);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t;
    int k;
    ll* b;
    ll* c;
    ll n;
    cin>>t;
    while(t--) {
        cin>>k;
        b = new ll[k];
        c = new ll[k];
        loop(i,0,k){
            cin>>b[i];
        }
        loop(i,0,k) {
            cin>>c[i];
        }
        cin>>n;
        if (n<=k) {
            cout<<b[n-1]<<'\n';
        }
        else {
            ll** matrix = new ll*[k];
            loop(i,0,k) {
                matrix[i] = new ll[k];
                loop(j,0,k) {
                    if (i==0) matrix[i][j] = c[j];
                    else if (i==j+1) matrix[i][j] = 1;
                    else matrix[i][j] = 0;
                }
            }
            vector<vector<ll> > recurrence = matrixPower(matrix,n-k,k);
            ll ans = 0;
            loop(i,0,k) {
                ans += (recurrence[0][i]* b[k-i-1]);
                ans%=MOD;
            }
            cout<<ans<<'\n';
            // loop(i,0,recurrence.size()) {
            //     loop (j,0,recurrence[i].size()) {
            //         cout<<recurrence[i][j]<<" ";
            //     }
            //     cout<<'\n';
            // }
        }
    }

    return 0;
}
