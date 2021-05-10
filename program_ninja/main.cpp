#include <bits/stdc++.h>
using namespace std;

vector<int,vector<int> > matrixMul(vector<int,vector<int> > Matrix,int pow) {
    if (pow == 1) {
        return Matrix;
    }
    return Matrix;
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    vector<int,vector<int> > Matrix(2,vector<int>(2,1));
    Matrix[0][1] = -1;
    Matrix[1][1] = 0;
    matrixMul(Matrix,c-2);
}