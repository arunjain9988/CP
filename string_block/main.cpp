#include<bits/stdc++.h>
using namespace std;

string Find_It (int N, int X, int K, string S) {
   // Write your code here
   int blocks = (N+X-1)/X;
   vector<vector<int> > bl(blocks,vector<int>());
   for (int i=0; i<blocks; i++) {
      for (int j=i*X; j<min(N,(i+1)*(X)); j++) {
         bl[i].push_back((S[j])-'0');
      }
   }

   // int cur = bl[blocks-1].size();
   // int bb = blocks-2;
   // while(cur<K) {
   //    cur *= (X);
   //    bb--;
   // }
   vector<int> sizes;
   sizes.push_back(0);
   int cur = 1;
   for (int i=(bl.size()-1); i>=0; i--) {
      cur*=bl[i].size();
      sizes.push_back(cur);
   }
   reverse(sizes.begin(),sizes.end());
   // for (int u:sizes) cout<<u<<' ';
   int cc = 0;
   while(sizes[cc+1] >= K) {
      cout<<bl[cc][0];
      cc++;
   }
   while(cc<bl.size()) {
      sort(bl[cc].begin(),bl[cc].end());
      // cerr<<(bl[cc][0]);
      cout<<bl[cc][(K/X)-1];
      cc++;
      K -= (K/X);
   }
   // cur/=X;
   // cout<<bb+1<<' '<<cur<<'\n';
   // for (auto i:bl) {
   //    for (int j:i) {
   //       cout<<j<<' ';
   //    }
   //    cout<<endl;
   // }
   return "a";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int X;
    cin >> X;
    int K;
    cin >> K;
    string S;
    cin>>S;

    string out_;
    out_ = Find_It(N, X, K, S);
    cout << out_;
}