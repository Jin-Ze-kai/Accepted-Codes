// Problem: Infiltrate Angel's Domain
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133882/A
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	auto check=[&](int mask) -> bool {
		auto b=a;
		for(int i=1;i<=n;i++) {
			b[i]|=mask;
			for(int j=30;j>=0;j--) {
				if (((mask>>j)&1)) {
					if ((b[i]^(1<<j)) >= b[i-1]) b[i]^=1<<j;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			if (b[i] < b[i-1]) return 0;
		}
		return 1;
	};
	
	int ans=0;
	for(int i=30;i>=0;i--) {
		int cur=ans|((1<<i)-1);
		if (!check(cur)) ans|=1<<i;
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







