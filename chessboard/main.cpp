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


int knightmovesx[] = {+2,+2,-2,-2,+1,+1,-1,-1};
int knightmovesy[] = {+1,-1,+1,-1,+2,-2,+2,-2};

int kingmovesx[] = {-1,-1,-1,1,1,1,0,0};
int kingmovesy[] = {-1,0,1,-1,0,1,1,-1};

vector<int> ninjaChess2021(string king, string ninja) {
    int Board[8][8];
    memset(Board,0,sizeof(Board));
    // 1 = whiteking block
    // 2 = blackqueen attack
    int ninjarow = ninja[1]-'1';
    int ninjacol = ninja[0]-'a';
    int kingrow = king[1]-'1';
    int kingcol = king[0]-'a';
    // cout<<ninjarow<<ninjacol<<kingrow<<kingcol;
    // trace4(ninjarow,ninjacol,kingrow,kingcol);
    int i,j;


    i = ninjarow-1;
    j = ninjacol-1;
    while(i>=0 && j>=0) {
        Board[i][j] = 2;
        i--,j--;
    }

    i = ninjarow+1;
    j = ninjacol+1;
    while(i<8 && j<8) {
        Board[i][j] = 2;
        i++,j++;
    }

    i = ninjarow+1;
    j = ninjacol-1;
    while(i<8 && j>=0) {
        Board[i][j] = 2;
        i++,j--;
    }

    i = ninjarow-1;
    j = ninjacol+1;
    while(i>=0 && j<8) {
        Board[i][j] = 2;
        i--,j++;
    }
    
    i = ninjarow+1;
    j = ninjacol;
    while(i<8) {
        Board[i][j] = 2;
        i++;
    }
    
    i = ninjarow;
    j = ninjacol+1;
    while(j<8) {
        Board[i][j] = 2;
        j++;
    }
    
    i = ninjarow-1;
    j = ninjacol;
    while(i>=0) {
        Board[i][j] = 2;
        i--;
    }

    i = ninjarow;
    j = ninjacol-1;
    while(j>=0) {
        Board[i][j] = 2;
        j--;
    }

    for(int it=0; it<8; it++) {
        if (ninjarow+knightmovesx[it]<0 || ninjarow+knightmovesx[it]>=8 || ninjacol+knightmovesy[it]<0 || ninjacol+knightmovesy[it]>=8) continue;
        Board[ninjarow+knightmovesx[it]][ninjacol+knightmovesy[it]] = 2;
    }
    Board[ninjarow][ninjacol] = 0;

    Board[kingrow][kingcol] = 1;

    i = kingrow-1;
    j = kingcol-1;
    if(i>=0 && j>=0) {
        Board[i][j] = 1;
        i--,j--;
    }

    i = kingrow+1;
    j = kingcol+1;
    if(i<8 && j<8) {
        Board[i][j] = 1;
        i++,j++;
    }

    i = kingrow+1;
    j = kingcol-1;
    if(i<8 && j>=0) {
        Board[i][j] = 1;
        i++,j--;
    }

    i = kingrow-1;
    j = kingcol+1;
    if(i>=0 && j<8) {
        Board[i][j] = 1;
        i--,j++;
    }
    
    i = kingrow+1;
    j = kingcol;
    if(i<8) {
        Board[i][j] = 1;
        i++;
    }
    
    i = kingrow;
    j = kingcol+1;
    if(j<8) {
        Board[i][j] = 1;
        j++;
    }
    
    i = kingrow-1;
    j = kingcol;
    if(i>=0) {
        Board[i][j] = 1;
        i--;
    }

    i = kingrow;
    j = kingcol-1;
    if(j>=0) {
        Board[i][j] = 1;
        j--;
    }

    // Board[ninjarow][ninjacol] = 1;

    vector<int> ans(4,0);
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (i==ninjarow && j==ninjacol) continue;
            if (Board[i][j] == 2){
                int done = false;
                for (int k=0; k<8; k++) {
                    if (i+kingmovesx[k] >=0 && i+kingmovesx[k]<8 && j+kingmovesy[k]>=0 && j+kingmovesy[k]<8) {
                        if (Board[i+kingmovesx[k]][j+kingmovesy[k]] == 0) {
                            done = true;
                        }
                    }
                }
                if (done) {
                    ans[1]++;
                }
                else {
                    ans[0]++;
                }
            }
            else if (Board[i][j] == 0) {
                int done = false;
                for (int k=0; k<8; k++) {
                    if (i+kingmovesx[k] >=0 && i+kingmovesx[k]<8 && j+kingmovesy[k]>=0 && j+kingmovesy[k]<8) {
                        if (Board[i+kingmovesx[k]][j+kingmovesy[k]] == 0) {
                            done = true;
                        }
                    }
                }
                if (done) {
                    ans[3]++;
                }
                else {
                    ans[2]++;
                }
            }
        }
    }
    // for (int i=7; i>=0; i--) {
    //     for (int j=0; j<8; j++) {
    //         cout<<Board[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> ans = ninjaChess2021("d3","e4");
    for (auto u:ans) {
        cout<<u<<" ";
    }
    return 0;
}
