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
int n,k;
int H[105];
    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        loop(i,0,n) {
            cin>>H[i+1];
        }
        if (k>=10000) {
            cout<<"-1\n";
            continue;
        }
        bool waste = false;
        for (int i=1; i<=k; i++) {
            int j=1;
            while(j<n && H[j]>=H[j+1]) {
                j++;
            }
            if (j==n) waste = true;
            else H[j]++;
            if (i==k) {
                if (waste) cout<<"-1\n";
                else cout<<j<<'\n';
            }
        }
        // if (waste) cout<<"-1\n";
        // else {
        //     int j=1;
        //     while(j<n && H[j]>=H[j+1]) {
        //         j++;
        //     }
        //     if (j==n) waste = true;
        // }
    }
    return 0;
}
