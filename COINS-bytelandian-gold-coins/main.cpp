#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define FOO(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define input(__input__var) cin>>__input__var;
#define debug(format, args...) fprintf (stderr, format, args)
#define fo(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;

ll n;
vector<int> A;

void solve() {
    fo(i,0,n-1) {
        if (A[i]!=i+1){
            cout<<i+1;
            return;
        } 
    }
    cout<<n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    A.resize(n-1);
    fo(i,0,n-1) {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    solve();
    return 0;
}
