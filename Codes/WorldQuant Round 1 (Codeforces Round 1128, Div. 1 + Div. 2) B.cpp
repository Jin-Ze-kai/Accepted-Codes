// Problem: B. What's the Capital of France?
// Contest: Codeforces - WorldQuant Round 1 (Codeforces Round 1128, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2261/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	int ans=0;
	for(int b=31;b>=0;b--) {
		int c1=0;
		for(int i=0;i<n;i++) {
			if (((a[i]>>b)&1) == 1) c1++;
		}
		if (c1 == 0) continue;
		else if (c1 == n) {
			ans+=1ll<<b;
		}
		else {
			ans+=(1ll<<(b+1))-1;
			break;
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







