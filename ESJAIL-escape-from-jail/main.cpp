#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    int t1,t2;
    cin>>n>>k>>m;
    int keysPresent[n+1];
    bool isLocked[n+1];
    bool isWaiting[n+1];
    bool visited[n+1];
    for (int i=0; i<=n; i++) {
        keysPresent[i]=0;
        isLocked[i]=true;
        isWaiting[i]=false;
        visited[i]=false;
    }
    for (int i=0; i<k; i++) {
        cin>>t1>>t2;
        keysPresent[t1]=t2;
        isLocked[t1]=false;
    }
    
    set<int> adjList[n+1];
    for (int i=0; i<m; i++) {
        cin>>t1>>t2;
        adjList[t1].insert(t2);
        adjList[t2].insert(t2);
    }
    bool found;
    queue<int> bfsQ;
    bfsQ.push(1);
    while(!bfsQ.empty()) {
        int node = bfsQ.front();
        bfsQ.pop();
        for (int u:adjList[node]) {
            if (u==n) {
                found=true;
                break;
            }
            else if (visited[u]) continue;
            else if(isLocked[u]) {
                isWaiting[u]=true;
            }
            else {
                int a = keysPresent[u];
                if (isLocked[a]) {
                    isLocked[a]=false;
                    if (isWaiting[a]){
                    bfsQ.push(a);
                    isWaiting[a]=false;
                    }
                }
            }
        }
    }

    if (found) printf("YES");
    else printf("NO");


    return 0;
}
