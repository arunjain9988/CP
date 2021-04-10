#include <bits/stdc++.h>
using namespace std;


class TrieNode{
  public:
    TrieNode** childs;
    TrieNode(){
        childs = new TrieNode*[2];
        childs[0] = nullptr;
        childs[1] = nullptr;
    }
};

void insert(TrieNode* head,int p) {
    TrieNode* cur = head;
    for (int i=30; i>=0; i++) {
        if (!cur->childs[(p>>i)&1]) {
            cur->childs[(p>>i)&1] = new TrieNode();
        }
        cur = cur->childs[(p>>i)&1];
    }
}

int getmaxxor(TrieNode* head,int p) {
    int mxxor = 0;
    TrieNode* cur = head;
    for (int i=30; i>=0; i++) {
        if (cur->childs[(p>>i)^1]) {
            mxxor += (1<<i);
            cur = cur->childs[(p>>i)^1];
        }
        else {
            cur = cur->childs[(p>>i)&1];
        }
    }
    return mxxor;
}

int solve(vector<int> A, vector<int> B) {
    TrieNode* head = new TrieNode();
    for (int i=0; i<A.size(); i++) {
        insert(head,A[i]);
    }
    int mx = INT_MIN;
    for (int i=0; i<B.size(); i++) {
        int curmx = getmaxxor(head,B[i]);
        if (curmx>mx) {
            mx = curmx;
        }
    }
    return mx;
}


int main() {
    int A[] = { 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605, 3903, 154, 293, 12383, 17422, 18717, 19719, 19896, 5448, 21727, 14772, 11539, 1870, 19913, 25668, 26300, 17036, 9895, 28704, 23812, 31323, 30334, 17674, 4665, 15142, 7712 };
    int B[] = { 28254, 6869, 25548, 27645, 32663, 32758, 20038, 12860, 8724, 9742, 27530, 779, 12317, 3036, 22191, 1843, 289, 30107, 9041, 8943, 19265, 22649 };
    vector<int> a(begin(A),end(A));
    vector<int> b(begin(B),end(B));
    int u = solve(a,b);
    // for (string u:anss) {
        cout<<u<<" ";
    // }
    return 0;
}  // } Driver Code Ends
