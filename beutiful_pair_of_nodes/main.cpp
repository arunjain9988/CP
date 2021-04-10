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
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less

using namespace __gnu_pbds;
template <typename T>
using indexed_set =  tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


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
const int N = 100005;
int A[N];
int B[N];
map<int,int> real_to_compress;
vector<int> Tree[N];

indexed_set<ii> bit[N];

void add(int a,int b) {
    while(a<N) {
        bit[a].insert(mp(b,a));
        a += (a&-a);
    }
}


void rmv(int a,int b) {
    while(a<N) {
        bit[a].erase(mp(b,a));
        // cout<<*bit[a].find(b);
        a += (a&-a);
    }
}

int query(int a,int b) {
    int rs=0;
    while(a>=1) {
        // for (int v:bit[a]) cerr<<v<<' ';
        rs += bit[a].order_of_key(mp(b,0));
        a -= (a&-a);
    }
    return rs;
}

int dfs(int node,int par) {
    // trace2(node,par);
    // int ret = 0;
    // trace2(real_to_compress[A[node-1]],B[node-1]);
    add(real_to_compress[A[node-1]],B[node-1]);
    int rtt = query(real_to_compress[A[node-1]]-1,B[node-1]);
    // trace1(rtt);
    // int rtt = 0;
    for (int u:Tree[node]) {
        if (u==par) continue;
        rtt += (dfs(u,node));
    }
    rmv(real_to_compress[A[node-1]],B[node-1]);
    return rtt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int n;
    int a,b;
    cin>>n;
    loop(i,n-1){
        cin>>a>>b;
        Tree[a].pb(b);
        Tree[b].pb(a);
    } 
    vector<int> permute;
    loop(i,n) {
        cin>>A[i];
        permute.pb(i);
    }
    sort(all(permute),[](const int &a,const int &b) { return A[a]<A[b]; });
    loop(i,permute.size()) {
        real_to_compress[A[permute[i]]] = i+1;
    }
    loop(i,n) {
        cin>>B[i];
    }

    cout<<dfs(1,-1);
    return 0;
}
