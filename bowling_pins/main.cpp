#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back
#define mp make_pair

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)


// trace program
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

// useful constants
#define MOD 1000000007

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

bool ans(int chance,int sz) {
    // trace2(chance,sz);
    if (sz == 0) return chance;
    if (sz == 1) return chance^1;
    bool ret;
    if (chance == 0) {
        ret = false;
        for (int i=0; i<sz/2; i++) {
            ret |= (ans(chance^1,i)^ans(chance^1,sz-i-1));
        }
        return ret;
    }
    else {
        ret = true;
        for (int i=0; i<sz/2; i++) {
            ret &= (ans(chance^1,i)^ans(chance^1,sz-i-1));
        }
        return ret;
    }
    // ll sm = 0;
    // ll tmp = 0;
    // bool parity = false;
    


    // return parity;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    string str;
    cin>>t;
    int tmp;
    multiset<int> groups;
    while(t--) {
        cin>>tmp;
        cin>>str;
        groups.clear();
        int cur = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == 'I') {
                cur++;
            }
            else {
                if (cur>0)
                groups.insert(cur);
                cur = 0;
            }
        }
        if (cur>0) groups.insert(cur);
        // tr(groups,it) cout<<ans(0,*it)<<'\n';
        bool willwin = false;
        bool gaveans = false;
        tr(groups,it) {
            if (ans(0,*it) && (ans(1,*it))) {
                cout<<"WIN\n";
                gaveans = true;
                break;
            }
        }
        if (gaveans) continue;
        tr(groups,it) willwin^=ans(0,*it);
        string ans = (willwin)?"WIN":"LOSE";
        cout<<ans<<'\n';
    }
    // cout<<ans(groups);

    return 0;
}
