#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c,m,x;
    int q;
    cin>>q;
    while(q--) {
        cin>>c>>m>>x;
        cout<<min({c,m,(c+m+x)/3})<<'\n';
    }
    return 0;
}
