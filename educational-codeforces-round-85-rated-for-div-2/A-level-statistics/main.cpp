#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, a, b, c, d;
    cin>>t;
    bool done=false;
    for (int _t =0; _t<t; _t++) {
        cin>>n;
        cin>>a>>b;
        done=false;
        for (int i=0; i<n-1; i++) {
            cin>>c>>d;
            if (done) {
                continue;
            }
            if (c<a || d<b || c-a<d-b) {
                printf("NO\n");
                done = true;
            }
            a = c;
            b = d;
        }
        if (!done) {
            printf("YES\n");
        }
    }
    
    return 0;
}
