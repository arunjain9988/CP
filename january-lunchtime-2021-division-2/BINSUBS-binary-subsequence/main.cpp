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


int zeros[100005];
int ones[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t,n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        loop(i,0,n) {
            zeros[i] = 0;
            ones[i] = 0;
        }
        if (s[0] == '0') {
            zeros[0]++;
        }
        if (s[n-1] == '1') {
            ones[n-1]++;
        }
        loop(i,1,n) {
            if (s[i] == '0') {
                zeros[i]++;
            }
            zeros[i] += zeros[i-1];
        }
        rloop(i,n-2,0) {
            if (s[i] == '1'){
                ones[i]++;
            }
            ones[i] += ones[i+1];
        }
        int mx=0;
        loop(i,0,n-1) {
            mx = max(mx,zeros[i]+ones[i+1]);
        }
        mx = max(mx,ones[0]);
        mx = max(mx,zeros[n-1]);
        cout<<n-mx<<'\n';
    }
    return 0;
}
