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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t;
    int a,b,k;
    int boysIn[200005];
    int girlsIn[200005];
    // vii pairs;
    cin>>t;
    int pa[200005],pb[200005];
    while(t--) {
        // pairs.clear();
        memset(boysIn,0,sizeof(boysIn));
        memset(girlsIn,0,sizeof(girlsIn));
        cin>>a>>b>>k;
        for (int i=0; i<k; i++) {
            cin>>pa[i];
            boysIn[pa[i]]++;
        }
        for (int i=0; i<k; i++) {
            cin>>pb[i];
            girlsIn[pb[i]]++;
        }
        ll ans=0;
        for (int i=0; i<k; i++) {
            ans += (k-i)-boysIn[pa[i]]-girlsIn[pb[i]]+1;
            boysIn[pa[i]]--;
            girlsIn[pb[i]]--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
