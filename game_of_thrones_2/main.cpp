#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define MOD 1000000007

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

ll modularExponentiation(ll a,ll b,ll m) {
    if (a == 0) return 0;
    if (b==0) return 1;
    ll res = 1;
    while(b>1) {
        if (b&1) res = (res*a)%m;
        b>>=1;
        a = (a*a)%m;
        a%=m;
    }
    return (res*a)%m;
}

ll fact[100005];
ll infact[100005];

void pre(){
    fact[0] = 1;
    for (int i=1; i<=100000; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    infact[0] = 1;
    infact[1] = 1;
    for (int i=2; i<=100000; i++) {
        infact[i] = modularExponentiation(i,MOD-2,MOD);
        infact[i] = (infact[i]*infact[i-1])%MOD;
        // cout<<infact[i]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    pre();
    string input;
    cin>>input;
    int times[26]{0};
    for (int i=0; i<input.size(); i++) {
        times[input[i]-'a']++;
    }
    for (int i=0; i<26; i++) {
        times[i]/=2;
        // if (times[i] != 0) cout<<times[i]<<" ";
    }
    ll ans=fact[input.size()/2];
    // cout<<ans<<endl;
    for (int i=0; i<26; i++) {
        if (times[i] == 0) continue;
        ans = (ans*infact[times[i]])%MOD;
        // cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
