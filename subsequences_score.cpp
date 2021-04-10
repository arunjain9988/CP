#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> all_subsets = {};

void subset(int n,int k=1,vector<int> s={}){
    if (k==n+1){
        all_subsets.push_back(s);
    }
    subset(n,k+1,s);
    s.push_back(k);
    subset(n,k+1,s);
    s.pop_back();
}

int main(){

    subset(4);
    for(auto a:all_subsets){
        for(auto p:a){
            cout<<p<<' ';
        }
    }

    // long long N,temp,is_set,a;
    // long long answer=0;
    // long long modulo = pow(10,9)+7;
    // // bitset<10> bits;
    // cin>>N;
    // long long A[N];
    // // N=4;
    // for(long long i=N-1; i>=0; i--){
    //     cin>>A[i];
    // }




    //debug
    // for(int i=N-1; i>=0; i--){
    //         cout<<A[i];
    //     }


    // A[0]=34;
    // A[1]=23;
    // A[2]=12;
    // A[3]=1;
    // long long no_of_subsets=pow(2,N);
    // for(long long _=1; _<no_of_subsets; _++){
    //     //debug

    //     // cout<<i;

    //     bits.reset();
    //     long long shift=0;
    //     long long i = _;
    //     while(i>0){
    //         //debug
    //         // cout<<i;

    //         if(i&(1<<shift)){
    //         temp=A[shift];
    //         bitset<10> bitstemp;
    //         while(temp>0){
    //             a=temp%10;
    //             bitstemp.set(a);
    //             temp/=10;
    //         }
    //         auto r = bits&bitstemp;
    //         if(r.any()){
    //             break;
    //         }
    //         bits|=bitstemp;
    //         i=i^(1<<shift);
    //         }
    //         shift++;
    //     }
    //     if(i==0){
    //         // debug
    //         // cout<<"no"<<_<<endl;
    //         // cout<<"bits"<<bits<<endl;
    //         answer=(answer+1)%modulo;
    //     }
    // }
    // cout<<answer;
    return 0;
}