#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int t,n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    int a;
    bool ans;
    fo(_t,0,t) {
        ans=false;
        cin>>n;
        vector<int> pos[5005];
        fo(i,0,n) {
            cin>>a;
            pos[a].push_back(i+1);
            if (pos[a].size()>1 && pos[a][pos[a].size()-2]<pos[a][pos[a].size()-1]-1 ) {
                ans=true;
            }
        }
        if (ans) {
            print("YES");
        }
        else {
            print("NO");
        }


    }
    
    return 0;
}
