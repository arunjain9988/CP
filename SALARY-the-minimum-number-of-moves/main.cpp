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

int t,n,w,mn,sm;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    int ans;
    while(t--) {
        ans=0;
        cin>>n;
        sm=0;
        mn=100000;
        loop(i,0,n) {
            cin>>w;
            mn=min(mn,w);
            sm+=w;
        }
        ans = sm-n*mn;
        // priority_queue<int> pq;
        // loop(i,0,n) {
        //     cin>>w;
        //     mn = min(mn,w);
        //     pq.push(w);
        // }
        // while(w=pq.top(),w!=mn) {
        //     pq.pop();
        //     ans++;
        //     pq.push(w-1);
        // }
        cout<<ans<<'\n';
    }
    return 0;
}
