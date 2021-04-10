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
int A[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    int n;
    while(t--) {
        cin>>n;
        loop(i,0,n) {
            cin>>A[i];
        }
        // int mx = 0;
        // for (int i=0; i<n-1; i++) {
        //     mx=max(mx,A[i]);
        // }
        // if (A[n-1] > mx) cout<<
        // int mx = A[n-1];
        int mx= A[n-1];
        bool done = false;
        for (int i=n-2; i>=0; i--) {
            // mx = max(mx,A[i]);
            // if (A[i] > A[n-1]){
            //     cout<<"No\n";
            //     break;
            // }
            if (A[i] < A[n-1]) done = true;
            if (A[i] < mx) done = true;
            if (A[i] >=mx ) done = false;
            mx = max(mx,A[i]);
            // if (i==0 && done) cout<<"Yes\n";
            // else if (i==0) cout<<"No\n";
        }
        if (done) cout<<"Yes\n";
        else cout<<"No\n";
    }    
    return 0;
}
