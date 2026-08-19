// Problem: Team Formation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133885/K
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
int dp[1<<24];
void solve()
{
	int n;
	cin>>n;
	vector a(3*n,vector<int>(3*n));
	for(int i=0;i<3*n;i++) {
		for(int j=0;j<3*n;j++) {
			cin>>a[i][j];
		}
	}
	
	fill(dp+1,dp+(1<<24),-inf);
	for(int mask=0;mask<(1<<3*n)-1;mask++) {
		if (dp[mask] == -inf) continue;
		int p=-1;
		for(int i=0;i<3*n;i++) {
			if (((mask>>i)&1) == 0) {p=i;break;}
		}
		
		for(int i=p+1;i<3*n;i++) {
			if ((mask>>i)&1) continue;
			for(int j=i+1;j<3*n;j++) {
				if ((mask>>j)&1) continue;
				int nmask=mask|(1<<p)|(1<<i)|(1<<j);
				int cur=a[p][i]+a[p][j]+a[i][j];
				dp[nmask]=max(dp[nmask],dp[mask]+cur);
			}
		}
	}
	cout<<dp[(1<<3*n)-1];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







