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

ll solve(int days,vector<ii>& passes,int use) {
    /* passes.first = weight;
    passes.second = cost;
    */
   if (days == 0) return 0;
   if (use<0) return 1ll<<60;
   ll ans = solve(days,passes,use-1);
   if (days >= passes[use].first) {
       ans = min(ans,solve(days-passes[use].first,passes,use)+passes[use].second);
   }
   return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<ii> passes(5);  // first = days // second = min_price
    for (int i=0; i<5; i++) {
        cin>>passes[i].first;
        passes[i].second = INT_MAX;
    }
    int N;
    cin>>N;
    int tmp;
    loop(i,0,N) {
        loop(j,0,5) {
            cin>>tmp;
            passes[j].second = min(passes[j].second,tmp);
        }
    }

    // loop(j,0,5) {
    //     cout<<passes[j].first<<" "<<passes[j].second<<endl;
    // }


    int d;
    cin>>d;
    vector<int> tmparray;
    loop(i,0,d) {
        cin>>tmp;
        tmparray.pb(tmp);
    }

    sort(tmparray.begin(),tmparray.end());

    vector<int> days;
    int cur=tmparray[0];
    int cnt = 1;
    loop(i,1,d) {
        tmp = tmparray[i];
        // cout<<"tmp "<<cur<<tmp<<endl;
        if (tmp == (cur+1)) cnt++;
        else {
            days.pb(cnt);
            cnt = 1;
        }
        cur = tmp;
    }
    days.pb(cnt);

    // loop(i,0,days.size()) {
    //     cout<<days[i]<<" ";
    // }

    ll ans = 0;
    loop(i,0,days.size()) {
        ans += solve(days[i],passes,(int)passes.size()-1);
    }
    cout<<ans;
    return 0;
}
