// Problem: K - Divisibility by 2^n
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/K
// Memory Limit: 1024 MB
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
	int cur=0;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cur+=__builtin_ctz(a[i]);
	}
	// cout<<cur<<"\n";
	vector<int> vec;
	for(int i=n;i>=1;i--) {
		int c=__builtin_ctz(i);
		if (c) vec.push_back(c);
	}
	ranges::sort(vec,greater<int>());
	for(auto x : vec) {
		if (cur >= n) break;
		cur+=x;
		cnt++;
	}
	if (cur >= n) cout<<cnt<<"\n";
	else cout<<"-1\n";
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







