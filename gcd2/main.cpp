#include <bits/stdc++.h>  // This will work only for g++ compiler. 
using namespace std;

long long ggcd(long long a,long long b) {
	return ((b==0)?a:ggcd(b,a%b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    string a;
    long long b,c;
    long long ia;
    cin>>t;
    while(t--) {
        cin>>b>>a;
        if (b==0){
            cout<<a<<'\n';
            continue;
        } 
        long long amodb = 0;
        for (int i=0; i<a.size(); i++) {
            amodb = (amodb*10)%b;
            amodb = (amodb+a[i]-'0')%b;
        }
        if (b<amodb) swap(b,amodb);
        cout<<ggcd(b,amodb)<<'\n';
    }
    return 0;
}
