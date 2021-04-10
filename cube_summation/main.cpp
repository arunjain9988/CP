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

const int N = 105;

ll bit[N][N][N];

void update(ll val,int x,int y,int z,int n) {
    for (int i=x; i<=n; i+=(i&-i)){
        for (int j=y; j<=n; j+=(j&-j)) {
            for (int k=z; k<=n; k+=(k&-k)) {
                bit[i][j][k] += val;
            }
        }
    }
    // if(x<=n && y<=n && z<=n) {
    //     bit[x][y][z] += val;
    //     update(val,x+(x&-x),y,z,n);
    //     update(val,x,y+(y&-y),z,n);
    //     update(val,x,y,z+(z&-z),n);
        // x+=(x&-x);
        // y+=(y&-y);
        // z+=(z&-z);
    // }
    // for (int i = x; i < n; i = i | (i + 1))
    //         for (int j = y; j < n; j = j | (j + 1))
    //             for (int k = z; k < n; k = k | (k + 1))
    //                  bit[i][j][k] += val;
                  
    // if (x>n || y>n || z>n) return;
    // int cp_x=x,cp_y=y,cp_z=z;
    // while(x<=n) {
    //     bit[x][y][z] += val;
    //     x+=(x&-x);
    // }
    // x = cp_x;
    // y = (y&-y);
    // while(y<=n) {
    //     bit[x][y][z] += val;
    //     y+=(y&-y);
    // }
    // // y = cp_y+(cp_y&-cp_y);
    // y=cp_y;
    // z=z&-z;
    // while(z<=n) {
    //     bit[x][y][z] += val;
    //     z+=(z&-z);
    // }
    // update(val,cp_x+cp_x&-cp_x,cp_y+cp_y&-cp_y,cp_z,n);
    // update(val,cp_x+cp_x&-cp_x,cp_y,cp_z+cp_z&-cp_z,n);
    // update(val,cp_x,cp_y+cp_y&-cp_y,cp_z+cp_z&-cp_z,n);
}

ll query(int x,int y,int z) {
    ll smm=0;
    // for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    //         for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
    //                for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
    //                   smm += bit[i][j][k];
    for (int i=x; i>=1; i-=(i&-i)) {
        for (int j=y; j>=1; j-=(j&-j)) {
            for (int k=z; k>=1; k-=(k&-k)) {
                smm+=bit[i][j][k];
            }
        }
    }
    return smm;
    // ll ans = 0;
    // while(x>=1 && y>=1 && z>=1) {
    //     ans += (bit[x][y][z]);
    //     x -= (x&-x);
    //     y-=(y&-y);
    //     z-=(z&-z);
    // }
    // return ans;
}

ll rangeSum(int x0, int y0,int z0,int x,int y,int z ) {
    if (x<x0 || y<y0 || z<z0) return 0;
    ll  value1 = query(x,y,z)- query(x0-1,y,z)  - query(x,y0-1,z) + query(x0-1,y0-1,z);
    ll value2 = query(x,y,z0-1) - query(x0-1,y,z0-1) - query(x,y0-1,z0-1)  + query(x0-1,y0-1,z0-1);
    return value1 - value2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    int n,m;
    int x,y,z,x2,y2,z2;
    ll val;
    int qr;
    // cin>>t;
    t=1;
    // vector<ll> asss;
    ll ttt;
    while(t--) {
        cin>>n>>m;
        n++;
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++) {
                for (int k=0; k<=n; k++) {
                    bit[i][j][k] = 0;
                }
            }
        }
        // memset(bit,0,sizeof(bit));
        int _m=m;
        ll total = 0;
        while(m--) {
            cin>>qr;
            if (qr == 1){
                cin>>x>>y>>z>>val;
                // ttt =(val-rangeSum(x+1,y+1,z+1,x+1,y+1,z+1));
                total+=val;
                update(val,x+1,y+1,z+1,n);
            }
            else {
                cin>>x>>y>>z>>x2>>y2>>z2;
                // x--,y--,z--,x2--,y2--,z2--;
                cout<<total-(rangeSum(x+1,y+1,z+1,x2+1,y2+1,z2+1))<<'\n';
                // cout<<asss[asss.size()-1]<<endl;
            }
        }
    }
    // ll ttt;
    // for (ll a:asss) {
        // cin>>ttt;
        // if (ttt!=a) cout<<a<<" "<<ttt<<endl;
    // }
    return 0;
}
