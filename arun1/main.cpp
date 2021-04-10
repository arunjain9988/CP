#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

bool isPrime(int a){
    for (int i=2; i*i<=a; i++) {
        if (a%i==0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char res[10];
    int count = 0;
    for (int i=2; i<=50; i++) {
        if (isPrime(i)) {#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    
    return 0;
}
            printf("%d\n",i);
            fflush(stdout);
            scanf("%s",res);
            if (res[0] == 'y') {
                count++;
            }
            if (i*i<=50) {
                printf("%d\n",i*i);
                fflush(stdout);
                scanf("%s",res);
                if (res[0] == 'y') {
                count++;
            }
            }
        }
        if (count >=2 ) {
            printf("composite");
            fflush(stdout);
            return 0;
        }
    }
    printf("prime");
    fflush(stdout);
    return 0;
}
