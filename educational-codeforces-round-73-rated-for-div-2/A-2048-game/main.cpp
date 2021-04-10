#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q,n;
    cin>>q;
    int A[101];
    while(q--) {
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>A[i];
        }
        ll sum=0;
        for (int i=0; i<n; i++) {
            if (A[i]<=2048) {
                sum+=A[i];
            }
        }
        if (sum>=2048) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    
    return 0;
}
