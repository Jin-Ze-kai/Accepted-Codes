#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> val;
	vector<int> cost;
	for(int i=1;i<=m;i++) {
		int x;
		cin>>x;
		for(int j=1;i*j<=n;j++) {
			val.push_back(x*j);
			cost.push_back(i*j);
		}
	}
	
	// for(auto x : cost) cout<<x<<" ";
	// cout<<endl;
	// for(auto x : val) cout<<x<<" ";
	// cout<<endl; 
	vector<int> dp(n+1);
	for(int i=0;i<cost.size();i++) {
		for(int j=n;j>=cost[i];j--) {
			dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
		}
	}
	cout<<dp[n];
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







