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

int n,p;
ll funds[10005];
ll pre[10005];

vector<ii> groups;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n;
    floop(i,1,n) {
        cin>>funds[i];
    }
    pre[0] = 0;
    floop(i,1,n) {
        pre[i] = pre[i-1] + funds[i];
    }
    cin>>p;
    int l,r;

    // groups.push_back(make_pair(0,0));
    loop(_k,0,p) {
        cin>>l>>r;
        groups.pb(make_pair(l,r));
    }
    sort(groups.begin(),groups.end());

    // int idx = 0;
    // for (int i=1; i<(int)groups.size(); i++) {
    //     if (groups[idx].second >= groups[i].first) {
    //         groups[idx].second = max(groups[idx].second,groups[i].second);
    //         groups[idx].first = min(groups[idx].first,groups[i].first);
    //     }
    //     else {
    //         idx++;
    //         groups[idx].first = groups[i].first;
    //         groups[idx].second = groups[i].second;
    //     }
    // }

    // floop(i,0,idx) {
    //     cout<<groups[i].first<<groups[i].second<<endl;
    // }


    // int bestl=1,bestr=0;

    // floop(i,0,idx) {
    //     l = groups[i].first;
    //     r = groups[i].second;
    //     // cout<<l<<' '<<r<<endl;

    //     if ((pre[r]-pre[l-1]) > (pre[bestr]-pre[bestl-1])) {
    //         bestl = l;
    //         bestr = r;
    //     }
    //     else if ((pre[r]-pre[l-1]) == (pre[bestr]-pre[bestl-1])) {
    //         if ((r-l) < (bestr-bestl)) {
    //             bestr = r;
    //             bestl = l;
    //         }
    //     }
    // }
    vector<ii> new_groups;


    int curl=groups[0].first;
    int curr = groups[0].second;
    
    for (int i=1; i<(int)groups.size(); i++) {
        if (groups[i].first <= curr) {
            curr = max(curr,groups[i].second);
            curl = min(curl,groups[i].first);
        }
        else {
            new_groups.pb(make_pair(curl,curr));
            curl = groups[i].first;
            curr = groups[i].second;
            // cout<<curl<<curr<<"cur"<<endl;
        }
    }
    new_groups.pb(make_pair(curl,curr));



    // loop(i,0,new_groups.size()) {
    //     cout<<new_groups[i].first<<new_groups[i].second<<endl;
    // }


    int bestl=1,bestr=0;
    ll curbest = -100000000000ll;

    loop(i,0,new_groups.size()) {
        
        l = new_groups[i].first;
        r = new_groups[i].second;
        if ((pre[r]-pre[l-1]) > (curbest)) {
            bestl = l;
            bestr = r;
            curbest = pre[bestr]-pre[bestl-1];
        }
        else if ((pre[r]-pre[l-1]) == (curbest)) {
            if ((r-l) < (bestr-bestl)) {
                bestr = r;
                bestl = l;
            }
        }
        // cout<<bestl<<' '<<bestr<<endl;
    }


    floop(i,bestl,bestr) {
        cout<<i<<" ";
    }
    return 0;
}
