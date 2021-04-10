#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans =0;
    vector<int> input(n);
    for (int i=0; i<input.size(); i++) cin>>input[i];
    vector<int> dp(n);
    for (int i=0; i<input.size(); i++) {
        dp[i] = input[i];
        for (int j=0; j<i; j++) {
            if (input[i]%input[j]==0) dp[i] = max(dp[i],dp[j]+input[i]);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
}