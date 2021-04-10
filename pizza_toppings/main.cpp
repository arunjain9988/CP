#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
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
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

// useful constants
#define MOD 1000000007

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

class Pizza{
    public:
        bitset<10000> bs;
        int set_bits;
        set<int> combination_of;
        // int pizza_idx;

        Pizza() {
            set_bits = 0;
            // combination_of.pb(idx);
        }
        // bitset<100> bs;
        
        void bit_set(int idx) {
            if (bs.test(idx)) return;
            bs.set(idx);
            set_bits++;
        }

        Pizza bits_or(Pizza &b) {
            Pizza ret;
            ret.bs = bs | b.bs;
            ret.set_bits = ret.bs.count();
            ret.combination_of.insert(combination_of.begin(),combination_of.end());
            ret.combination_of.insert(b.combination_of.begin(),b.combination_of.end());
            return ret;
        }

        void print() {
            cout<<bs;
        }
};

bool sortPizza(Pizza &a,Pizza &b) {
    return a.set_bits > b.set_bits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("Ain.txt","r",stdin);
    freopen("Aout.txt","w",stdout);
    cout.precision(10);
    cout << fixed;
    int m,t2,t3,t4,k;
    vector<set<int> > answers;
    int teams[5];
    map<string,int> string_to_idx;
    vector<string> idx_to_string;
    int cur_idx = 0;
    string str;
    cin>>m>>teams[2]>>teams[3]>>teams[4];
    Pizza* pizzas = new Pizza[m];
    for (int i=0; i<m; i++) {
        cin>>k;
        Pizza tmp;
        loop(j,0,k) {
            cin>>str;
            if (string_to_idx.find(str) == string_to_idx.end()) {
                string_to_idx[str] = idx_to_string.size();
                idx_to_string.push_back(str);
            }
            tmp.bit_set(string_to_idx[str]);
        }
        tmp.combination_of.insert(i);
        pizzas[i] = tmp;
    }

    sort(pizzas,pizzas+m,sortPizza);
    // for (int i=0; i<m; i++) {
    //     cout<<*pizzas[i].combination_of.begin()<<" ";
    // }
    bool occupied[m];
    memset(occupied,false,sizeof(occupied));
    for (int i=0; i<m; i++) {
        if (occupied[i]) continue;

        if (teams[4] > 0) {
            while(pizzas[i].combination_of.size() <4) {
                int mx = -1;
                Pizza mxpizza;
                int mxpizzaidx = -1;
                for (int j=i+1; (j<m && pizzas[j].set_bits > mx); j++) {
                    if (occupied[j]) continue;
                    Pizza new_pizza = pizzas[i].bits_or(pizzas[j]);
                    if (new_pizza.combination_of.size() > 4) continue;
                    if (new_pizza.set_bits - pizzas[i].set_bits > mx) {
                        mx = new_pizza.set_bits - pizzas[i].set_bits;
                        mxpizza = new_pizza;
                        mxpizzaidx = j;
                    }
                }
                if (mxpizzaidx == -1) {
                    // no pizza found
                    // teams[4] = 0;
                    // i--;
                    break;
                }
                pizzas[i] = mxpizza;
                occupied[mxpizzaidx] = true;
                // if (pizzas[i].combination_of.size() >=4) break;
            }
            if (pizzas[i].combination_of.size() == 4) {
                answers.push_back(pizzas[i].combination_of);
                teams[4]--;
            }
            else {
                i--;
                teams[4] = 0;
                // break;
            }
            // teams[pizzas[i].combination_of.size()]--;
        }

        else if (teams[3] > 0) {
            while(pizzas[i].combination_of.size() <3) {
                int mx = -1;
                Pizza mxpizza;
                int mxpizzaidx = -1;
                for (int j=i+1; (j<m && pizzas[j].set_bits > mx); j++) {
                    if (occupied[j]) continue;
                    Pizza new_pizza = pizzas[i].bits_or(pizzas[j]);
                    if (new_pizza.combination_of.size() > 3) continue;
                    if (new_pizza.set_bits - pizzas[i].set_bits > mx) {
                        mx = new_pizza.set_bits - pizzas[i].set_bits;
                        mxpizza = new_pizza;
                        mxpizzaidx = j;
                    }
                }
                if (mxpizzaidx == -1) break;
                pizzas[i] = mxpizza;
                occupied[mxpizzaidx] = true;
                // if (pizzas[i].combination_of.size() >=4) break;
            }
            if (pizzas[i].combination_of.size() == 3) {
                answers.push_back(pizzas[i].combination_of);
                teams[3]--;
            }
            else {
                i--;
                teams[3] = 0;
            }
            // teams[pizzas[i].combination_of.size()]--;
        }

        else if (teams[2] > 0) {
            while(pizzas[i].combination_of.size() <2) {
                int mx = -1;
                Pizza mxpizza;
                int mxpizzaidx = -1;
                for (int j=i+1; (j<m && pizzas[j].set_bits > mx); j++) {
                    if (occupied[j]) continue;
                    Pizza new_pizza = pizzas[i].bits_or(pizzas[j]);
                    if (new_pizza.combination_of.size() > 2) continue;
                    if (new_pizza.set_bits - pizzas[i].set_bits > mx) {
                        mx = new_pizza.set_bits - pizzas[i].set_bits;
                        mxpizza = new_pizza;
                        mxpizzaidx = j;
                    }
                }
                if (mxpizzaidx == -1) break;
                pizzas[i] = mxpizza;
                occupied[mxpizzaidx] = true;
                // if (pizzas[i].combination_of.size() >=4) break;
            }
            if (pizzas[i].combination_of.size() == 2) {
                answers.push_back(pizzas[i].combination_of);
                teams[2]--;
            }
            else {
                i--;
                teams[2] = 0;
            }
            // teams[pizzas[i].combination_of.size()]--;
        }


    }
    // ll score = 0;
    cout<<answers.size()<<'\n';
    // bitset<10000> tmp;
    for (int k=0; k<answers.size(); k++) {

        // score += tmp*tmp;

        cout<<answers[k].size()<<" ";
        // tmp = 0;
        // tmp.reset();
        for (set<int>::iterator it = answers[k].begin(); it!=answers[k].end(); it++) {
            // tmp |= pizzas[*it].bs;
            cout<<*it<<" ";
        }
        // score += tmp.count()*tmp.count();
        cout<<'\n';
    }
    // cout<<"Score "<<score;
    // for (int i=0; i<m; i++) {
    //     pizzas[i].print();
    //     cout<<endl;
    // }
    return 0;
}
