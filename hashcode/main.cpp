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

class Street{
    public:
        string street_name;
        // int street_id;
        int street_time;
        int no_of_cars_pass;

        Street(string sname,int stime){
            street_name = sname;
            street_time = stime;
            no_of_cars_pass = 0;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    freopen("a.txt", "r", stdin);
    freopen("aoutt.txt", "w", stdout);
    int d,I,s,v,f;
    string stmp;
    cin>>d>>I>>s>>v>>f;
    map<string,Street*> street_find;
    // vector<Street> idx_to_street;
    int b,e,l;
    vector<Street*> incoming_streets[I];
    int street_time[s];
    for (int i=0;i<s; i++) {
        cin>>b>>e>>stmp>>l;
        Street* tmpstreet = new Street(stmp,l);
        street_find[stmp] = tmpstreet;
        incoming_streets[e].pb(tmpstreet);
    }

    ll car_time[v];
    memset(car_time,0,sizeof(car_time));

    int p;

    vector<Street*> car_streets[v];

    for (int i=0; i<v; i++) {
        cin>>p;
        while(p--) {
            cin>>stmp;
            street_find[stmp]->no_of_cars_pass++;
            car_streets[i].push_back(street_find[stmp]);
            // cout<<street_find[stmp]->street_name<<" "<<street_find[stmp]->no_of_cars_pass<<'\n';
            car_time[i] += street_find[stmp]->street_time;
        }
    }

    // for (int i=0; i<v; i++) {
    //     if (car_time[i] > d) {
    //         for (int j=0; j<car_streets[i].size(); j++) {
    //             car_streets[i][j]->no_of_cars_pass = max(car_streets[i][j]->no_of_cars_pass-1,0);
    //         }
    //     } 
    // }

    vector<pair<int, vector<Street*> > > answers;
    for (int i=0; i<I; i++) {
        ll total = 0;
        // ll total_cars = 0;
        pair<int, vector<Street*> > ttt;
        vector<Street*> stt;
        for (int j=0; j<incoming_streets[i].size(); j++) {
            if (incoming_streets[i][j]->no_of_cars_pass == 0) continue;
            total += incoming_streets[i][j]->no_of_cars_pass;
            stt.push_back(incoming_streets[i][j]);
        }
        if (stt.empty()) continue;
        total /= stt.size();
        
        for (int j=0; j<stt.size(); j++) {
            stt[j]->no_of_cars_pass = (stt[j]->no_of_cars_pass+total-1)/total;
            stt[j]->no_of_cars_pass = ((stt[j]->no_of_cars_pass)+(stt[j]->street_time)-1)/stt[j]->street_time;
            if (stt[j]->no_of_cars_pass == 0) stt[j]->no_of_cars_pass = 1;
        }
        answers.push_back(make_pair(i,stt));
        // if (ttt.empty()) continue;
        // answers.push_back(ttt);
        
    }

    cout<<answers.size()<<'\n';
    for (int i=0; i<answers.size(); i++) {
        cout<<answers[i].first<<'\n'<<answers[i].second.size()<<'\n';
        for (int j=0; j<answers[i].second.size(); j++) {
            cout<<answers[i].second[j]->street_name<<" "<<answers[i].second[j]->no_of_cars_pass<<"\n";
        }
    }
    return 0;
}
