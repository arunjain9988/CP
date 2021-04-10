#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int row =0;
    int t;
    cin>>t;
    int n;
    string s;
    for (int z=0; z<t; z++) {
        for (int i=0; i<3; i++) {
            for (int j=i; j<9; j+=3) {
                cin>>n;
                s = to_string(n);
                if (s[j]=='1') {
                    s[j]='2';
                }
                else {
                    s[j]='1';
                }
                cout<<s<<'\n';
            }
        }
    }
    
    return 0;
}
