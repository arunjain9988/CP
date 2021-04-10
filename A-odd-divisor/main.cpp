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
    cin>>t;
    int n,m;
    int mem1[200005];
    int conv;
    priority_queue<int> conv1;
    priority_queue<int> conv2;
    while(t--) {
        cin>>n>>m;
        while(conv1.size()) conv1.pop();
        while(conv2.size()) conv2.pop();
        int s=0;
        for (int i=0; i<n; i++) {
            cin>>mem1[i];
            s+= mem1[i];
        }
        for (int i=0; i<n; i++) {
            cin>>conv;
            if (conv==1) {
                conv1.push(mem1[i]);
            }
            else {
                conv2.push(mem1[i]);
            }
        }
        if (m>s) {
            cout<<"-1\n";
            continue;
        }
        int curm = 0;
        int curv = 0;
        while(curm < m && conv1.size() && conv2.size()) {
            if (conv1.size() == 1) {
                if (conv1.top() + curm >= m) {
                    curv++;
                    break;
                }
                else {
                    curv += 2;
                    curm += conv2.top();
                    conv2.pop();
                    continue; 
                }
            }
            else if (curm + conv1.top() >= m ) {
                curm += conv1.top();
                conv1.pop();
                curv++;
                break;
            }
            int ftop = conv1.top();
            conv1.pop();
            int stop = conv1.top();
            conv1.pop();
            if (ftop+stop >= conv2.top()) {
                curv +=2;
                curm += (ftop+stop);
                continue;
            }
            else {
                conv1.push(ftop);
                conv2.push(stop);
                curv += 2;
                curm += conv2.top();
                conv2.pop();
            }
        }
        while(curm<m && conv1.size()) {
            curm+= conv1.top();
            curv++;
            conv1.pop();
        }
        while(curm<m && conv2.size()) {
            curm+= conv2.top();
            curv+=2;
            conv2.pop();
        }
        cout<<curv<<'\n';
    }
    return 0;
}
