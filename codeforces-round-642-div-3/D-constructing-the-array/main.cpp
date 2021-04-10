#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

// class comp {
//     public:
//     bool operator() (pair<int,int> a,pair<int,int> b) {
//         ll l1 = a.second-a.first+1;
//         ll l2 = b.second-b.first+1;
//         if (l1<l2) {
//             return true;
//         }
//         else {
//             return b.first<a.first;
//         }
//     }
// };

// bool cmp (pair<int,int> a,pair<int,int> b) {
//         ll l1 = a.second-a.first+1;
//         ll l2 = b.second-b.first+1;
//         if (l1<l2) {
//             return true;
//         }
//         else {
//             return b.first<a.first;
//         }
//     }


auto cmp=[](pair<int,int> &a,pair<int,int> &b) {
        ll l1 = a.second-a.first+1;
        ll l2 = b.second-b.first+1;
        if (l1<l2) {
            return true;
        }
        else {
            return b.first<a.first;
        }
    };

int Result[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,n,leng;
    int now;
    cin>>t;
    while(t--) {
        priority_queue<pair<int,int>,std::vector<pair<int,int>>,decltype(cmp)> q(cmp);
        cin>>n;
        now=1;
        q.push({0,n-1});
        while(now<=n) {
            auto a = q.top();
            q.pop();
            leng=(a.second-a.first+1)/2;
            Result[leng]=now;
            now++;
            q.push({a.first,leng-1});
            q.push({leng+1,a.second});
        }
        for (int i=1; i<=n; i++) {
            cout<<Result[i]<<" ";
        }
    }
    return 0;
}
