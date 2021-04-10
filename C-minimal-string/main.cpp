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
    string s;
    cin>>s;
    string ans;
    stack<char> t;
    map<char,int> lastpos;
    char cc = 'a';
    loop(i,0,25) {
        lastpos['a'+i]=-1;
    }
    lastpos['a'+26]=1000000;
    loop(i,0,s.size()) {
        lastpos[s[i]]=i;
    }
    loop(i,0,s.size()) {
        while(lastpos[cc]<=i) {
            cc++;
        }
        t.push(s[i]);
        while(!t.empty() && t.top()<=cc) {
            ans.push_back(t.top());
            t.pop();
        }
    }
    while(!t.empty()) {
        ans.push_back(t.top());
        t.pop();
    }
    cout<<ans;
    return 0;
}
