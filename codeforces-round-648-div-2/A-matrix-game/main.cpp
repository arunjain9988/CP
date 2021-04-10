#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, r) for (int i = 0; i < (int)(r); ++i) 
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

int t,n,m,tmp,win;
int rows[50];
int cols[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        memset(rows,0,sizeof rows);
        memset(cols,0,sizeof cols);
        loop(i,n) {
            loop(j,m) {
                cin>>tmp;
                if (tmp==1) {
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        win=0;
        loop(i,n) {
            loop(j,m) {
                if (rows[i]==0 && cols[j]==0) {
                    win^=1;
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        if (win==0) {
            cout<<"Vivek"<<'\n';
        }
        else {
            cout<<"Ashish"<<'\n';
        }
    }
    return 0;
}