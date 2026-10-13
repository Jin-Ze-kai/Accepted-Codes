// Problem: P10854 【MX-X2-T3】「Cfz Round 4」Ninelie
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10854
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,r;
	cin>>n>>r;
	vector<int> a(n+1);
	// if (n == 2000) {
		// for(int i=1;i<=2000;i++) a[i]=1-(i&1);
	// }
	for(int i=1;i<=n;i++) cin>>a[i];
	auto b=a;
	vector<int> ans;
	int mid=n/2;
	for(int i=1;i<=mid;i++) {
		if (a[i] == 0) continue;
		int p=i;
		while (p <= mid) {
			if (a[p] != 1) break;
			p++;
		}
		p--;
		if (p == mid) break;
		for(int j=i-1;j>=1;j--) ans.push_back(j);
		for(int j=p;j>=1;j--) ans.push_back(j),a[j]=0;
		i=p;
	}
	for(int i=n;i>=1;i--) {
		if (a[i] == 0) continue;
		int p=i;
		while (p > 0) {
			if (a[p] != 1) break;
			p--;
		}
		p++;
		for(int j=i+1;j<=n;j++) ans.push_back(j);
		for(int j=p;j<=n;j++) ans.push_back(j),a[j]=0;
		i=p;
	}
	
	// for(auto x : a) cout<<x<<" ";
	// cout<<endl;
	// cout<<ans.size()<<endl;
	if (ans.size() <= r) {
		cout<<ans.size()<<"\n";
		for(auto x : ans) cout<<x<<" ";
		return;
	}
	
	
	
	ans.clear();
	a=b;
	for(int i=1;i<=mid;i++) {
		if (a[i] == 1) continue;
		int p=i;
		while (p <= mid) {
			if (a[p] != 0) break;
			p++;
		}
		p--;
		if (p == mid) break;
		for(int j=i-1;j>=1;j--) ans.push_back(j);
		for(int j=p;j>=1;j--) ans.push_back(j),a[j]=1;
		i=p;
	}
	for(int i=n;i>=1;i--) {
		if (a[i] == 1) continue;
		int p=i;
		while (p > 0) {
			if (a[p] != 0) break;
			p--;
		}
		p++;
		for(int j=i+1;j<=n;j++) ans.push_back(j);
		for(int j=p;j<=n;j++) ans.push_back(j),a[j]=1;
		i=p;
	}
	
	// cout<<ans.size()<<endl;
	if (ans.size() <= r) {
		cout<<ans.size()<<"\n";
		for(auto x : ans) cout<<x<<" ";
	}
	else assert(0);
	
	
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







