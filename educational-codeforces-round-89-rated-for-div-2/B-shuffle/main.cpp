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
ll a,b;
ll n,m,x,low,high,tmp;

ll ans(ll n,ll m) {
    ll res=0;
    floop(i,1,n) {
        if (i&1) res+=i;
        else if (i&4) res+=ans(n/2,m);
        else res+=n/2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t; 
    while(t--) {
        cin>>n;
        cin>>m;
        cout<<ans(n,m);
    }
    // vector<int> A;
    // set<int, greater<int>> s;
    // set<int>::iterator it;
    // // int DP[n];
    // loop(i,0,n) {
    //     cin>>x;
    //     // s.insert(A[i]);
    //     vector<int>::iterator it = upper_bound(A.begin(), A.end(), x, std::greater<int>());
    //     if (it == A.end()) A.push_back(x);
    //     else *it = x;
    //     // it++;
    //     // if (it!=s.end()) s.erase(it);
    // }
    // // DP[0]=1;
    // // int ans;
    // // loop(i,1,n) {
    // //     DP[i]=1;
    // //     loop(j,0,i) {
    // //         if (A[j]>A[i]) {
    // //             DP[i]=max(DP[j]+1,DP[i]);
    // //         }
    // //     }
    // //     ans=max(ans,DP[i]);
    // // }
    // cout<<A.size();
    return 0;
}
