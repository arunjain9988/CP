#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, r) for (int i = (int)(0); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back
#define mp make_pair

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)


// trace program
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl

// useful constants
#define MOD 1000000007
#define EPS (double)1e-6

using namespace std;


// Important header files   ordered set
// #include <ext/pb_ds/assoc_container.hpp> // Common file  
// #include <ext/pb_ds/tree_policy.hpp>  
// #include <functional> // for less

// using namespace __gnu_pbds;
// template <typename T>
// using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


//chess moves
// int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
// int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

// int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
// int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

// int rookmovesx[] = {-1,0,1,0};
// int rookmovesy[] = {0,-1,0,1};

// int bishopmovesx[] = {-1,1,1,-1};
// int bishopmovesy[] = {-1,-1,1,1};


class uniquecount{
   public:
   int A[26];
   int uniques;
   uniquecount() {
      fill(A,A+26,0);
      uniques=0;
   }
   void insert(char c) {
      if (A[c-'a'] == 0) uniques++;
      A[c-'a']++;
   }
   void rmv(char c) {
      if (A[c-'a'] == 1) uniques--;
      A[c-'a']--;
   }
};

vector<long long> DistinctChars (int N, string S) {
   // Write your code hdsafere
   int answers[27];
   fill(answers,answers+27,0);
   for (int i=1; i<=26; i++) {
      uniquecount uq;
      int st=0,ed=0;
      for (int j=0; j<S.size(); j++) {
         // if (uq.uniques < i){
         //    uq.insert(S[j]);
         // }
         uq.insert(S[j]);
         char tmp;
         if (uq.uniques < i) continue;
         answers[i]++;
         while(uq.uniques > i){
            uq.rmv(S[st]);
            st++;
         }
         while(uq.A[S[st]-'a'] > 1) {
            uq.rmv(S[st]);
            st++;
            answers[i]++;
         }
      }
   }
   for (int i=1; i<=25; i++) cout<<answers[i]<<'\n';
   return vector<long long>();
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<long long> out_;
    out_ = DistinctChars(N, S);
    // cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
