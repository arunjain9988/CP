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

int n;
int curpos;
int ans;
int tmp;
int t,k;
int mxrange,mnrange,mxlimit,mnlimit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    floop(p,1,t) {
        cin>>k;
        ans=0;
        cin>>tmp;
        mxrange=4;
        mnrange=1;
        mxlimit=0,mnlimit=0;
        curpos=0;
        loop(i,1,k) {
            // cin>>n;
            // if ((n>tmp && curmax==3) || (n<tmp && curmax==-3)) { ans++; curmax=0; }
            // else if (n>tmp) {
            //     curmax++;
            // }
            // else if (n<tmp) {
            //     curmax--;
            // }
            // tmp=n;
            cin>>n;
            if (n>tmp) {
                curpos++;
            }
            else if (n<tmp) {
                curpos--;
            }
            mxlimit=max(mxlimit,curpos);
            mnlimit=min(mnlimit,curpos);
            if (mxlimit-mnlimit>3) {ans++; curpos=0; mxlimit=0;mnlimit=0;}
            tmp=n;
        }

        cout<<"Case #"<<p<<": "<<ans<<'\n';
    }
    return 0;
}
