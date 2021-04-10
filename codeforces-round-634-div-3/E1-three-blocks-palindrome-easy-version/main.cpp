#include <bits/stdc++.h>
using namespace std;
#define test(t) int t;cin>>t; while(t--)
#define num(n) long long n; cin>>n
#define str(s) string s; cin>>s
#define arr(a,n) vector<long long> a(n); for(long long i=0;i<n;i++) {cin>>a[i];}
#define aout(a,i) for(int i=0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl
#define loop(i,m,n) for(long long i=m;i<n;i++)
#define rloop(i,m,n) for(long long i=n-1;i>=m;i--)
#define de(n) cout<<n<<endl
#define ok ios_base::sync_with_stdio(0); cin.tie(NULL)

long long mcountFreq(vector<long long> arr)
{
    if(arr.size()==0){return 0;}
    unordered_map<long long, long long> mp;

    // Traverse through array elements and
    // count frequencies
    for (long long i = 0; i < arr.size(); i++)
        mp[arr[i]]++;

    vector<long long> frq;
    // Traverse through map and print frequencies
    for (auto x : mp)
        frq.push_back(x.second);

    return *max_element(frq.begin(),frq.end());
}

int main()
#define int long long
{


    freopen("/tests/1.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ok;
    test(t)
    {
        num(n);
        arr(a,n);

        vector<vector<int>> pos(26);
        loop(i,0,n)
        {
            pos[a[i]-1].push_back(i);
        }

        int ans = 1;
        loop(i,0,26)
        {
            loop(j,0,pos[i].size()/2)
            {
                // cout<<"posse: "<<pos[i][j]<<" "<<pos[i][pos[i].size()-j-1]<<endl;
                // cout<<"m:"<<mcountFreq(vector<int>(a.begin() + pos[i][j]+1, a.begin() + pos[i][pos[i].size()-j-1]))<<endl;
                // cout<<"j:"<<j<<endl;
                ans = max(ans,2*(j+1)+mcountFreq(vector<int>(a.begin() + pos[i][j]+1, a.begin() + pos[i][pos[i].size()-j-1])));
            }
        }
       
       cout<<ans<<endl;
    }


    return 0;
}

/*
Explain:

*/