#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        if (n==1) {
            cout<<0<<'\n';
        }
        else if (n==2) {
            cout<<m<<'\n';
        }
        else {
            cout<<m*2<<'\n';
        }
    }
    return 0;
}
