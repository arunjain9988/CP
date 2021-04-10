#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int A[40];
int B[40];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,n,k,ans,temp;
    cin>>t;
    while(t--) {
        ans=0; 
        temp=0;
        cin>>n>>k;
        for (ll i=0; i<n; i++) {
            cin>>A[i];
        }
        for (ll i=0; i<n; i++) {
            cin>>B[i];
        }
        sort(A,A+n);
        sort(B,B+n);
        for (int i=0; i<n; i++) {
            temp+=A[i];
        }
        for(ll i=n-k; i<n; i++) {
            if (B[i]>A[i-(n-k)]) {
                temp+=B[i]-A[i-(n-k)];
            }
        }
        for(ll i=k; i<n; i++) {
            ans += A[i];
        }
        for (ll i=n-1; i<n-k; i++) {
            ans += max(A[i],B[i]);
        }
        cout<<temp<<'\n';
    }

    return 0;
}
