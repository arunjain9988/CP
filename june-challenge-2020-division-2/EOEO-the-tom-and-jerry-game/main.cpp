#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)


typedef long long ll;
using namespace std;

ll t,n;

ll solve(ll n) {
    if (n&1) {
        return (n-1)/2;
    }
    else return solve(n/2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve(n)<<'\n';
        
    }
    return 0;
}
