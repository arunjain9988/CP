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

int t;
string str;
int ans[1000005];
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int mx;
    cin>>str;
    mx=0;
    memset(ans,0,sizeof ans);
    loop(i,0,str.size()) {
        if (str[i]=='(') {
            st.push(i);
            // mx=i+1;
        }
        else {
            // if (st.empty()) {
            //     break;
            // }
            // st.pop();
            // if (st.empty()) {
            //     mx=i+1;
            // }
            if (!st.empty()) {
                ans[i]=i-st.top()+1;
                st.pop();
            if (i-ans[i]>=0) {
                ans[i]+=ans[i-ans[i]];
            }
                if (ans[i]>mx) {
                    mx=ans[i];
                }
            }
        }
    }
    t=0;
    loop(i,0,str.size()) {
        if (ans[i]==mx) t++;
    }
    if (mx==0) t=1;
    cout<<mx<<" "<<t<<'\n';
    return 0;
}
