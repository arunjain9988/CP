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

struct edge {
    int l,r;
    vii lcm;
};

int a,b,c,d,e;
ll ans;

int t,m,n;
int visited[40];
vector<edge> inputs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        inputs.clear();
        cin>>n>>m;
        memset(visited,0,sizeof visited);
        loop(i,0,m) {
            cin>>a>>b>>c;
            visited[a]=1;
            visited[b]=1;
            if (a>b) swap(a,b);
            auto tmp = edge();
            tmp.l = a;
            tmp.r = b;
            loop(j,0,c) {
                cin>>d>>e;
                tmp.lcm.pb({d,e});
            }
            sort(all(tmp.lcm));
            inputs.pb(tmp);
        }

        bool ans_find = true;
        loop(i,1,n+1) {
            if (!visited[i]) {
                // cout<<-1<<'\n';
                ans_find = false;
            }
        }
        if (!ans_find) {
            cout<<-1<<'\n';
            continue;
        }

        sort(all(inputs),[](edge a,edge b) {
            if (a.l == b.l) return (a.r < b.r );
            return a.l<b.l;
        });
        ans_find = true;
        loop(i,1,m) {
            if ((inputs[i].l == inputs[i-1].l) && (inputs[i].r == inputs[i-1].r) && (inputs[i].lcm.size() == inputs[i-1].lcm.size())) {
                loop(k,0,inputs[i].lcm.size()) {
                    if ((inputs[i].lcm[k].first != inputs[i-1].lcm[k].first) || (inputs[i].lcm[k].second != inputs[i-1].lcm[k].second)) {
                        ans_find=false;
                    }
                }
            }
        }

        if (!ans_find) {
            cout<<0<<'\n';
            continue;
        }

        ans=0;
        cout<<ans<<'\n';
    }
    return 0;
}
