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

int t,n;
ll xx;
ll mn,mx;
int cnt;
ll A[100005];
vector<pair<int,int> > inputs;
ll ans;

int lb(ll x) {
    int l = 0;
    int mid;
    int h = inputs.size()-1;
    while(l<h) {
        mid = (l+h)/2;
        if (2*A[inputs[mid].second]>=x) {
            h=mid;
        }
        else {
            l = mid+1;
        }
        // if (A[inputs[mid].first]>=x && A[inputs[mid].second]<=x) {
        //     return mid;
        // }
        // if (A[inputs[mid].first]<=x) {
        //     l = mid;
        // }
        // else {
        //     h = mid;
        // }
        // if (A[inputs[mid].second]>=x) {
        //     h = mid;
        // }
        // else {
        //     l = mid+1;
        // }
    }
    return h;
}

ll convert(ll x,ll y) {
    if (x>=y) return 0;
    else {
        ll cntt = 0;
        while(x<y) {
            cntt++;
            x*=2;
        }
        return cntt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n>>xx;
        inputs.clear();
        loop(i,0,n) {
            cin>>A[i];
        }
        sort(A,A+n);
        mn = 0;
        mx = 0;
        loop(i,1,n) {
            if (A[i]<=A[mx]*2) {
                mx = i;
            }
            else {
                inputs.pb(make_pair(mn,mx));
                mn = i;
                mx = i;
            }
        }
        inputs.pb(make_pair(mn,mx));


        //debug
        // cout<<"inputs\n";
        // loop(i,0,inputs.size()) {
        //     cout<<inputs[i].first<<" "<<inputs[i].second<<'\n';
        // }
        // int idx = lower_bound(inputs.begin(),inputs.end(),xx) - inputs.begin();
        // cout<<idx<<" ";
        // int idx = 0;






        int idx = lb(xx);

        //debug
        // cout<<"idx "<<idx<<'\n';
        // if (idx == inputs.size()) idx--;
        // else if (A[inputs[idx].first]<=xx && 2*A[inputs[idx].second]>=xx) {
        // }


        // if (2*A[inputs[idx].second]>=xx) {}
        // while(idx<inputs.size() && xx>2*A[inputs[idx].second]) {idx++;}
        // while (idx>0 && 2*A[inputs[idx-1].second]>=xx) {
        //     idx--;
        // }


        // int idx=inputs.size()-1;




        ans = 0;
        loop(i,idx,inputs.size()) {
            if (xx>=A[inputs[i].first]) {
                ans += (inputs[i].second-inputs[i].first+1);
               xx = A[inputs[i].second]*2;
            }
            else {
                // ans += (int)ceil(log2((double)A[inputs[i].first]) - log2((double)xx) - (1e-9));
                ans += convert(xx,A[inputs[i].first]);
                ans += (inputs[i].second-inputs[i].first+1);
               xx = A[inputs[i].second]*2;
            }


            //debug
            // cout<<"i "<<i<<"ans "<<ans<<"xx "<<xx<<'\n';
        }
        loop(i,0,idx) {
            ans += inputs[i].second - inputs[i].first +1; 
        }
        cout<<ans<<'\n';
        // cout<<(int)ceil(log2((double)110) - log2((double)40) - (1e-8));
        // cout<<(int)ceil(log2((double)1600) - log2((double)200) - (1e-8))<<'\n';
    } 
    return 0;
}
