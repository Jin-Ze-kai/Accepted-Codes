// Problem: Bridge VI
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133883/I
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

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++) cin>>a[i];
	int x=a[0]+m;
	int ans=0;
	if (x < a[1]) ans++;
	for(int i=2;i<2*n;i+=2) {
		int mx=a[i],mn=a[i+1];
		if (mx < mn) swap(mx,mn);
		if (mn > x) ans+=2;
		else if (mx > x or mx+mn+m > x*2) ans++;
	}
	cout<<ans<<" ";
	ans=0;
	x=a[0];
	if (a[0] < a[1]+m) ans++;
	for(int i=2;i<2*n;i+=2) {
		int mx=a[i],mn=a[i+1];
		if (mx < mn) swap(mx,mn);
		if (max(0ll,x-mn)+max(0ll,x-mx) < m) ans+=2;
		else if (mx+m > x) ans++;
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







