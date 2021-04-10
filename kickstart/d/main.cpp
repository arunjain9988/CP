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
#define MOD 1000000007
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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};

int t,n;
vector<vector<int> > subsets;


void pre(int cur,int mx,vector<int> &cur_subset) {
    if (cur == mx) {
        subsets.push_back(cur_subset);
        return;
    }
    cur_subset.push_back(cur);
    pre(cur+1,mx,cur_subset);
    cur_subset.pop_back();
    pre(cur+1,mx,cur_subset);
}

vector<vector<int> > input;
vector<vector<int> > cost;
vector<int> rowsum;
vector<int> colsum;
vector<int> rowswaste;
vector<int> colswaste;
vector<ii> lostpositions;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        if (n>4) return 0;
        rowsum = vector<int>(n+1,0);
        colsum = vector<int>(n+1,0);
        lostpositions.clear();
        input = vector<vector<int> >(n+1,vector<int>(n+1,0));
        cost = vector<vector<int> >(n+1,vector<int>(n+1,0));
        floop(i,1,n) {
            floop(j,1,n) {
                cin>>input[i][j];
                if (input[i][j] == -1) {
                    rowsum[i]++;
                    colsum[j]++;
                    lostpositions.pb({i,j});
                }
            }
        }

        floop(i,1,n) {
            floop(j,1,n) {
                cin>>cost[i][j];
            }
        }

        floop(i,1,n) {
            cin>>rowswaste[i];
        }
        floop(i,1,n) {
            cin>>colswaste[i];
        }

        ll ans = (1ll)<<40;
        vector<int> tmp;
        pre(0,lostpositions.size(),tmp);
        for (vector<int> u:subsets) {
            ll cur_ans = 0;
            for (int p:u) {
                cur_ans += cost[lostpositions[p].first][lostpositions[p].second];
                rowsum[lostpositions[p].first]--;
                colsum[lostpositions[p].second]--;
            }
            bool is_valid_now = true;
            // s.clear();
            // set<pair<int,ii> > s;
            for(int pp=1; pp<=50; pp++) {
                for (int i=1; i<=n; i++) {
                    if (rowsum[i] == 1) {
                        for (int j=1; j<=n; j++) {
                            if (input[i][j] == -1) {
                                // input[i][j] = 1;
                                colsum[j]--;
                            }
                        }
                    }
                }
                for (int i=1; i<=n; i++) {
                    if (rowsum[i]>0 || colsum[i] > 0) is_valid_now = false;
                }
            }
            if (is_valid_now) ans = min(ans,cur_ans);

        }
        cout<<ans<<'\n';
    }
    return 0;
}
