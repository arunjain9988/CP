#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'r') {
            printf("%d\n",i+1);
        }
    }
    for (int i=s.size()-1; i>=0; i--) {
        if (s[i] == 'l') {
            printf("%d\n",i+1);
        }
    }
    return 0;
}
