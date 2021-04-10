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
int tmp;
int A[1000001];
int mx;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    int curr;
    while(t--) {
        cin>>n;
        loop(i,0,n) {
            cin>>tmp;
            A[i]=tmp;
        }
        int _i;
        for(_i=n-1;_i>=1;_i--) {
            if (A[_i]>A[_i-1]) break;
        }
        if (_i==0) {
            cout<<-1<<'\n';continue;
        }
        mx = 1e6;
        curr=-1;
        //Need to replace i-1th value
        floop(j,_i,n-1) {
            if (A[j]>A[_i-1]) {
                mx=min(mx,A[j]);
                curr=j;
            }
        }
        swap(A[_i-1],A[curr]);
        sort(A+_i,A+n);
        loop(i,0,n) {
            cout<<A[i];
        }
        cout<<endl;
    }
    return 0;
}
