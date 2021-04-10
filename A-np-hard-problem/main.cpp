#include <bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, int color,const set<int> *adjList, int *colorG) {
    if (colorG[node]!=0) {
        if (colorG[node]==color) return;
        else { printf("%d",-1); exit(0); }
    }
    colorG[node]=color;
    for (auto u:adjList[node]) {
        if (u==parent) continue;
        dfs(u,node,color^1,adjList,colorG);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int a,b;
    cin>>n>>m;
    set<int> adjList[n+1];
    int colorG[100005]= {0};
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }
    for (int z=1; z<=n; z++) {
        if (colorG[z]==0) {
            dfs(z,0,2,adjList,colorG);
        }
    }
    vector<int> v1;
    vector<int> v2;
    for (int i=1; i<=n; i++) {
        if (colorG[i]==2) {
            v1.push_back(i);
        }
        else if (colorG[i]==3) {
            v2.push_back(i);
        }
    }
    cout<<v2.size()<<"\n";
    for (auto b11:v2) {
        cout<<b11<<" ";
    }
    cout<<'\n';
    cout<<v1.size()<<"\n";
    for (auto b11:v1) {
        cout<<b11<<" ";
    }
    return 0;
}

