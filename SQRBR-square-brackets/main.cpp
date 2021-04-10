#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n'
#define input(__input__var) cin>>__input__var
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

bool A[50];
int DP[50][50];
int getAnswer(int n,int currP=0, int openP=0) {
    // cout<<n<<" "<<currP<<" "<<openP<<'\n';
    if ( openP<0 || currP<0 ) {
        return 0;
    }
    if (currP==n && openP==0) {
        return 1;
    }
    if (DP[currP][openP] != -1) {
        return DP[currP][openP];    
    }
    if (openP>n-currP) {
        DP[currP][openP]=0;
        return DP[currP][openP];
    }
    if (A[currP]==true) {
        return DP[currP][openP]=getAnswer(n,currP+1,openP+1);
    }
    return DP[currP][openP]=getAnswer(n,currP+1,openP+1)+getAnswer(n,currP+1,openP-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,a,b,c,d,n,k;
    cin>>t;
    fo(_t,0,t) {
        cin>>n>>k;
        memset(DP,-1,sizeof(int)*50*50);
        memset(A,false,sizeof(char)*50);
        fo(i,0,k) {
            A[cin>>a,a-1] = true; 
        }
        cout<<getAnswer((2*n))<<'\n';
    }
    return 0;
}
