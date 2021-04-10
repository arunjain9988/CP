#include <bits/stdc++.h>
#define print(__a) cout<<__a<<'\n';
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int A[5005];
    while(cin>>a, a!="0") {
        A[a.size()] = 1;
        for (int i=a.size()-1; i>=0; i--) {
            if ( a[i] == '0' ) {
                A[i]=0;
            }
            else if ( i<a.size()-1 && a.substr(i,2) < "27" && a.substr(i,2) > "0") {
                A[i]=A[i+1]+A[i+2];
            }
            else {
                A[i]=A[i+1];
            }
        }
        print(A[0]);
    }
    
    return 0;
}
