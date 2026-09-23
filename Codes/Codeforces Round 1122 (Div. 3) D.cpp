// Problem: D. Falling Concrete
// Contest: Codeforces - Codeforces Round 1122 (Div. 3)
// URL: https://codeforces.com/contest/2266/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) a[i]-=i;
	ranges::sort(a);
	int ans=1;
	int cur=1;
	for(int i=0;i<n-1;i++) {
		if (a[i]+1 == a[i+1]) cur++,ans=max(ans,cur);
		else if (a[i] == a[i+1]) continue;
		else cur=1;
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







