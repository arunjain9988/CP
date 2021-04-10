#include <bits/stdc++.h>
using namespace std;

// class UnionFind{
//     public:
//     int* link;
//     int* size;

//     UnionFind(int n) {
//         this->link = new int[n+1];
//         this->size = new int[n+1];
//         for (int i=1; i<=n; i++) {
//             link[i] = i;
//             size[i] = 1;
//         }
//     }

//     int find(int node) {
//         while (node!=link[node]){
//             node = link[node];
//         }
//         return node;
//     }

//     bool same(int n1, int n2) {
//         return find(n1) == find(n2);
//     }

//     void _union(int n1, int n2) {
//         int a = find(n1);
//         int b = find(n2);
//         if (size[a]<size[b]) {
//             swap(a,b);
//         }
//         a[size] += b[size];
//         b[link] = a;
//     }

//     ~UnionFind() {
//         delete link;
//         delete size;
//     }
// };

int s[26]= {0};

int find(int a) {
    while(a!=s[a]){
        a=s[a];
    }
    return a;
}

void _union(int n1, int n2) {
    int a = find(n1);
    int b = find(n2);
    s[a]=s[b];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    char sbb[51];
    for (int i=0; i<n; i++) {
        cin>>sbb;
        for (int a=1; sbb[a]!='\0'; a++) {
            if (s[(int)sbb[a]-97]==0 && s[(int)sbb[a-1]-97]==0) {
                s[(int)sbb[a]-97]=(int)sbb[a]-97;
                s[(int)sbb[a-1]-97]=(int)sbb[a-1]-97;
            }
            else {
                if (s[(int)sbb[a]-97]==0) s[(int)sbb[a]-97]=(int)sbb[a]-97;
                if (s[(int)sbb[a-1]-97]==0) s[(int)sbb[a-1]-97]=(int)sbb[a-1]-97;
                _union((int)sbb[a]-97,(int)sbb[a-1]-97);
            }
        }
    }

    set<int> result;
    int ans=0;
    for (int i=0; i<26; i++) {
        if (s[i]!=0) {
            result.insert(s[i]);
        }
    }
    printf("%d",result.size());
    return 0;
}
