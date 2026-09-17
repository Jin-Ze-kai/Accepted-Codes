// Problem: B. Metronome for Corgi
// Contest: Codeforces - The 8th Guangxi Collegiate Programming Contest
// URL: https://codeforces.com/gym/106707/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	auto pre=a;
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
	
	unordered_map<int,bool> mp;
	for(int i=1;i<=n;i++) mp[pre[i]]=1;
	int ans=pre[n];
	for(int i=1;i<=n;i++) {
		int cur=pre[i];
		bool ok=1;
		while (1) {
			cur+=pre[i];
			if (cur > pre[n]) break;
			if (!mp.count(cur)) {ok=0;break;}
		}
		if (ok) {ans=pre[i];break;}
	}
	cout<<ans;
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







