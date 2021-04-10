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

ll t,n;
ll tmp,tmp2;
ll mx,mn;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        bool donef=0,dones=0;
        cin>>n;
        cin>>mx;
        mn=mx;
        loop(i,1,n) {
            cin>>tmp;
            if (dones) continue;
            else if (donef) {
                if (tmp<mx) dones=true;
            }
            else if (tmp>mn) {
                donef=true;
            }
            mx=max(tmp,mx);
            mn=min(tmp,mn);
        }
        if (dones) {cout<<"YES"<<'\n'; cout<<mn<<" "<<mx<<" "<<tmp;}
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}