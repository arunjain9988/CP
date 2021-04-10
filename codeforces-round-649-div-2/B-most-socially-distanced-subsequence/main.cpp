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

int t,n;
bool inc;
int A[100005];
vi res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n;
        res.clear();
        loop(i,0,n) {
            cin>>A[i];
        }
        res.pb(A[0]);
        if (A[1]>A[0]) inc=true;
        else inc=false;
        loop(i,1,n-1) {
            if (inc && A[i]<A[i+1]) continue;
            else if (!inc && A[i]>A[i+1]) continue;
            else if (inc) {res.pb(A[i]); inc=false;}
            else {res.pb(A[i]); inc=true;}
        }
        res.pb(A[n-1]);
        cout<<res.size()<<'\n';
        loop(i,0,res.size()) {
            cout<<res[i]<<" ";
        }
    }
    return 0;
}
