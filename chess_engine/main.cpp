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

// int queenmovesx[] = {+1,+2,+3,+1,+2,+3,-1,-2,-3,-1,-2,-3}
// int queenmovesy[] = {}

bool whitewin(int chance,int m,char** Board) {
  
    //   for (int i=0; i<4; i++) {
    //     for (int j=0;j<4; j++) {
    //         cout<<Board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<m<<"\n";

    int i,j;
    if (m<=0) return false;
    if (chance == 0) // white chance
    {

        for (int row=0; row<4; row++) {
            for (int col=0; col<4; col++) {
                if (Board[row][col] == 'Q') {
                    i = row-1;
                    j = col-1;
                    while(i>=0 && j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i--,j--;
                    }

                    i = row+1;
                    j = col+1;
                    while(i<4 && j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++,j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i++,j++;
                    }

                    i = row+1;
                    j = col-1;
                    while(i<4 && j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++,j--;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i++,j--;
                    }

                    i = row-1;
                    j = col+1;
                    while(i>=0 && j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i--,j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i--,j++;
                    }
                    
                    i = row+1;
                    j = col;
                    while(i<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i++;
                    }
                    
                    i = row;
                    j = col+1;
                    while(j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        j++;
                    }
                    
                    i = row-1;
                    j = col;
                    while(i>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i--;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        i--;
                    }

                    i = row;
                    j = col-1;
                    while(j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            j--;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'Q';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'Q';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'Q';
                        if (Board[i][j] != '.') break;
                        j--;
                    }

                }

                else if(Board[row][col] == 'P') {
                    i=row+1;
                    j=col+1;
                    if (i<4 && j<4) {
                        if (Board[i][j] == '.'){}
                        else if (Board[i][j] == 'q') return true;
                        else if (Board[i][j] >=65 && Board[i][j] <=90) {}
                        else if (i==3) {
                            char store = Board[i][j];
                            Board[i][j] = 'B';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'N';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'R';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'P';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }                    
                    }
                    i=row+1;
                    j=col-1;
                    if (i<4 && j>=0) {
                        if (Board[i][j] == '.'){}
                        else if (Board[i][j] == 'q') return true;
                        else if (Board[i][j] >=65 && Board[i][j] <=90){}
                        else if (i==3) {
                            char store = Board[i][j];
                            Board[i][j] = 'B';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'N';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'R';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'P';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }                    
                    }


                    i=row+1;
                    j=col;
                    if (i<4) {
                        if (Board[i][j] != '.'){}
                        // else if (Board[i][j] == 'q') return true;
                        else if (Board[i][j] >=65 && Board[i][j] <=90) {}
                        else if (i==3) {
                            char store = Board[i][j];
                            Board[i][j] = 'B';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'N';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';


                            Board[i][j] = 'R';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'P';
                            Board[row][col] = '.';
                            if (whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'P';
                                return true;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'P';
                        }                    
                    }
                }

                else if (Board[row][col] == 'B') {
                    i = row-1;
                    j = col-1;
                    while(i>=0 && j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'B';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'B';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'B';
                        if (Board[i][j] != '.') break;
                        i--,j--;
                    }

                    i = row+1;
                    j = col+1;
                    while(i<4 && j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++,j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'B';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'B';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'B';
                        if (Board[i][j] != '.') break;
                        i++,j++;
                    }

                    i = row+1;
                    j = col-1;
                    while(i<4 && j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++,j--;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'B';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'B';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'B';
                        if (Board[i][j] != '.') break;
                        i++,j--;
                    }

                    i = row-1;
                    j = col+1;
                    while(i>=0 && j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i--,j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'B';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'B';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'B';
                        if (Board[i][j] != '.') break;
                        i--,j++;
                    }
            }


                else if (Board[row][col] == 'R') {
                    
                    i = row+1;
                    j = col;
                    while(i<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            i++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'R';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'R';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'R';
                        if (Board[i][j] != '.') break;
                        i++;
                    }
                    
                    i = row;
                    j = col+1;
                    while(j<4) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            j++;
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'R';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'R';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'R';
                        if (Board[i][j] != '.') break;
                        j++;
                    }
                    
                    i = row-1;
                    j = col;
                    // cout<<m<<" "<<i<<" "<<j<<endl;
                    while(i>=0) {
                        if (Board[i][j] == 'q') return true;
                        // cout<<m<<" returning false\n";
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'R';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'R';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'R';
                        if (Board[i][j] != '.') break;
                        i--;
                    }

                    i = row;
                    j = col-1;
                    while(j>=0) {
                        if (Board[i][j] == 'q') return true;
                        if (Board[i][j] >= 65 && Board[i][j] <=90){
                            break;
                        }
                        char store = Board[i][j];
                        Board[i][j] = 'R';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[i][j] = store;
                            Board[row][col] = 'R';
                            return true;
                        }
                        Board[i][j] = store;
                        Board[row][col] = 'R';
                        if (Board[i][j] != '.') break;
                        j--;
                    }

                }

                else if (Board[row][col] == 'N') {
                    for(int it=0; it<8; it++) {
                        if (row+knightmovesx[it]<0 || row+knightmovesx[it]>=4 || col+knightmovesy[it]<0 || col+knightmovesy[it]>=4) continue;
                        if (Board[row+knightmovesx[it]][col+knightmovesy[it]] == 'q') return true;
                        if (Board[row+knightmovesx[it]][col+knightmovesy[it]] >= 65 && Board[row+knightmovesx[it]][col+knightmovesy[it]] <=90){
                            continue;
                        }
                        char store = Board[row+knightmovesx[it]][col+knightmovesy[it]];
                        Board[row+knightmovesx[it]][col+knightmovesy[it]] = 'N';
                        Board[row][col] = '.';
                        if (whitewin(chance^1,m-1,Board)){
                            Board[row][col] = 'N';
                            Board[row+knightmovesx[it]][col+knightmovesy[it]] = store;
                            return true;
                        }
                        Board[row][col] = 'N';
                        Board[row+knightmovesx[it]][col+knightmovesy[it]] = store;
                    }
                }

            }

        }

    
        // cout<<m<<" returning false\n";
        return false;
    }
    for (int row=0; row<4; row++) {
        for (int col=0; col<4; col++) {
            if (Board[row][col] == 'q') {
                i = row-1;
                j = col-1;
                while(i>=0 && j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--,j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i--,j--;
                }

                i = row+1;
                j = col+1;
                while(i<4 && j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++,j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i++,j++;
                }

                i = row+1;
                j = col-1;
                while(i<4 && j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++,j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i++,j--;
                }

                i = row-1;
                j = col+1;
                while(i>=0 && j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--,j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i--,j++;
                }
                
                i = row+1;
                j = col;
                while(i<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i++;
                }
                
                i = row;
                j = col+1;
                while(j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    j++;
                }
                
                i = row-1;
                j = col;
                while(i>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    i--;
                }

                i = row;
                j = col-1;
                while(j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'q';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'q';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'q';
                    if (Board[i][j] != '.') break;
                    j--;
                }

            }

            else if(Board[row][col] == 'p') {
                    i=row-1;
                    j=col+1;
                    if (i>=0 && j<4) {
                        if (Board[i][j] == '.'){}
                        else if (Board[i][j] == 'Q') return false;
                        else if (Board[i][j] >=97 && Board[i][j] <=122){}
                        else if (i==0) {
                            char store = Board[i][j];
                            Board[i][j] = 'b';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'n';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'r';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'p';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }                    
                    }

                    i=row-1;
                    j=col-1;
                    if (i>=0 && j>=0) {
                        if (Board[i][j] == '.'){}
                        else if (Board[i][j] == 'Q') return false;
                        else if (Board[i][j] >=97&& Board[i][j] <=122){}
                        else if (i==0) {
                            char store = Board[i][j];
                            Board[i][j] = 'b';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'n';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'r';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'p';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }                    
                    }

                    i=row-1;
                    j=col;
                    if (i>=0) {
                        if (Board[i][j] != '.'){}
                        // else if (Board[i][j] == 'Q') return false;
                        else if (Board[i][j] >=97&& Board[i][j] <=122){}
                        else if (i==0) {
                            char store = Board[i][j];
                            Board[i][j] = 'b';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'n';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';


                            Board[i][j] = 'r';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }
                        else {
                            char store= Board[i][j];
                            Board[i][j] = 'p';
                            Board[row][col] = '.';
                            if (!whitewin(chance^1,m-1,Board)){
                                Board[i][j] = store;
                                Board[row][col] = 'p';
                                return false;
                            }
                            Board[i][j] = store;
                            Board[row][col] = 'p';
                        }                    
                    }
                    
                    

                }


            else if (Board[row][col] == 'b') {
                i = row-1;
                j = col-1;
                while(i>=0 && j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--,j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'b';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'b';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'b';
                    if (Board[i][j] != '.') break;
                    i--,j--;
                }

                i = row+1;
                j = col+1;
                while(i<4 && j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++,j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'b';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'b';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'b';
                    if (Board[i][j] != '.') break;
                    i++,j++;
                }

                i = row+1;
                j = col-1;
                while(i<4 && j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++,j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'b';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'b';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'b';
                    if (Board[i][j] != '.') break;
                    i++,j--;
                }

                i = row-1;
                j = col+1;
                while(i>=0 && j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--,j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'b';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'b';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'b';
                    if (Board[i][j] != '.') break;
                    i--,j++;
                }
        }


            else if (Board[row][col] == 'r') {
                
                i = row+1;
                j = col;
                while(i<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'r';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'r';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'r';
                    if (Board[i][j] != '.') break;
                    i++;
                }
                
                i = row;
                j = col+1;
                while(j<4) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        j++;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'r';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'r';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'r';
                    if (Board[i][j] != '.') break;
                    j++;
                }
                
                i = row-1;
                j = col;
                while(i>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        i--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'r';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'r';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'r';
                    if (Board[i][j] != '.') break;
                    i--;
                }

                i = row;
                j = col-1;
                while(j>=0) {
                    if (Board[i][j] == 'Q') return false;
                    if (Board[i][j] >=97 && Board[i][j] <= 122) {
                        j--;
                        break;
                    }
                    char store = Board[i][j];
                    Board[i][j] = 'r';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        Board[i][j] = store;
                        Board[row][col] = 'r';
                        return false;
                    }
                    Board[i][j] = store;
                    Board[row][col] = 'r';
                    if (Board[i][j] != '.') break;
                    j--;
                }

            }

            else if (Board[row][col] == 'n') {
                for(int it=0; it<8; it++) {
                    if (row+knightmovesx[it]<0 || row+knightmovesx[it]>=4 || col+knightmovesy[it]<0 || col+knightmovesy[it]>=4) continue;
                    if (Board[row+knightmovesx[it]][col+knightmovesy[it]] >=97 && Board[row+knightmovesx[it]][col+knightmovesy[it]] <=122) {
                        continue;
                    }
                    if (Board[row+knightmovesx[it]][col+knightmovesy[it]] == 'Q') return false;
                    char store = Board[row+knightmovesx[it]][col+knightmovesy[it]];
                    Board[row+knightmovesx[it]][col+knightmovesy[it]] = 'n';
                    Board[row][col] = '.';
                    if (!whitewin(chance^1,m-1,Board)){
                        
                        Board[row][col] = 'n';
                        Board[row+knightmovesx[it]][col+knightmovesy[it]] = store;
                        return false;
                    }
                    Board[row][col] = 'n';
                    Board[row+knightmovesx[it]][col+knightmovesy[it]] = store;
                }
            }
        }

    }
    return true;
}
    


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    char** Board = new char*[4];
    // vector<vector<char> > Board(4,vector<char>(4));
    for (int i=0; i<4; i++) {
        Board[i] = new char[4];
        for (int j=0; j<4; j++) {
            Board[i][j] = '.';
        }
    }
    int g,w,b,m;
    cin>>g;
    char piece,col;
    int row;
    int _g = g;
    while(g--) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                Board[i][j] = '.';
            }
        }
        cin>>w>>b>>m;
        // if (_g-g == 66)cout<<w<<" "<<b<<" "<<m<<'\n';
        // m=5;
        loop(i,0,w) {
            cin>>piece>>col>>row;
            // trace3(piece,col-'A',row-1);
            // if (_g-g == 66)cout<<piece<<" "<<col<<" "<<row<<'\n';
            Board[row-1][col-'A'] = piece;
        }

        loop(i,0,b) {
            cin>>piece>>col>>row;
            // trace3(piece,col-'A',row-1);
            // if (_g-g == 66)cout<<piece<<" "<<col<<" "<<row<<'\n';
            Board[row-1][col-'A']= piece+32;
        }


        // if (_g-g != 66) {
            // continue;
        // }

        // for (int i=0; i<4; i++) {
        //     for (int j=0; j<4; j++) {
        //         cout<<Board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        if(whitewin(0,m,Board)){
            // cout<<_g-g;
            cout<<"YES\n";
        }
        else {
            // cout<<_g-g;
            cout<<"NO\n";
        }
    }
    return 0;
}
