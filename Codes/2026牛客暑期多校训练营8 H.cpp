// Problem: It's Magic, Not a Trick!
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133883/H
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

const int p=998244353;
void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	if (x == 1) {
		int ans=0;
		for(int i=0;i<n;i++) (ans+=a[i]%p)%=p;
		cout<<ans<<"\n";
		return;
	}
	
	i128 cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i]/x > 0) cnt+=a[i]/x,a[i]%=x;
	}
	ranges::sort(a,greater<int>());
	for(int i=0;i<n;i++) {
		if (a[i] > 0 and cnt >= x-a[i]-1) {
			if (cnt == x-a[i]-1) cnt-=x-a[i]-1;
			else cnt-=x-a[i],cnt++;
			a[i]=0;
		}
	}
	
	while (cnt >= x) {
		i128 cur=cnt/x;
		cnt%=x;
		cnt+=cur;
	}
	if (cnt == x-1) cnt=0;
	
	int ans=cnt%p;
	for(int i=0;i<n;i++) {
		(ans+=a[i]%p)%=p;
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







