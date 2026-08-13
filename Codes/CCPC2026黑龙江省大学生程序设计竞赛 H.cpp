// Problem: H. 周二会员日
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/H
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
	string s;
	cin>>s;
	i128 y=0;
	for(auto c : s) {
		if (c == '.') continue;
		y*=10;
		y+=c-'0';
	}
	y=(y*2-100)*2-100;
	int x=y%100;
	y/=100;
	if (x < 10) cout<<(int)y<<".0"<<x<<"\n";
	else cout<<(int)y<<"."<<x<<"\n";
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







