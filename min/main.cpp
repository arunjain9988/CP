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

long long getmin(vector<int>& jobs,int start,int A[],int sz){
    int ans = INT_MIN;
        if (start == sz) {
            for (int i=0; i<sz; i++) {
                ans = max(ans,A[i]);
            }
            return ans;
        }
        for (int i=0; i<jobs.size();i++) {
            if (jobs[i] == 0) continue;

        }
    }
    
    int minimumTimeRequired(vector<int> jobs, int k) {
        // sort(jobs.begin(),jobs.end(),greater<int>());
        int A[k];
        memset(A,0,sizeof(A));
        long long ans;
        // if (k>= (jobs.size()+1)/2) {
        //     sort(jobs.begin(),jobs.end(),greater<int>());
        //     // for (int i=0; i<jobs.size(); i++) {
        //     //     cout<<jobs[i]<<" ";
        //     // }
        //     for (int i=0; i<k; i++) {
        //         A[i] = jobs[i];
        //     }
        //     ans = getmin(jobs,k,A,k);  
        // }
        // else 
        ans = getmin(jobs,0,A,k);
        return ans;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> p =  {9899456,8291115,9477657,9288480,5146275,7697968,8573153,3582365,3758448,9881935,2420271,4542202};
    int k=9;
    cout<<minimumTimeRequired(p,k);
    return 0;
}
