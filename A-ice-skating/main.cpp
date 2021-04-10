#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a; i<b; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<pair<int, int>,bool> inputs;
    int n, a, b;
    cin>>n;
    fo(i,0,n) {
        cin>>a>>b;
        inputs[{a,b}]=true;
    }
    int answer;
    bool rowsCaptured[1001];
    bool colsCaptured[1001];
    memset(rowsCaptured,false,1001);
    memset(colsCaptured,false,1001);
    queue<int> q;
    set<pair<int, int>>::iterator temp;
    while(!inputs.empty) {
        temp = inputs.begin();
        if (rowsCaptured[temp->first] || colsCaptured[temp->second]){
            rowsCaptured[temp->first] = true;
            colsCaptured[temp->second] = true;
            inputs.find(temp);
        }
        inputs.erase(temp);
    }
    
    return 0;
}
