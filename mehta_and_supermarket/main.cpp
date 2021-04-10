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

int n;
int A[18];
unsigned long long _lcm[1<<17];

void pre_lcm() {
    _lcm[0] = 1;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                _lcm[i] = (A[j]*_lcm[i^(1<<j)])/__gcd((unsigned long long)A[j],_lcm[i^(1<<j)]);
                break;
            }
        }
    }
}



unsigned long long solve(long long number) {
    unsigned long long ans = 0;
    for (int i=1; i<(1<<n); i++) {
        // unsigned long long bits = __builtin_popcount(i);
        unsigned long long cur=_lcm[i];
        // unsigned long long j=i;
        unsigned long long bitscnt = __builtin_popcount(i);
        // int tmp = i;
        // for (unsigned long long j=0; j<n; j++) {
        //     if (i&(1<<j)) {
        //         bitscnt++;
        //         cur = (cur*A[j])/__gcd(cur,(unsigned long long)A[j]);
        //         if (cur>number) break;
        //         tmp = tmp&(tmp-1);
        //         if (tmp == 0) break;
        //     }
        // }
                // cout<<"cur "<<cur<<'\n';
        if (bitscnt&1) {
            ans += (number/cur);
        }
        else {
            ans -= (number/cur);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    // set<int> dup;
    loop(i,0,n) {
        cin>>A[i];
        // if (dup.find(A[i]) != dup.end()) {
        //     i--;
        //     n--;
        // }
        // dup.insert(A[i]);
    }
    // for (int i=0; i<n; i++) {
    //     cout<<A[i]<<"\n";
    // }
    unsigned long long q,l,r;
    pre_lcm();
    cin>>q;
    while(q--) {
        cin>>l>>r;
        unsigned long long totalans = solve(r);
        unsigned long long lessans = solve(l-1);
        cout<<totalans-lessans<<'\n';
    }
    return 0;
}
