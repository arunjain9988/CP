#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define loop(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n,k,a,ans=0;
        cin>>n>>k;
        loop(i,0,n) {
            cin>>a;
            if (a>k) {
                ans+=a-k;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
