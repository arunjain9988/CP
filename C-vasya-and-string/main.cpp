#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,c,d,n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int fp = 0;
    int sp = 0;
    // int aCount = s[0]=='a';
    // int bCount = s[0]=='b';
    int aCount=0;
    int bCount=0;
    int maximum  = 0;
    while(sp<s.size()) {
            aCount+=s[sp]=='a';
            bCount+=s[sp]=='b';
            while(aCount>k && bCount>k) {
                aCount-= s[fp]=='a';
                bCount-= s[fp]=='b';
                fp++;
            }
            maximum=max(maximum,sp-fp+1);
            sp++;
    }
    cout<<maximum;
    return 0;
}
