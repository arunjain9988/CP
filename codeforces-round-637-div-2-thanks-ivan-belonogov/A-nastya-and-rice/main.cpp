#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,a,b,c,d;
    cin>>t;
    while(t--) {
        cin>>n>>a>>b>>c>>d;
        int minR = n*(a-b);
        int maxR = n*(a+b);
        int minT = c-d;
        int maxT = c+d;
        if (minT<=maxR && maxT >= minR) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    
    return 0;
}
