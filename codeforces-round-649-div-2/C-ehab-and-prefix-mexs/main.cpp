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
int idx;
int A[100005];
int pos[100005];
int res[100005];
set<int> remain;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    memset(pos,-1,(sizeof(int))*n);
    loop(i,0,n) {
        cin>>A[i];
        pos[A[i]]=i;
    }
    idx=0;
    loop(i,0,n) {
        while (pos[idx]>=i) {
            remain.insert(idx);
            idx++;
        }
        if (!remain.empty() && *remain.begin()<A[i]) {
            res[i]=*remain.begin();
            remain.erase(remain.begin());
        }
        else {
            res[i]=idx++;
        }
        // else {

        // }
        cout<<res[i]<<" ";
    }
    return 0;
}
