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

int eulerphi[500005];
int A[1000001];
int bit[1000001];
int F[500005];

void update(int idx,int val,int n) {
    while(idx<=n) {
        bit[idx] = (bit[idx] + val)%MOD;
        idx += (idx&-idx);
    }
}

int query(int idx) {
    int ret = 0;
    while(idx>=1) {
        ret = (ret+bit[idx])%MOD;
        idx -= (idx&-idx);
    }
    return ret;
}


void pre() {
    for (int i=1; i<=500004; i++) {
        eulerphi[i] = i;
    }
    for (int i=2; i<=500004; i++) {
        if (eulerphi[i] == i) {
            for (int j=i; j<=500004; j+=i) {
                eulerphi[j] = (eulerphi[j]*(ll)(i-1))/i;
            }
        }
    }

    for(int q=1; q<=500004; q++) {
        int s=0;
        int i=1;
        for (; i*i<q; i++) {
            if (q%i==0) {
                s = (s + (i*(ll)eulerphi[q/i]))%MOD;
                s = (s + (q/i)*(ll)eulerphi[i])%MOD;
            }
        }
        if (q%(i*i)==0) s = (s + (i*(ll)eulerphi[q/i]))%MOD;
        F[q] = s;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    pre();
    int n,q;
    cin>>n;
    loop(pp,n) {
        cin>>A[pp+1];
        update(pp+1,F[A[pp+1]],n);
    }
    cin>>q;
    char type;
    int x,y;
    loop(_i,q) {
        cin>>type>>x>>y;
        if (type == 'C'){
            cout<<(((query(y)-(ll)query(x-1))%MOD)+MOD)%MOD<<'\n';
        }
        else {
            update(x,(((ll)F[y]-F[A[x]]))%MOD,n);
            A[x] = y;
        }
    }
    // for (int i=1; i<=n; i++) cout<<query(i)<<' ';
    // cout<<F[43536]<<' '<<F[54343];
    return 0;
}
