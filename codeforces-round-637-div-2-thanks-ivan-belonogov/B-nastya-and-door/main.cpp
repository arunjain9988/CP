#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,k;
    long long A[200005];
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for (int i=0; i<n; i++) {
            cin>>A[i];
        }
        int m = 0;
        int ans=1;
        for (int i=1; i<n-1 && i<k-1; i++) {
            if (A[i]>A[i-1] && A[i]>A[i+1]) {
                m++;
            }
        }
        int nm=m;
        int i=2;
        int j=i+k-2;
        while(j<n) {
            if ( A[i-1] > A[i-2] && A[i-1] > A[i]) nm--;
            if (A[j-1] >A[j] && A[j-1]>A[j-2]) {
                nm++;
            }
            if (nm>m) {
                ans=i;
                m=nm;
            }
            i++;
            j++;
        }
        cout<<m+1<<" "<<ans<<'\n';
    }
    return 0;
}
