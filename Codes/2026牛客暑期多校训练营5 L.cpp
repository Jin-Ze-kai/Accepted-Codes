// Problem: Matrix
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133880/L
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	int pre=-inf;
	bool ok=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
			if (pre != -inf and pre != a[i][j]) ok=0;
			pre=a[i][j];
		}
	}
	
	if (ok) {cout<<"0\n";return;}
	else if (n == 1 or m == 1) {cout<<"-1\n";return;}
	
	int x=a[0][1]+a[1][0]-a[0][0];
	int ans=x-a[0][0];
	vector b(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			b[i][j]=x-a[i][j];
			if (b[i][j] < 0) {
				cout<<"-1\n";
				return;
			}
		}
	}
	a=b;
	
	for(int k=0;k<n+m-1;k++) {
		for(int i=0;i<n;i++) {
			int j=k-i;
			if (j >= m) continue;
			if (j < 0) break;
			if (i-1 >= 0) {
				int minx=min(a[i-1][j],b[i][j]);
				a[i-1][j]-=minx;
				b[i][j]-=minx;
			}
			if (j-1 >= 0) {
				int minx=min(a[i][j-1],b[i][j]);
				a[i][j-1]-=minx;
				b[i][j]-=minx;
			}
		}
	}
	
	// cout<<"\n";
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<m;j++) {
			// cout<<a[i][j]<<" ";
		// }
		// cout<<"\n";
	// }
	// cout<<"\n";
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<m;j++) {
			// cout<<b[i][j]<<" ";
		// }
		// cout<<"\n";
	// }
	
	a[n-1][m-1]=0;
	b[0][0]=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (a[i][j] or b[i][j]) {cout<<"-1\n";return;}
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







