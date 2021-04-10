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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int cnt[26];
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        for (int i=0; i<26; i++) cnt[i] = 0;
        for (char c:s) {
            cnt[c-'a']++;
        }
        int even_gr  =0;
        int singlechar = 0;
        int half = 0;
        for (int i=0; i<26; i++) {
            if ((cnt[i] > 1) && (cnt[i]%2==0)) {
                even_gr += (cnt[i]/2);
            }
            else if (cnt[i] == 1) singlechar++;
            else if (cnt[i]>1) {
                even_gr += (cnt[i]/2);
                singlechar++;
            }
        }
        if (even_gr >= singlechar) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
