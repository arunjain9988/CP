#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)


typedef long long ll;
using namespace std;

int odd,even;
int t,n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) {
        odd=1;
        even=2;
        cin>>n;
        if (n%2==0) {
            fo(i,0,n) {
                fo(j,0,n) {
                    if ((i+j)%2!=0) {
                        cout<<odd<<" ";
                        odd+=2;
                    }
                    else {
                        cout<<even<<" ";
                        even+=2;
                    }
                }
                cout<<'\n';
            }
        }
        else {
            fo(i,0,n) {
                fo(j,0,n) {
                    if ((i+j)%2!=0) {
                        cout<<even<<" ";
                        even+=2;
                    }
                    else {
                        cout<<odd<<" ";
                        odd+=2;
                    }
                }
                cout<<'\n';
            }
        }
        
    }
    return 0;
}
