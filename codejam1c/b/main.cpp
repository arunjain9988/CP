#include <bits/stdc++.h>  // This will work only for g++ compiler.


#define loop(i, r) for (int i = (int)(0); i < (int)(r); ++i)
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

// useful constants
#define MOD 1000000007
#define EPS (double)1e-6

using namespace std;


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1) {
        cerr<<name<<" : " <<arg1<<std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* comma = strchr(names + 1, ','); 
        cerr.write(names, comma - names) << " : " << arg1 <<" | "; __f(comma+1,args...);
    }
#else
#define trace(...)
#endif

// Important header files   ordered set
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional> // for less

// using namespace __gnu_pbds;
// template <typename T>
// using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

// Custom Hash for unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};

ll t;
string input;

string add1(const string &s) {
    ll ii = stoi(s);
    ii++;
    return to_string(ii);
}


string sub1(const string &s) {
    ll ii = stoi(s);
    ii--;
    return to_string(ii);
}

ll isgreater(const string &a,const string &b) {
    ll ai = stoi(a);
    ll bi = stoi(b);
    if (ai>bi) return 1;
    else if (ai==bi) return 0;
    else return -1;
}

bool check(string s,ll idx,string tocheck,bool strict) {
    // trace(s,idx,tocheck,strict);
    if ( (s.size()-idx == 0) && strict == 0) return true;
    if (s.size()-idx < tocheck.size()) return false;
    // if (s[idx] == '0') return false;
    if (strict == 1) {
        string now = s.substr(idx,tocheck.size());
        if (isgreater(now,tocheck) == 1) return false; // greater
        if (isgreater(now,tocheck) == 0)  return check(s,idx+tocheck.size(),add1(tocheck),1); // equals
        else return check(s,idx+tocheck.size(),add1(tocheck),0); // lesser
    }
    else {
        return check(s,idx+tocheck.size(),add1(tocheck),0);
    }
}

bool valid(string s,int idx,string tocheck) {
    if (s.size()-idx == 0) return true;
    if (s.size()-idx < tocheck.size()) return false;
    if (s.substr(idx,tocheck.size()) == tocheck) {
        return valid(s,idx+tocheck.size(),add1(tocheck));
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    ll _t=t;
    while(t--) {
        string ans;
        ans.clear();
        cin>>input;
        if (input.size() <= 18) {
            string a1;
            bool done = false;
            // cerr<<'n';
            while(!done) {
                input = add1(input);
                for (ll i=input.size()/2; i>=1; i--) {
                    if (valid(input,i,add1(input.substr(0,i)))){
                        done = true;
                        a1 = input;
                        break;
                    }
                }
            }
            cout<<"Case #"<<_t-t<<": "<<a1<<'\n';
        }
        else {
                
            bool done = false;
            for (ll i=input.size()/2; i>=1; i--) {
                string cur = input.substr(0,i);
                bool found = check(input,i,add1(cur),1);
                if (found == true){
                    done = true;
                    ans = cur;
                    break;
                }
                else {
                    cur = add1(cur);
                    bool found = check(input,i,add1(cur),0);
                    // trace(cur,i,found);
                    if (found == true){
                        done = true;
                        ans = cur;
                        break;
                    }
                }
            }
            if (done == false) {
                // cerr<<"false";
                for (ll i=1; i<=input.size()/2; i++) {
                    string nines = string(i,'9');
                    for (ll j=0; j<20; j++) {
                        string cur = input.substr(0,i);
                        if (isgreater(nines,cur) == 1) {
                            bool found = check(input,i,add1(nines),0);
                            if (found) {
                                done = true;
                                ans = nines;
                            }
                        }
                        else {
                            break;
                        }
                        nines = sub1(nines);
                    }
                    if (done == true) break;
                    
                }
            }
            if (done==false) {
                // cerr<<"false";
                string now = "1" + string(input.size(),'0');
                input = now;
                for (ll i=input.size()/2; i>=1; i--) {
                    string cur = input.substr(0,i);
                    bool found = check(input,i,add1(cur),1);
                    if (found == true){
                        done = true;
                        ans = cur;
                        break;
                    }
                    else {
                        cur = add1(cur);
                        bool found = check(input,i,add1(cur),0);
                        // trace(cur,i,found);
                        if (found == true){
                            done = true;
                            ans = cur;
                            break;
                        }
                    }
                }
            }

            // cout<<ans<<'\n';
            ll c = stoi(ans);
            while(ans.size()<input.size()){
                c++;
                ans.append(to_string(c));
            }
            cout<<"Case #"<<_t-t<<": "<<ans<<'\n';
        }
    }
    return 0;
}
