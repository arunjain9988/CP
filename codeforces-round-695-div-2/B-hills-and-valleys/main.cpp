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
int n;
int A[300005];
bool horv[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n;
        floop(i,1,n) {
            cin>>A[i];
        }
        int total = 0;
        memset(horv,false,n+1);
        for (int i=2; i<n; i++) {
            if ((A[i] < A[i-1] && A[i] < A[i+1]) || (A[i] > A[i-1] && A[i] > A[i+1])) {
                horv[i] = true;
                total++;
            }
        }
        int cur =  horv[2] + horv[3] + horv[4];
        int ans = total-cur;
        for (int i=5; i<n; i++) {
            cur -= horv[i-3];
            cur += horv[i];
            ans = min(ans,total-cur);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
