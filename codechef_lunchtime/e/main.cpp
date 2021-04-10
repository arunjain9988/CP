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


// trace program
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl

// useful constants
#define MOD 998244353
#define EPS (double)1e-6

using namespace std;


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

int t;
int n,m,c;
vector<vii> clubs;
vector<int> ar;
int ST[4*100005];
int lazy[4*100005];

void seginit(int st,int ed,int idx) {
    if (st == ed) {
        ST[idx] = 0;
        return;
    }
    int mid = (st+ed)/2;
    seginit(st,mid,idx*2);
    seginit(mid+1,ed,idx*2+1);
}

void upd(int st,int ed,int idx,int updst,int upded) {
    if (lazy[idx]) {
        ST[idx] = 1;
        if (st != ed) {
            lazy[idx*2] = 1;
            lazy[idx*2+1] = 1;
            lazy[idx] = 0;
        }
    }
    if (st>upded || ed <updst) return;
    if (st>=updst && ed <= upded) {
        lazy[idx] = 1;
        return;
    }
    int mid = (st+ed)/2;
    upd(st,mid,idx*2,updst,upded);
    upd(mid+1,ed,idx*2+1,updst,upded);
}

int query(int st,int ed,int idx,int qst,int qed) {
    if (lazy[idx]) {
        ST[idx] = 1;
        if (st != ed) {
            lazy[idx*2] = 1;
            lazy[idx*2+1] = 1;
            lazy[idx] = 0;
        }
    }
    if (st>qed || ed <qst) return 0;
    if (st>=qst && ed <= qed) {
        return ST[idx];
    }
    int mid = (st+ed)/2;
    return query(st,mid,idx*2,qst,qed) || query(mid+1,ed,idx*2+1,qst,qed);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    int x;
    int l,r;
    set<int> tmp;
    unordered_map<int,int,custom_hash> mp;
    while(t--) {
        clubs.clear();
        tmp.clear();
        cin>>c>>n>>m;
        clubs = vector<vii>(c,vector<ii>());
        loop(i,c) {
            cin>>x;
            loop(j,x) {
                cin>>l>>r;
                clubs[i].pb({l,r});
                tmp.insert(l);
                tmp.insert(r);
            }
        }
        // sort(all(tmp));
        int i=0;
        // loop(i,tmp.size()) {
        //     mp[tmp[i]] = i+1;
        // }
        tr(tmp,it) {
            mp[*it] = ++i;
        }
        ar = vi(tmp.size()+5,0);
        ll ans=1;
        for (int i=0; i<clubs.size(); i++) {
            bool canbe = true;
            for (ii &u:clubs[i]) {
                for (int k=mp[u.first]; k<=mp[u.second]; k++) {
                    if (ar[k] == 1) {
                        canbe = false;
                    }
                    ar[k] = 1;
                }
            }
            if (canbe) ans = (ans*m)%MOD;
        }
        // for (int i=1; i<=n; i++) {
        //     if (ar[i] == 0) {
        //         ans = (ans*m)%MOD;
        //         break;
        //     }
        // }
        auto p = tmp.end();
        p--;
        // if (*p < n) (ans = (ans*m)%MOD);
        cout<<ans<<'\n';
    }   
    return 0;
}
