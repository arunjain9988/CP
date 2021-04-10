#include <bits/stdc++.h>
using namespace std;

// 💻 Here in brute-force.cpp, write a straighforward, brute-force solution that will be used to generate correct test outputs from inputs. 💻
// 💡 Then, press Alt+F9 to have ICIE automatically test your solution on thousands of tests! 💡
// 😕 Just write O(n^6), O(2^n) code; it doesn't need to be fast, but correct. 😕

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

int n,q;
int a,b,c;
ll k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n>>q;
    ll H[n+1];
    ll A[n+1];
    loop(i,1,n+1) {
        cin>>H[i];
    }
    loop(i,1,n+1) {
        cin>>A[i];
    }
    loop(i,0,q) {
        cin>>a;
        if (a==1) {
            cin>>b>>k;
            A[b]=k;
        }
        else {
            cin>>b>>c;
            if (c<=b) {
                ll ans=A[c];
                ll cur = c;
                c++;
                while(c<=b) {
                    if (H[c]>H[cur]) {
                        ans += A[c];
                        cur = c;
                    }
                    c++;
                }
                if (cur == b) {
                    cout<<ans<<'\n';
                }
                else {
                    cout<<-1<<'\n';
                }
            }
            else // c>b 
            {

                ll ans=A[c];
                ll cur = c;
                c--;
                while(c>=b) {
                    if (H[c]>H[cur]) {
                        ans += A[c];
                        cur = c;
                    }
                    c--;
                }
                if (cur == b) {
                    cout<<ans<<'\n';
                }
                else {
                    cout<<-1<<'\n';
                }
            }
        }
    }
    return 0;
    
}
