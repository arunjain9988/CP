#include <bits/stdc++.h>
using namespace std;

minstd_rand rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T> T randint(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }
template <typename T> T uniform(T a, T b) { return uniform_real_distribution<T>(a, b)(rng); }

// 💻 Here in test-generator.cpp, write code that prints one random test input with cout/printf. 💻
// 💡 Then, press Alt+F9 to have ICIE automatically test your solution on thousands of tests! 💡
// 😕 How to randomize a dice roll: int dice = randint<int>(1, 6); 😕
// 😕 How to randomize a probability: double probability = uniform<double>(0., 1.); 😕

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("tests/user/6.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = randint<int>(1,200000);
    int q = randint<int>(1,200000);
    cout<<n<<" "<<q<<'\n';
    for(int i=0;i<n;i++) {
        int h = randint<int>(1,1000000000);
        cout<<h<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++) {
        int a = randint<int>(1,1000000000);
        cout<<a<<" ";
    }
    cout<<'\n';
    for(int i=0;i<q;i++) {
        int a = randint<int>(1,2);
        if (a==1) {
            int b = randint<int>(1,n);
            int k = randint<int>(1,INT_MAX-5);
            cout<<a<<" "<<b<<" "<<k<<'\n';
        }
        else {
            int b = randint<int>(1,n);
            int c = randint<int>(b-50,b+50);
            cout<<a<<" "<<b<<" "<<c<<'\n';
        }
    } 

}
