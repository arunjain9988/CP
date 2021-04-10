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
string str;
stack<char> st;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    map<char,int> pr = {{'+',0},{'-',1},{'*',2},{'/',3},{'^',4},{'(',-1},{')',-1}};
    cin>>t;
    while(t--) {
        string res;
        cin>>str;
        loop(i,0,str.size()) {
            if (str[i]-'a'>=0 && str[i]-'a'<=25) {
                res.push_back(str[i]);
            }
            else if (str[i]=='(') {
                st.push(str[i]);
            }
            else if (str[i]==')') {
                while(st.top()!='(') {
                    res.pb(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if (pr.find(str[i])!=pr.end()) {
                int p=pr.find(str[i])->second;
                while(!st.empty() && p<=pr.find(st.top())->second) {
                    res.pb(st.top());
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        while(!st.empty()) {
            res.pb(st.top());
            st.pop();
        }
        cout<<res<<'\n';
    }
    return 0;
}
