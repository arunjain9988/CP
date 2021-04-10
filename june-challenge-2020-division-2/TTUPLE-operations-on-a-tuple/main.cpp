#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
// #define fo(i,_a,_b) for(ll i=_a; i<_b; i++)


typedef long long ll;
using namespace std;

int cnt;
int t;
ll p,q,r,a,b,c;
bool done;
vector<pair<ll,ll> > inputs(3);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) {
        cnt=0;
        // inputs.clear();
        cin>>p>>q>>r;
        cin>>a>>b>>c;
        if (p==q && a==b) {
            a=p;
        }
        if (q==r && b==c) {
            b=q;
        }
        if (p==r && a==c) {
            a=p;
        }
        if (p!=a) {
            inputs[cnt++]={p,a};
        }
        if (q!=b) {
            inputs[cnt++]={q,b};
        }
        if (r!=c) {
            inputs[cnt++]={r,c};
        }
        // trying to do in 1 move

        //if only 1 plus move is required

        done=true;
        for(int i=0; i<cnt-1; i++) {
            if (inputs[i].second-inputs[i].first!=inputs[i+1].second-inputs[i+1].first) {
                done=false;
            }
        }
        if (done) {
            cout<<1<<'\n';
            continue;
        }

        //if only 1 multiply move is required

        done=true;
        for(int i=0;i<cnt-1;i++) {
            if (inputs[i].first==0 || inputs[i+1].first==0) {
                done=false;
                break;
            }
            if (((inputs[i].second/inputs[i].first)!=(inputs[i+1].second/inputs[i+1].first)) ||
             (inputs[i].second%inputs[i].first!=0) || (inputs[i+1].second%inputs[i+1].first!=0)) {
                done=false;
                break;
            }
        }

        if (done) {
            cout<<1<<'\n';
            continue;
        }
        if (cnt<3) {
            cout<<2<<'\n';
            continue;
        }
        done=false;
        for(int i=0;i<cnt-1; i++) {
            for(int j=i+1; j<cnt; j++) {
                if (inputs[i].second-inputs[i].first==inputs[j].second-inputs[j].first) {
                    done=true;
                    break;
                }

                if (inputs[i].first==0 || inputs[j].first==0) {
                    continue;
                }

                if (((inputs[i].second/inputs[i].first)==(inputs[j].second/inputs[j].first)) &&
                 (inputs[i].second%inputs[i].first==0) && (inputs[j].second%inputs[j].first==0)) {
                    done=true;
                    break;
                }
            }
        }

        ll gg = inputs[1].first-inputs[0].first;
        ll hh = inputs[1].second-inputs[0].second;
        ll ii = inputs[2].first-inputs[1].first;
        ll jj = inputs[2].second-inputs[1].second;
        if ( gg!=0 && ii!=0 && hh/gg==jj/ii && hh%gg==0 && jj%ii==0) {
            done=true;
        }
        if (done) {
            cout<<2<<'\n';
            continue;
        }
        cout<<3<<'\n';
    }
    return 0;
}
