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
int f;
int k;
int p;
int sel;

vector<unsigned long long> ans;
unsigned long long tmp;
set<unsigned long long> dp[70];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    // memset(dp,0,sizeof dp);
    loop(i,0,n) {
        cin>>tmp;
        p = log2(tmp);
        dp[p].insert(tmp);
    }
    for(f=70; f>=0; f--) {
        if (dp[f].size()>0) {
            break;
        }
    }
    // auto z = dp[f].end();
    // z--;



    tr(dp[f],it) {
        ans.pb(*it);
    }
    unsigned long long rr=2;
    set<unsigned long long> remain;
    while(rr>0 && f>0) {
        do {
            remain.clear();
            f--;
            set_difference(all(dp[f]),all(dp[f+1]),std::inserter(remain, remain.end()));
        }
        while(remain.size()>rr && f>0);
        ans.pb(f);
        rr -=remain.size();
    }

    unsigned long long s=0;
    loop(i,0,ans.size()) {
        s+=pow(2,ans[i]);
    }
    cout<<s<<'\n';


    // sel=dp[f].size();
    // while(sel<k) {
        
    // }
    return 0;
}