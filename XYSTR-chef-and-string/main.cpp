#include <bits/stdc++.h>

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

int t,n,x,y,ans;
string str;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.precision(10);
    // cout << fixed;
    cin>>t;
    while(t--) {
        cin>>str;
        ans=0,x=0,y=0;
        loop(i,0,n) {
            cout<<str[i]<<endl;
            if (!x && str[i]=='x') {
                x = 1;
            }
            else if (!y && str[i]=='y') {
                y = 1;
            }
            if (x && y) {
                ans++;
                x=0;
                y=0;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}