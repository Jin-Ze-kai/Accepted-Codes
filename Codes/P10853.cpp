// Problem: P10853 【MX-X2-T2】「Cfz Round 4」Xor Counting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10853
// Memory Limit: 512 MB
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
	vector<int> a(n),cnt(32);
	int c0=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] == 0) c0++;
		else cnt[__lg(a[i])]++;
		// cout<<__lg(a[i])<<"\n";
	}
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 0) ans+=n;
		else {
			int cur=0;
			while (a[i] > 1) {
				if (a[i]&1) ans+=cnt[cur];
				a[i]>>=1;
				cur++;
			}
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







