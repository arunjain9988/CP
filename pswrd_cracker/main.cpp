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

int dp[2001];

bool canput(string &word,string &password,int idx) {
    // trace3(word,password,idx);
    if (idx+1 < word.size()) {
        return false;
    }
    for (int i=word.size()-1; i>=0; i--) {
        if (password[idx-word.size()+i+1] != word[i]) return false;
    }
    return true;
}

bool solve(vector<string>& words,string &password,int idx) {
    // trace2(password,idx);
    // cout<<password.substr(4,2);
    // if (idx == -1) return true;

    // int cur_has = 0;
    // for (int i=idx; i>=0; i--) {
    //     cur_has = ((cur_has*(ll)10) + 103*password[i])%MOD;
    //     // trace1(cur_has);
    //     if (mp.find(cur_has) != mp.end() && mp[cur_has] == password.substr(i,idx-i+1)) {
    //         if (solve(words,password,i-1,mp)) {
    //             if (idx == password.size()-1) cout<<password.substr(i,idx-i+1);
    //             else cout<<password.substr(i,idx-i+1)<<" ";
    //             return true;
    //         }
    //     }
    // }
    // return false;

    if (idx == -1) return true;
    if (dp[idx] != -1) return dp[idx];

    for (auto s:words) {
        if (canput(s,password,idx)) {
            if (solve(words,password,idx-s.size())) {
                if (idx == password.size()-1) cout<<s;
                else cout<<s<<" ";
                return true;
            }
        }
    }
    return dp[idx] = false;
}

int gethash(string s) {
    int hash = 0;
    for (int i=s.size()-1; i>=0; i--) {
        hash = (((ll)hash*10) + 103*s[i])%MOD;
    }
    return hash;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t,n;
    vector<string> words;
    string password;
    cin>>t;
    // unordered_map<int,string> mp;
    while(t--) {
        cin>>n;
        // mp.clear();
        words.clear();
        loop(i,0,n) {
            cin>>password;
            // mp[gethash(password)] = password;
            // trace1(gethash(password));
            words.pb(password);
        }
        memset(dp,-1,sizeof(dp));
        cin>>password;
        bool poss = solve(words,password,password.size()-1);
        if (!poss) cout<<"WRONG PASSWORD\n";
        else cout<<"\n";
    }

    return 0;
}
