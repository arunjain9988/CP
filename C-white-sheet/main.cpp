#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


pair<pii,pii> intersect(pii x1, pii x2, pii x3, pii x4) {
    int left = max(min(x1.first, x2.first),min(x3.first, x4.first));
    int right = min(max(x1.first, x2.first), max(x3.first, x4.first));
    int top = min(max(x1.second, x2.second), max(x3.second, x4.second));
    int down = max(min(x1.second, x2.second), min(x3.second,x4.second));

    if (top<=down || right<=left) {
        return {{0,0},{0,0}};
    }
    return {{left,down},{right,top}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pii w1, w2, b1, b2, b3, b4;
    cin>>w1.first>>w1.second>>w2.first>>w2.second>>b1.first>>b1.second>>b2.first>>b2.second
    >>b3.first>>b3.second>>b4.first>>b4.second;

    pair<pii,pii> isc1 = intersect(w1,w2,b1,b2);
    pair<pii,pii> isc2 = intersect(w1,w2,b3,b4);
    pair<pii,pii> isc3 = intersect(isc1.first,isc1.second,isc2.first,isc2.second);
    ll area1 = 1ll * abs(isc1.second.first-isc1.first.first) * abs(isc1.second.second-isc1.first.second);
    ll area2 = 1ll * abs(isc2.second.first-isc2.first.first) * abs(isc2.second.second-isc2.first.second);
    ll area3 = 1ll * abs(isc3.second.first-isc3.first.first) * abs(isc3.second.second-isc3.first.second);
    ll fArea = 1ll * abs(w2.first-w1.first) * abs(w2.second-w1.second);
    if (fArea > area1+area2-area3) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

    return 0;
}
