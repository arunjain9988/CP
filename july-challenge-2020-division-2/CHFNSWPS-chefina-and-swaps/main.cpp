#include <bits/stdc++.h>  // This will work only for g++ compiler. 


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

ll t,n;
ll ai,bi;
ll aj,bj;
ll a,b;
multiset<ll> s1;
multiset<ll> s2;
vector<ll> v1;
vector<ll> v2;
ll ans;
vector<ll> an;
ll minin,minout;
ll totalmin;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>t;
    while(t--) {
        cin>>n;
        v1.clear();
        v2.clear();
        s1.clear();
        s2.clear();
        // v1.reserve(n);
        // v2.reserve(n);
        an.clear();
        loop(i,0,n) {
            cin>>a;
            v1.pb(a);
        }
        loop(i,0,n) {
            cin>>b;
            v2.pb(b);
        }
        sort(all(v1));
        sort(all(v2));
        ll indx1=0;
        ll indx2=0;
        ans=0;
        minin = 10000000008;
        minout = 10000000008;
        while(indx1<n && indx2<n) {
            if (v1[indx1]<v2[indx2]){
                s1.insert(v1[indx1]);
                minin = min(minin,v1[indx1]);
                indx1++;
            }
            else if (v1[indx1]>v2[indx2]) {
                s2.insert(v2[indx2]);
                minin = min(minin,v2[indx2]);
                indx2++;
            }
            else {
                minout = min(minout,v1[indx1]);
                indx1++;
                indx2++;
            }

        }
        while(indx1<n){ s1.insert(v1[indx1]); minin = min(minin,v1[indx1]); indx1++; }
        while(indx2<n){ s2.insert(v2[indx2]); minin = min(minin,v2[indx2]); indx2++; }
        // cout<<s1.size()<<" "<<s2.size()<<'\n';
        if (s1.size()%2 || s2.size()%2){
            cout<<-1<<'\n';
            continue;
        }
        auto it1=s1.begin();
        bool find=false;
        while(it1!=s1.end()) {
            ai = *it1;
            it1++;
            aj = *it1;
            it1++;
            if (ai!=aj){
                cout<<-1<<'\n';
                find=true;
                break;
            }
            an.pb(ai);
        }

        if (find) continue;
        find=false;
        auto it2 = s2.begin();
        while(it2!=s2.end()) {
            bi = *it2;
            it2++;
            bj = *it2;
            it2++;
            if (bi!=bj){
                cout<<-1<<'\n';
                find=true;
                break;
            }
            an.pb(bi);
        }
        // ll sz= s1.size()/2;
        // loop(i,0,sz) {
        //     if (ai!=aj || bi!=bj){
        //         cout<<-1<<'\n';
        //         find=true;
        //         break;
        //     }
        //     ans+= min(ai,bi);
        // }
        if (find) continue;
        if (an.empty()) {
            cout<<0<<'\n';
            continue;
        }
        ans=0;
        sort(all(an));
        auto it=an.begin();
        totalmin=min(minin,minout);
        // ll sz = an.size()-1;
        auto end = an.end();
        while(*it <= 2*totalmin && it<end) {
            ans += *it;
            it++;
            end--;
        }
        ans+= (end-it)*totalmin;
        // sz = an.size()/2;
        // loop(i,0,sz) {
        //     ans+= *it;
        //     it++;
        // }
        cout<<ans<<'\n';
    }    
    return 0;
}
