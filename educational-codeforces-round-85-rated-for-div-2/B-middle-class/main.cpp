#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    double average, x;
    int result =0;
    cin>>t;
    for (int z=0; z<t; z++) {
        cin>>n>>x;
        average = 0;
        result =0;
        int A[n];
        for (int i=0; i<n; i++) {
            cin>>A[i];
        }
        sort(A,A+n, greater<int>());
        for (int i=0; i<n; i++) {
            average = (average*i+A[i])/(i+1);
            if (average-x>=-0.0005) {
                result++;
            }
            else {
                break;
            }
        }
        printf("%d\n", result);
    }
    
    return 0;
}
