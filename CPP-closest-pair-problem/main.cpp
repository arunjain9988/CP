#include <bits/stdc++.h>
#define print(__print__var) cout<<__print__var<<'\n';
#define input(__input__var) cin>>__input__var;
#define fo(i,a,b) for(int i=a; i<b; i++)

typedef long long ll;
using namespace std;

struct Point{
    int x,y;
    Point(){}
    Point(int x, int y) : x(x), y(y) { }
};

bool operator<(Point a,Point b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

double dis(Point a, Point b) {
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    Point points[n];
    fo(i,0,n) {
        cin>>points[i].x>>points[i].y;
    }    

    double best = 1e5;
    set<Point> working;
    for (int p=0; p<n; p++) {
        auto itr = working.begin();
        while(itr!=working.end() && points[p].x - itr->x >= best){
            working.erase(itr);
            itr = working.begin();
        }
        for (auto i: working) {
            best = min(best,dis(points[p],i));
        }
        working.insert(points[p]);
    }
    cout<<best;
    return 0;
}
