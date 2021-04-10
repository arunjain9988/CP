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

int t,n,x;
ll sm;
int A[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t; 
    while(t--) {
        cin>>n>>x;
        sm=0;
        loop(i,0,n) {
            cin>>A[i];
            sm+=A[i];
        }
        if (sm%x==0) {
            int i=0;
            while(i<n && A[i]%x==0) i++;
            int j=n-1;
            while(j>=0 && A[j]%x==0) j--;
            if (i>j) { cout<<-1<<'\n'; continue;}
            if (i>((n-1)-j)) {
                cout<<j<<'\n';
            }
            else {
                cout<<n-i-1<<'\n';
            }
            // cout<<j-i<<'\n'; continue;
        }
        else {
            cout<<n<<'\n';
        }
        // sm = accumulate(A,A+n,0);
    }
    return 0;
}
