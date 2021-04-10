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

int tmp;
int row,col;
int ans1[60];
int ans0[60];
int t,n,m;
ll ans;
int M[31][31];
int main() {
    int count0,count1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        ans=0;
        cin>>n>>m;
        loop(i,0,n) {
            loop(j,0,m) {
                cin>>M[i][j];
            }
        }
        loop(i,0,m+n-1) {
            count0=0,count1=0;
            if (i>=m) {
                row=i-m+1;
                col=i-row;
            }
            else {
                row=0;
                col=i-row;
            }
            while(row<n && col>=0) {
                if (M[row][col]==1) {
                    count1++;
                }
                else count0++;
                row+=1;col-=1;
            }
            ans1[i]=count1;
            ans0[i]=count0;
        }
        loop(i,0,(m+n-1)/2) {
            tmp=m+n-i-2;
            ans+=min(ans1[i]+ans1[tmp],ans0[i]+ans0[tmp]);
            // cout<<ans1[i]<<' '<<ans0[i]<<'\n';
        }
        cout<<ans<<'\n';
        // loop(i,0,m+n-1) {
        //     cout<<ans1[i]<<' ';
        // }
        // cout<<endl;
        // loop(i,0,m+n-1) {
        //     cout<<ans0[i]<<' ';
        // }
        // cout<<endl;
    }
    return 0;
}
