// Problem: C. 圆桌会议
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/C
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
	vector<int> a(n);
	int cnt=0;
	for(int i=0;i<n;i+=3) a[i]=++cnt;
	for(int i=1;i<n;i+=3) a[i]=++cnt;
	for(int i=2;i<n;i+=3) a[i]=++cnt;
	for(auto e1 : a) cout<<e1<<" ";
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







