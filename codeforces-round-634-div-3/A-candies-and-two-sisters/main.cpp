#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n;
    int t;
    cin>>t;
    for (int z=0; z<t; z++) {
        cin>>n;
        printf("%llu\n",(n-1)/2);
    }
    
    return 0;
}
