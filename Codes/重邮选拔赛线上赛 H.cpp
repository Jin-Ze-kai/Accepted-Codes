// Problem: H - Number Replacement
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/H
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	string s;
	cin>>s;
	vector<char> pre(51);
	for(int i=0;i<n;i++) {
		if (pre[a[i]] == 0) pre[a[i]]=s[i];
		else if (pre[a[i]] != s[i]) {cout<<"NO\n";return;}
	}
	cout<<"YES\n";
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







