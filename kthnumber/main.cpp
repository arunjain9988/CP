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

// typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

const int N = 100005;

int A[N];
int ST[4*N+5];

void update(int start,int end,int idx,int val) {
    if (start>val || end < val) return;
    if (start == end){
        ST[idx]++;
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,idx*2,val);
    update(mid+1,end,idx*2+1,val);
    ST[idx] = ST[idx*2]+ST[idx*2+1];
}

int query(int start,int end,int idx,int k) {
    if (start == end) return start;
    int mid = (start+end)/2;
    int cnt = ST[idx*2];
    if (cnt>=k) return query(start,mid,idx*2,k);
    return query(mid+1,end,idx*2+1,k-cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<int> permute;
    loop(i,n){
        cin>>A[i];
        permute.pb(i);
    }
    sort(all(permute),[](const int a,const int b){ return A[a]>A[b];});
    vector<pair<ii,int> > queries;
    int t1,t2;
    int ans[N];
    loop(i,q){
        cin>>t1>>t2;
        queries.pb(mp(mp(t1,t2),i));
    }
    sort(all(queries),greater<pair<ii,int> >());
    int cur = 0;
    // loop(i,30) cout<<ST[i]<<"\n";
    loop(i,q) {
        while(cur < permute.size() && A[permute[cur]] >= queries[i].first.first) {
            update(0,100000,1,permute[cur]);
            // cout<<A[permute[cur]]<<'\n';
            cur++;
        }
        ans[queries[i].second] = A[query(0,100000,1,queries[i].first.second)];
        // cout<<"ans"<<A[query(0,100000,1,queries[i].second)]<<'\n';
    }
    loop(i,queries.size()) cout<<ans[i]<<"\n";

    return 0;
}
