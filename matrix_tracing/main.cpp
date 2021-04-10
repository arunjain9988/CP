#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long fact[2000000+2];
long long inverse_fact[1000000+3];

vector<int> extendedEuclid(int a,int b) {
    // if (b>a) swap(a,b);
    vector<int> res(3,0);
    if (b==0) {
        res[0] = a;
        res[1] = 1;
        return res;
    }
    vector<int> res1 = extendedEuclid(b, a%b);
    res[0] = res1[0];
    res[1] = res1[2];
    res[2]  = res1[1] - ((a/b)*res1[2]);
    return res;
}

long long inverseModulo(int a,int m) {
    vector<int> t = extendedEuclid(a,m);
    return (t[1]+m)%m;
}

void pre(){
    fact[0] = 1;
    for (int i=1; i<=2000000; i++) {
        fact[i] = (i*fact[i-1])%MOD;
    }
    inverse_fact[0] = 1;
    inverse_fact[1] = 1;
    for (int i=2; i<=1000000; i++) {
        inverse_fact[i] = (inverse_fact[i-1]*inverseModulo(i,MOD))%MOD;
    }
}

vector<string> split_string(string);

// Complete the solve function below.
int solve(int n, int m) {
    // calculate m+n-2 choose m-1
    // return inverseModulo(n, m);
    return ((((long long)fact[m+n-2] * inverse_fact[m-1])%MOD) * inverse_fact[n-1])%MOD;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pre();
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        int result = solve(n, m);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
