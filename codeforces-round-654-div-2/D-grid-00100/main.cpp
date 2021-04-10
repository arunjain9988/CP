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
int p;
int tmp,a,b;
int cur;
int n,k;
int M[302][302];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        p = (n+k-1)/n;
        tmp = k%n;
        if (tmp>0) cout<<2<<'\n';
        else cout<<0<<'\n';
        if (k==0) {
            loop(i,0,n) {
                loop(j,0,n) {
                    cout<<0;
                }
                cout<<"\n";
            }
            continue;
        }
        cur=0;
        loop(i,0,n) {
            loop(j,0,n) {
                M[i][j]=0;
            }
        }
        if (tmp==0)  tmp=1000005;
        loop(i,0,n) {
            a = i;
            // b = p;
            loop(j,0,p) {
                // if (b>0) {
                    if (tmp<=0 && j==p-1) continue;
                    M[i][a] = 1;
                    a = (a+1)%n;
                // }
            }
            tmp--;
        }
        loop(i,0,n) {
            loop(j,0,n) {
                cout<<M[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
