// Problem: L - Divisible Numbers (hard version)
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/L
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<int> aa,bb;
	for(int i=1;i<=a/i;i++) {
		if (a%i == 0) {
			aa.push_back(i);
			if (i*i != a) aa.push_back(a/i);
		}
	}
	for(int i=1;i<=b/i;i++) {
		if (b%i == 0) {
			bb.push_back(i);
			if (i*i != b) bb.push_back(b/i);
		}
	}
	
	for(auto a1 : aa) {
		for(auto b1 : bb) {
			int p=a1*b1;
			int q=a*b/p;
			int x=(a/p+1)*p;
			int y=(b/q+1)*q;
			if (x <= c and y <= d) {
				cout<<x<<" "<<y<<"\n";
				return;
			}
		}
	}
	cout<<"-1 -1\n";
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







