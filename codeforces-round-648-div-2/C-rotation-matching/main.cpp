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

int n,ans[200005];
pair<int, int> a[200005],b[200005];
int res;
int tmp;
int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    memset(ans,0,sizeof ans);
    cin>>n;
    loop(i,0,n) {
        cin>>x;
        a[i]={x,i};
    }
    loop(i,0,n) {
        cin>>x;
        b[i]={x,i};
    }
    sort(a,a+n);
    sort(b,b+n);

    loop(i,0,n) {
        tmp=a[i].second-b[i].second;
        if (tmp<0) {
            ans[n+tmp]++;
            res=max(res,ans[n+tmp]);
        }
        else {
            ans[tmp]++;
            res=max(res,ans[tmp]);
        }
    }
    cout<<res;
    return 0;
}