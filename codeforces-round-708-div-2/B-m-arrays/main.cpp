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

int t,n,m,tmp;
int A[100005];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans = 0;
        memset(A,0,sizeof(A));
        loop(i,0,n) {
            cin>>tmp;
            A[tmp%m]++;
        }
        for (int i=1; i<=(m)/2; i++) {
            if (i==(m-i)) {
                if (A[m-i]>0) ans++;
                A[m-i] = 0;
                break;
            }
            while(A[i]>0 && A[m-i]>0) {
                A[i]--;
                A[m-i]--;
            }
            if (A[i]>0) A[i]--;
            else if (A[m-i]>0) A[m-i]--;
            ans++;
        }
        for (int i=1; i<m; i++) {
            ans  += A[i];
        }
        if (A[0]) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
