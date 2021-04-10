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

int t,fence,painters;
int initial[100005];
int desired[100005];
int colors[100005];
// unordered_map<int,int> colormap;
vector<int> paintershave[100005];
int ans[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        // colormap.clear();
        cin>>fence>>painters;
        floop(i,1,fence) {
            cin>>initial[i];
            paintershave[i].clear();
        }
        floop(i,1,fence) {
            cin>>desired[i];
        }
        floop(i,1,painters) {
            cin>>colors[i];
            // colormap[colors[i]]++;
            paintershave[colors[i]].push_back(i);
            ans[i] = 0;
        }
        bool possible = false;
        int goodfence=-1;
        // int goodpos = -1;
        for (int i=1; i<=fence; i++) {
            if (desired[i] == colors[painters]) {
                possible = true;
                goodfence = i;
                // goodpos = 
                break;
            }
            // goodfence = i+1;
        }
        if (!possible) {
            cout<<"NO\n";
            continue;
        }
        possible = true;
        for (int i=1; i<=fence; i++) {
            if (initial[i] != desired[i]) {
                if (paintershave[desired[i]].size() <= 0) {
                    possible = false;
                    break;
                }
                else {
                    // colormap[desired[i]]--;
                    ans[paintershave[desired[i]].back()] = i;
                    paintershave[desired[i]].pop_back();
                }
            }
        }
        if (!possible) cout<<"NO\n";
        else {
            cout<<"YES\n";
            if (ans[painters] == 0 ) {
                ans[painters] = goodfence;
            }
            // int gdf = 0;
            // for (int i=painters; i>=0; i--) {
            //     if (ans[i] != 0){
            //         gdf = i;
            //         break;
            //     }
            // }
            // if (!gdf) {
            //     for (int i=0;  i<fence; i++) {
            //         if (desired[i] == colors[painters-1]) {
            //             gdf = i+1;
            //         }
            //     }
            // }
            for (int i=1; i<=painters; i++) {
                if (ans[i] == 0) {
                    ans[i] = ans[painters];
                }
                cout<<ans[i]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}
