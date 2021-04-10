#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,a,b,q,l,r,done_yet;
    vector<ll> result;
    cin>>t;
    while(t--) {
        cin>>a>>b>>q;
        done_yet=0;
        result.clear();
        while(q--) {
            cin>>l>>r;
            while(done_yet<r) {
                done_yet++;
                if ((((done_yet)%a)%b) != ((done_yet)%b)%a) {
                    result.push_back(done_yet);
                }
            }
            auto lb = lower_bound(result.begin(),result.end(),l);
            auto rb = upper_bound(result.begin(),result.end(),r);
            cout<<rb-lb<<'\n';
        }
    }
    
    return 0;
}
