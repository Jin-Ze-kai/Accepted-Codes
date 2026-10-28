// Problem: A. Lavencia Oranges
// Contest: Codeforces - Codeforces Round 1127 (Div. 1, Based on Mexican Olympiad in Informatics 2026)
// URL: https://codeforces.com/contest/2273/problem/A
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
	
	auto check=[&](int x) -> bool {
		int rest=n;
		for(int i=1;i<=n;i++) {
			int c=(n+i-1)/i;
			if (c*i > x) c=x/i;
			rest-=i*c;
			if (rest <= 0) break;
		}
		return rest <= 0;
	};
	
	int lo=1,hi=1e9,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res<<"\n";
	
	vector<int> ans;
	int cur=1;
	int rest=n;
	for(int i=1;i<=n;i++) {
		int c=(n+i-1)/i;
		if (c*i > res) c=res/i;
		rest-=i*c;
		for(int j=1;j<=c;j++) {
			for(int k=1;k<=i;k++) ans.push_back(cur);
			cur++;
		}
		if (rest <= 0) break;
	}
	int x=0;
	ranges::reverse(ans);
	while (ans.size() != n) ans.pop_back(),x++;
	for(auto e1 : ans) cout<<e1-x<<" ";
	cout<<"\n";
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







