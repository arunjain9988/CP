#include <iostream>  // This will work only for g++ compiler. 
#include <cmath>


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
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef long long ll;
// typedef vector<ll> vll;
// typedef vector<vll> vvll;
// typedef double ld;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    double r1,r2,s1,s2,total_time,d;
    cin>>r1>>r2>>s1>>s2>>total_time>>d;
    double cosalpha,alpha;
    cosalpha = ((r1*r1)+(r2*r2)-(d*d))/(2*r1*r2);
    alpha = acos(cosalpha);
    double theta1,theta2,sintheta1,sintheta2;
    sintheta1 = (r2/d)*sin(alpha);
    sintheta2 = (r1/d)*sin(alpha);
    // cout<<sintheta1<<endl;
    theta1 = asin(sintheta1);
    theta2 = asin(sintheta2);
    theta1 *= 2;
    theta2 *= 2;
    theta1 = theta1*(180/M_PI);
    theta2 = theta2*(180/M_PI);
    double arc1 = 2*M_PI*r1*(theta1/360);
    double arc2 = 2*M_PI*r2*(theta2/360);
    // cout<<arc1/s1<<endl<<arc2/s2<<endl;
    double t1time = (2*M_PI*r1)/s1;
    double t2time = (2*M_PI*r2)/s2;
    // vector<double> m1points_e;
    // vector<double> m2points_e;
    // vector<double> m1points_f;
    // vector<double> m2points_f;
    double cur1 = t1time, cur2 = arc2/s2;
    int found = -1;
    string dir;
    while(cur1 <= total_time && cur2 <= total_time) {
        // cout<<"time "<<cur1<<" "<<cur2<<endl;
        if ((int)cur1 == (int)cur2) {
            if (found == -1) {
                found = (int)cur1;
                dir.pb('E');
                break;
            }
        }
        else if (cur1 < cur2) {
            cur1 += t1time;
        }
        else {
            cur2 += t2time;
        }
        // m1points_e.pb(cur);
        // cur += t1time;
    }

    cur1 = arc1/s1,cur2 = t2time;

    while(cur1 <= total_time && cur2 <= total_time) {
        // cout<<"time "<<cur1<<" "<<cur2<<endl;
        if ((int)cur1 == (int)cur2) {
            if (found == -1) {
                cout<<(int)cur1<<" F";
                return 0;
            }
            else if (found != -1 && found == (int)cur1) {
                cout<<(int)(cur1)<<" E&F";
                return 0;
            }
            else {
                if (found!=-1 && found>(int)cur1) {
                    found = (int)cur1;
                }
            }
        }


        else if (cur1 < cur2) {
            cur1 += t1time;
        }
        else {
            cur2 += t2time;
        }
        // m1points_e.pb(cur);
        // cur += t1time;
    }


    if (found != -1) {
        cout<<found<<" E";
        return 0;
    }


    cout<<"no crash";
    return 0;


    // cur = arc1/s1;
    // while(cur <= total_time) {
    //     m1points_f.pb(cur);
    //     cur += t1time;
    // }

    // cur = t2time;
    // while(cur <= total_time) {
    //     m2points_e.pb(cur);
    //     cur += t2time;
    // }
    // cur = arc2/s2;
    // while(cur <= total_time) {
    //     m2points_f.pb(cur);
    //     cur += t2time;
    // }




    // for (int i=0; i<m1points_e.size(); i++) {
    //     cout<<m1points_e[i]<<endl;
    // }
    // for (int i=0; i<m2points_e.size(); i++) {
    //     cout<<m2points_e[i]<<endl;
    // }


    // sort(m1points_e.begin(),m1points_e.end());
    // sort(m2points_e.begin(),m2points_e.end());
    // sort(m1points_f.begin(),m1points_f.end());
    // sort(m2points_f.begin(),m2points_f.end());
    // int i=0,j=0;

    // string dir;
    // int found  = -1;

    // while(i<(int)m1points_e.size() && j<(int)m2points_f.size()) {
    //     if (((int)m1points_e[i]) == ((int)m2points_f[j])) {
    //         if (found == -1) {
    //             found = (int)m1points_e[i];
    //             dir.pb('E');
    //             break;
    //         }
    //     }
    //     else if (m1points_e[i] < m2points_f[j]) i++;
    //     else j++;
    // }

    // i=0,j=0;

    // while(i<(int)m1points_f.size() && j<(int)m2points_e.size()) {
    //     if ((int)m1points_f[i] == (int)m2points_e[j]) {
    //         if (found == -1) {
    //             cout<<(int)m1points_f[i]<<" F";
    //             return 0;
    //         }
    //         else if (found != -1 && found == (int)m1points_f[i]) {
    //             cout<<(int)m1points_f[i]<<" E&F";
    //             return 0;
    //         }
    //         else {
    //             if (found!=-1 && found>(int)m1points_f[i]) {
    //                 found = (int)m1points_f[i];
    //             }
    //         }
    //     }
    //     else if (m1points_f[i] < m2points_e[j]) i++;
    //     else j++;
    // }
    // if (found != -1) {
    //     cout<<found<<" F";
    //     return 0;
    // }

    // cout<<"no crash";
    // return 0;
    // return 0;
}
