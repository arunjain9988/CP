#include<bits/stdc++.h>
// #include<fstream>
// #include<cstdio>
using namespace std;



int maxSubarraySum(vector<int> A)
{
    int m = 0,tillNow = 0;
    for(int i=0; i<A.size(); i++){
        tillNow += A[i];
        if (tillNow<0){
            tillNow = 0;
        }
        else{
            m = max(tillNow,m);
        }
    }
    return m;
}

void merge(vector<int> A,int i,int j){
    int help[j-i+1];
    int start=i;
    int end=j;

}

void mergeHelper(vector<int> A, int i, int j){
    if (i<=j){
        return; 
    }
    int mid = (i+j)/2;
    mergeHelper(A,i,mid);
    mergeHelper(A,mid+1,j);
    merge(A,i,j);

}

void mergeSort(vector<int> A)
{
    int i = 0,j = A.size()-1;
    
}

pair<int,int> binary_s(vector<int> A,int k){
    int x=-1;
    auto lb = lower_bound(A.begin(),A.end(),k);
    auto ub = upper_bound(A.begin(),A.end(),k);
    int a = lb-A.begin();
    int b = ub-A.begin();
    return pair<int,int>(a,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    // unsigned long long abc;
    // int a ,b,c;
    // string s;
    // scanf("%d/%d/%d",&a,&b,&c);
    // cout<<a<<'-'<<b<<"-"<<c<<'\n';
    // scanf("%d/%d/%d",&a,&b,&c);
    // cout<<a<<'-'<<b<<"-"<<c<<'\n';
    // getline(cin,s);
    // cout<<s<<endl;
    // while(cin>>a){
    //     cout<<a<<" printed";
    // }
    // note: ctrl+d denotes end of input


    // abc = (unsigned long long)10000000000000000;
    // cout<<abc;

    // maxsubarray sum
    // vector<int> S = {-1,2,4,-3,5,2,-5,2};
    // cout<<maxSubarraySum(S)<<'\n';
    

    //binary search
    // vector<int> S = {1,4,6,6,7,9,11};
    // auto a = lower_bound(S.begin(),S.end(),6);
    // auto b = upper_bound(S.begin(),S.end(),6);
    // auto c = equal_range(S.begin(),S.end(),9);
    // if (*c.first == 9){
    //     cout<<c.second-c.first;
    // }
    // else{

    // }
    // auto t = binary_s(S,6);
    // cout<<t.second;
    // set<int> r = {1,5};
    // cout<<*(--r.end());
    // r.erase(r.find(5));
    // r.insert(1);
    // cout<<r.count(5);

    // deque<string> p;
    // p.push_back("arun");
    // p.push_back("aryan");
    // sort(p.begin(),p.end());
    // for(auto x:p){
    //     cout<<x<<" ";
    // }

    // bitset<20> bt;
    // bt.set(5);
    // cout<<bt.count()<<'\n';
    // cout<<bt[5]<<'\n';

    // priority_queue<int> pq;
    // pq.push(5);
    // pq.push(10);
    // pq.push(3);
    // cout<<pq.top()<<'\n';
    // pq.pop();
    // cout<<pq.top()<<'\n';

    // priority_queue<string,vector<string>,greater<string>> lpq;
    // lpq.push("arun");
    // lpq.push("aar");
    // lpq.push("pooja");
    // cout<<lpq.top()<<'\n';
    // lpq.pop();
    // cout<<lpq.top()<<'\n';

    vector<int> a = {5,2,8,9,4};
    vector<int> b = {3,2,9,5};
    
    // finding common elements
    // algo 1
    





    return 0;

}