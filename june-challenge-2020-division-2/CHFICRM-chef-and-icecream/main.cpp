#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)


typedef long long ll;
using namespace std;


int t,n,count5,count10;
int a[1005];
bool done;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n;
        count5=0;
        count10=0;
        done=0;
        fo(i,0,n) {
            cin>>a[i];
        }
        fo(i,0,n) {
            if (a[i]==5) {
                count5++;
            }
            else if (a[i]==10) {
                count10++;
                if (count5<1) {
                    cout<<"NO"<<'\n';
                    done=1;
                    break;
                }
                else {
                    count5--;
                }
            }
            else {
                if (count10<1 && count5<2) {
                    cout<<"NO"<<'\n';
                    done=1;
                    break;
                }
                else if (count10>0) {
                    count10--;
                }
                else {
                    count5-=2;
                }
            }
        }
        if(!done) {
            cout<<"YES"<<'\n';
        }
    }
    return 0;
}
