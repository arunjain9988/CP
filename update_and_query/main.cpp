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

const int N=200005;

int A[N];
ii ST[N*4+10];

void build(int start,int end,int idx) {
    if (start == end){
        ST[idx].first = ST[idx].second = A[start];
        return;
    }
    int mid = (start+end)/2;
    build(start,mid,idx*2);
    build(mid+1,end,idx*2+1);
    ST[idx].first = max(ST[idx*2].first,ST[idx*2+1].first);
    ST[idx].second = min(ST[idx*2].second,ST[idx*2+1].second);
}

void update(int start,int end,int idx,int pos,int val){
    if (start>pos || end<pos) return;
    if (start == pos && end == pos) {
        ST[idx].first = ST[idx].second = val;
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,idx*2,pos,val);
    update(mid+1,end,idx*2+1,pos,val);
    ST[idx].first = max(ST[idx*2].first,ST[idx*2+1].first);
    ST[idx].second = min(ST[idx*2].second,ST[idx*2+1].second);
}

ii query(int start,int end,int idx,int qstart,int qend) {
    if (qstart > end || qend < start) {
        return mp(INT_MIN,INT_MAX);
    }
    if (start >= qstart && end <= qend) {
        return ST[idx];
    }
    int mid = (start+end)/2;
    ii a = query(start,mid,idx*2,qstart,qend);
    ii b = query(mid+1,end,idx*2+1,qstart,qend);
    return mp(max(a.first,b.first),min(a.second,b.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    loop(i,n) cin>>A[i];
    build(0,n-1,1);
    // trace2(A[66132],A[66133]);
    // int q;
    int a,b;
    char type;
    loop(i,m) {
        cin>>type>>a>>b;
        if (type == 'U'){
            update(0,n-1,1,a-1,b);
            A[a-1] = b;
        }
        else {
            int lo = a-1;
            int hi = n-1;
            int ans = -1;
            int mnnn = INT_MAX;
            while(lo<=hi) {
                int mid = (lo+hi)/2;
                ii q = query(0,n-1,1,a-1,mid);
                // cout<<q.first<<" "<<q.second<<" "<<mid<<"tr\n";
                if ((q.first <= A[a-1]+b) && (q.second >= A[a-1]-b)) {
                    lo = mid+1;
                    ans = mid;
                    // cout<<"lo"<<lo<<endl;
                    mnnn = max(A[a-1]-q.second,q.first-A[a-1]);
                    // trace4(mnnn,q.first,q.second,A[a-1]);
                }
                else{
                    hi = mid-1;
                }
            }
            if (ans == -1 ) cout<<"-1 -1\n";
            else { cout<<ans-a+2<<" "<<mnnn<<endl; }
        }
    }
    return 0;
}
