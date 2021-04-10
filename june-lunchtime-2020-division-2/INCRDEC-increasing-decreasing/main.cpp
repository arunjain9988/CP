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
set<int> s;
set<int> s2;
int tmp;
bool ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        ans=true;
        cin>>n;
        s.clear();
        s2.clear();
        loop(i,0,n) {
            cin>>tmp;
            if (s.find(tmp) == s.end())
                s.insert(tmp);
            else {
                if (s2.find(tmp) == s2.end() ) s2.insert(tmp);
                else ans=false;
            }
        }
        if (s2.empty()){
            cout<<"YES\n";
            for(auto u:s) {
                cout<<u<<" ";
            }
        }
        else {
            int a = *s.rbegin();
            int b = *s2.rbegin();
            if (!ans || a==b) cout<<"NO"; 
            else {
                cout<<"YES\n";
                for(auto u:s) {
                    cout<<u<<" ";
                }
                for (auto it=s2.rbegin(); it!=s2.rend(); it++) {
                    cout<<*it<<" ";
                }
            }
        } 
                cout<<'\n';
        // if (s.size()<n)
    }
    return 0;
}
