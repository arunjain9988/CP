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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t;
    int x,y;
    string s;
    int u,d,r,l;
    cin>>t;
    while(t--) {
        cin>>x>>y;
        cin>>s;
        u =0,d=0,r=0,l=0;
        loop(i,0,s.size()) {
            if (s[i] == 'U') {
                u++;
            }
            else if (s[i] == 'D') {
                d++;
            }
            else if (s[i] == 'R') r++;
            else l++;
        }
        bool canx = false;
        bool cany = false;
        if (x>=0 && r>=x) { 
            canx = true;
        } 
        if (x<0 && l>=(-1*x)) canx = true;
        if (y>=0 && u>=y) cany= true;
        if (y<0 && d>=(-1*y)) cany = true;
        if (canx && cany) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
