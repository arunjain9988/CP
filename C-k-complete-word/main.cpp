#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        string s;
        int result=0;
        cin>>n>>k;
        cin>>s;
        for (int i=0; i<k; i++) {
            multiset<char> ms;
            int m=0;
            for (int j=0; j<n/k; j++) {
                ms.insert(s[i+j*k]);
                int temp = ms.count(s[i+j*k]);
                if (temp>m) {
                    m=temp;
                }   
            }
            result += (n/k-m);
        }
        cout<<result<<'\n';
    }
    return 0;
}
