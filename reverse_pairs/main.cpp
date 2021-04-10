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

class Solution {
    
public:
    int st[50001*4+10];
    
    void update(int start,int end,int idx,int updidx) {
        if (start>updidx || end<updidx) return;
        if (start == end){
            st[idx]++;
            // cout<<start<<'u'<<endl;
            return;
        }
        int mid = (start+end)/2;
        update(start,mid,idx*2,updidx);
        update(mid+1,end,idx*2+1,updidx);
        st[idx] = st[idx*2]+st[idx*2+1];
    }
    
    int query(int start,int end,int qstart,int qend,int idx) {
        // trace5(start,end,qstart,qend,idx);
        if (qstart > end || qend < start) return 0;
        if (start >= qstart && end <= qend) {
            // cout<<" idx "<<qstart<<" "<<qend<<" "<<start<<" "<<end<<" "<<idx<<" "<<st[idx]<<endl;
            return st[idx];
        }
        int mid = (start+end)/2;
        int l = query(start,mid,qstart,qend,idx*2);
        int r =  query(mid+1,end,qstart,qend,idx*2+1);
        return l+r;
    }
    
    
    int reversePairs(vector<int>& nums) {
        memset(st,0,sizeof(st));
        vector<int > compressions;
        for (int i=0;i<nums.size(); i++) {
            compressions.push_back(nums[i]);
            compressions.push_back(nums[i]*2);
        }
        sort(compressions.begin(),compressions.end());
        int cur = 0;
        // compressions[0].second = ++cur;
        map<int,int> mapping;
        mapping[compressions[0]] = ++cur;
        for (int i=1; i<compressions.size(); i++){
            if (compressions[i] == compressions[i-1]){
                mapping[compressions[i]] = cur;
            }           
            else mapping[compressions[i]] = ++cur;
        }
        int ans = 0;
        for (int u:nums) {
            int l = mapping[2*u];
            l++;
            ans += (query(1,cur,l,cur,1));
            // cout<<l<<" "<<mapping[u]<<endl;
            // trace4(u,l,mapping[2*u],mapping[u]);
            // trace3(mapping[u],mapping[u*2],ans);
            update(1,cur,1,mapping[u]);
            // for (int i=0; i<25; i++) {
            //     cout<<i<<" "<<st[i]<<endl;
            // }
        }
        return ans;   
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    Solution s;
    int A[] = {1,3,2,3,1,1000000000,5,8,5456};
    vector<int> in(A,A+9);
    cout<<s.reversePairs(in);
    return 0;
}
