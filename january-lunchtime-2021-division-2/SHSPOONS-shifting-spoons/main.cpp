#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

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

pair<ll,int> A[100005];
vector<pair<pair<int,int>, ll> > results;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    int t,n;
    ll tmp;
    int idx;
    cin>>t;
    ll sum,remain;
    while(t--) {
        cin>>n;
        results.clear();
        loop(i,0,n) {
            cin>>tmp;
            A[i] = make_pair(tmp,i);
        }
        sort(A+1,A+n);
        sum = 0;
        remain = 0;
        for (int i=1; i<n-1; i++) {
            // A[i].first += remain;
            // remain = 0;
            if (A[i].first <= A[0].first) {
                results.pb(make_pair(make_pair(A[i].second,0),A[i].first));
                A[0].first += A[i].first;
            }
            else {
                A[i+1].first += A[i].first - A[0].first;
                results.pb(make_pair(make_pair(A[i].second,A[i+1].second),A[i].first-A[0].first));
                results.pb(make_pair(make_pair(A[i].second,0),A[0].first));
                A[0].first += A[0].first;
            }
        }
        if (A[n-1].first <= A[0].first) {
            results.pb(make_pair(make_pair(A[n-1].second,0),A[n-1].first));
            cout<<results.size()<<'\n';
            for (int i=0; i<results.size(); i++) {
                cout<<results[i].first.first+1<<" "<<results[i].first.second+1<<"  "<<results[i].second<<'\n';
            }
        }
        else cout<<"-1\n";

    }
    return 0;
}
