// Problem: F. 复读机
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/F
// Memory Limit: 256 MB
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
	int x;
	cin>>x;
	if (x == 1) cout<<"I love Heilongjiang";
	else if (x == 0) cout<<"I love CCPC";
	else cout<<"Error";
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







