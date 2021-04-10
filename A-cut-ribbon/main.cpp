#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define FOO(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define input(__input__var) cin>>__input__var;
#define debug(format, args...) fprintf (stderr, format, args)
#define fo(i,a,b) for(int i=a; i<b; i++)
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,n;
    input(n);
    input(a);
    const int INF = INT32_MIN;
    input(b);
    input(c);
    int inputs[] = {0,a,b,c};
    int A[4][n+1];
    for (int i=0; i<n+1; i++) {
        A[0][i]=INF;
    }
    fo(i,0,4) {
        A[i][0]=0;
    }
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=n; j++) {
            if (j-inputs[i]>=0) {
                A[i][j] = max(A[i-1][j],1+A[i][j-inputs[i]]);
            }
            else {
                A[i][j] = A[i-1][j];
            }
        }
    }

    // for (int i=0; i<=3; i++) {
    //     for (int j=0; j<=n; j++) {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    print(A[3][n])
    return 0;
}
