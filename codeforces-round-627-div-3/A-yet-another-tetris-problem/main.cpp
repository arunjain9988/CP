#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    int A[105];
    bool a=false, b=false;
    fo(_t,0,t) {
        a=false;
        b=false;
        cin>>n;
        fo (i,0,n) {
            cin>>A[i];
        }
        for (int i=0; i<n && (!a || !b); i++) {
            if (A[i]%2==0) {
                a=true;
            }
            else {
                b=true;
            }
        }
        if (a && b) {
            print("NO");
        }
        else {
            print("YES");
        }
    }
    
    return 0;
}
