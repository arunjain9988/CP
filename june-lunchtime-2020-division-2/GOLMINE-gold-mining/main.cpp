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

int t,n;
int G[100005];
int TA[100005];
int TB[100005];
int idxa;
int idxb;
double ansa,ansb;
vector< pair< double, int> > PA;
vector< pair< double, int> > PB;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(5);
    cout << fixed;
    cin>>t;
    while(t--) {
        ansa=0;
        ansb=0;
        cin>>n;
        PA.resize(n);
        PB.resize(n);
        loop(i,0,n) {
            cin>>G[i]>>TA[i]>>TB[i];
            PA[i].first = (double)G[i]/TA[i];
            PA[i].second = i;
            PB[i].first = (double)G[i]/TB[i];
            PB[i].second = i;
        }
        sort(PA.rbegin(),PA.rend());
        sort(PB.rbegin(),PB.rend());
        idxa=idxb=0;
        while(idxa<n && idxb<n) {
            int fidx = PA[idxa].second;
            int sidx = PB[idxb].second;
            if (PA[idxa].second == PB[idxb].second) {
                double time = (double)G[fidx]/(PA[idxa].first+PB[idxb].first);
                ansa += (PA[idxa].first * time);
                ansb += (PB[idxb].first * time);
                idxa++;idxb++;
            }
            else{
                if (TA[fidx]<TB[sidx]) {
                    ansa += G[fidx];
                    G[fidx] = 0;
                    TA[fidx] = 0;
                    TB[fidx]=0; 
                    ansb += PB[sidx].first * TA[fidx];
                    TB[sidx] -= TA[fidx];
                    G[sidx] -= PA[sidx].first * TA[fidx];
                    idxa++;
                }
                else {
                    ansb += G[sidx];
                    G[sidx] = 0;
                    TB[sidx] = 0;
                    TA[sidx]=0;
                    ansa += PA[fidx].first * TB[sidx];
                    TA[fidx] -= TB[sidx];
                    G[fidx] -= PA[fidx].first * TB[sidx];
                    idxb++;
                }
            }
        }
        while(idxa<n) {
            int tt = PA[idxa].second;
            ansa += G[tt];
            idxa++;
        }
        while(idxb<n) {
            int tt = PB[idxb].second;
            ansb += G[tt];
            idxb++;
        }
        cout<<ansa<<" "<<ansb<<'\n';
    }
    return 0;
}
