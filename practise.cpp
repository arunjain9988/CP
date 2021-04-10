#include<bits/stdc++.h>
#include<string>
using namespace std;

// int main(){
//   // cout<<"hello world";
//   // return 0;
//   // list<int> a = {10,46,62};
//   // list<int>::iterator b = a.begin();
//   // cout<<*b<<endl;
//   // // a.splice(a.begin(),a,a.begin(),a.end());
//   // for(auto x:a){
//   //   cout<<x<<" ";
//   // }
//   set<int> ar;
//   int b;
//   for(int i = 0; i<10; i++){
//     cin>>b;
//     ar.insert(b);
//   }
//   for(auto x:ar){
//     cout<<x<<" ";
//   }
// }



// binary search on a vector
// int main(){
//   vector<int> a = {-5,4,45,12,47,78,98,105,112,205,302};
//   sort(a.begin(),a.end());
//   int i = 0;
//   int j = a.size();
//   int find = 44;
//   int mid;
//   while(i<j){
//     mid = (i+j)/2;
//     if (find == a[mid]){
//       cout<<"Element found"<<endl;
//       return 1;
//     }
//     else if (find>a[mid]){
//       i = mid+1;
//     }
//     else{
//       j = mid-1;
//     }
//   }
//   cout<<"Element not found"<<endl;
//   return 0;
// }


// generate all permutations
// void permutations(string A,int pos=0){
//   // cout<<A;    //debug
//   // cout<<pos;  //debug
//   int size = A.length();
//   // cout<<size;  //debug
//   static char res[15];
//   static int used[15] = {0};
//   // char res[size+1];
//   // char *res = (char *)malloc(sizeof(char)*size+1)
//   // char *res = new char[size+1];
//   // int used[size] = {0};
//   // int *used = new int[size];
//   if (pos == size){
//     res[pos] = '\0';
//     for(int i=0; res[i]!='\0'; i++){
//       cout<<res[i];
//     }
//   cout<<endl;
//   }
//   else{
//     for(int i=0; A[i]!='\0'; i++){
//       if (used[i]==0){
//         res[pos]=A[i];
//         used[i]=1;
//         permutations(A,pos+1);
//         used[i]=0;
//       }
//     }
//   }
// }

void permutation_simple(string S){
  sort(S.begin(),S.end());
  do{
    cout<<S<<endl;
  }
  while(next_permutation(S.begin(),S.end()));
}

void all_subsets(int n,int pos=0)
{
  static vector<int> res;
  if (pos == n){
    for(auto x:res){
      cout<<x<<" ";
    }
    cout<<endl;
  }
  else{
    all_subsets(n,pos+1);
    res.push_back(pos+1);
    all_subsets(n,pos+1);
    res.pop_back();
  }
}


int main(){
  // permutation_simple("arun");
  all_subsets(5);
  return 0;
}
