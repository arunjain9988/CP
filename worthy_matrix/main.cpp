#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,n,m,k;
vector<vector<ll> > matrix;
vector<vector<ll> > sum;

bool get_sum(int sr,int sc,int er,int ec) {
	ll cells = (er-sr+1)*(ec-sc+1);
	if (sr==0 && sc==0) {
		return sum[er][ec] >=0;
	}
	if (sr==0) {
		return (sum[er][ec] - sum[er][sc-1]) >=0;
	}
	if (sc==0) {
		return (sum[er][ec] - sum[sr-1][ec]) >=0;
	}
	return (sum[er][ec] - sum[er][sc-1] - sum[sr-1][ec] + sum[sr-1][sc-1]) >=0;
}

int main(){
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		matrix = vector<vector<ll> >(n,vector<ll>(m,0));
		sum = vector<vector<ll> >(n,vector<ll>(m,0));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin>>matrix[i][j];
				matrix[i][j] -=k;
				sum[i][j] = matrix[i][j];
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=1; j<m; j++) {
				sum[i][j] += sum[i][j-1];
			}
		}
		for (int j=0; j<m; j++) {
			for (int i=1; i<n; i++){
				sum[i][j] += sum[i-1][j];
			}
 		}
		// for (int i=0; i<n; i++){
		// 	for (int j=0; j<m; j++) {
		// 		cout<<sum[i][j]<<' ';
		// 	}
		// 	cout<<'\n';
		// }
 		ll ans = 0;
 		for (int r=n-1,c=0; c<m; c++) {
			int tr = r;
			int tc = c;
 			int less = min(r,c);
 			int sr = r-less;
 			int sc = c-less;
 			while(r>=sr && c>=sc) {
 				while(r>=sr && c>=sc && !get_sum(sr,sc,r,c)) {
 					sr++,sc++;
 				}
				if (r<sr || c<sc) break;
				// cout<<sr<<' '<<sc<<' '<<r<<' '<<c<<' ';
				// cout<<ans<<'\n';
 				ans += (r-sr+1);
 				r--;
 				c--;
 			}
			 r=tr;
			 c=tc;
 		}

		 
 		for (int r=0,c=m-1; r<n-1; r++) {
			int tr = r;
			int tc = c;
 			int less = min(r,c);
 			int sr = r-less;
 			int sc = c-less;
 			while(r>=sr && c>=sc) {
 				while(r>=sr && c>=sc && !get_sum(sr,sc,r,c)) {
 					sr++,sc++;
 				}
				if (r<sr || c<sc) break;
				// cout<<sr<<' '<<sc<<' '<<r<<' '<<c<<' ';
				// cout<<ans<<'\n';
 				ans += (r-sr+1);
 				r--;
 				c--;
 			}
			 r=tr;
			 c=tc;
 		}
 		cout<<ans<<'\n';
	}
	return 0;
}