#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

int n,w,h;
vector<pair<int, int>> inputs;
vector<int> ans;
map<pair<pair<int, int>, pair<int, int>>, int> dp;
int maxEnvelope(const pair<int, int> &curr) {
    int sum = 0;
    fo(i,0,inputs.size()) {
        if (inputs[i].first > curr.first && inputs[i].second > curr.second) {
            if (sum==0) {
            ans.push_back(i+1);
            }
            else {
                ans.pop_back();
                ans.push_back(i+1);
            }
            sum=max(sum, 1+maxEnvelope(inputs[i]));
            // ans.pop_back();
        }
    }
    return sum;
}
int main() {
    int a,b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>w>>h;
    fo(i,0,n) {
        cin>>a>>b;
        inputs.push_back({a,b});
    }
    cout<<maxEnvelope(make_pair(w,h))<<'\n';
    for (auto z:ans) {
        cout<<z<<" ";
    }
    return 0;
}
