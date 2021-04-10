#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q,n;
    cin>>q;
    while(q--) {
        cin>>n;
        int A[n],B[n];
        ll DP[n][3];
        fo(i,0,n) {
            cin>>A[i]>>B[i];
        }
        fo(i,0,3) {
            DP[0][i] = B[0]*i;
        }
        fo(i,1,n) {
            fo(j,0,3) {
                ll temp=1e18;
                fo(k,0,3) {
                    if (A[i]+j!=A[i-1]+k) {
                        temp=min(temp,DP[i-1][k]+B[i]*j);
                    }
                    DP[i][j]=temp;
                }
            }
        }
        ll ans = min(DP[n-1][0],DP[n-1][1]);
        ans = min(ans,DP[n-1][2]);
        cout<<ans<<'\n';
    }
    
    return 0;
}
