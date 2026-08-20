// Problem: I - Even-Odd Increments
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/I
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int c0=0,c1=0;
	int sum=0;
	for(int i=0;i<n;i++) {
		if (a[i]&1) c1++;
		else c0++;
		sum+=a[i];
	}
	
	while (q--) {
		int opt,x;
		cin>>opt>>x;
		if (opt == 0) {
			sum+=c0*x;
			if (x&1) {
				c1+=c0;
				c0=0;
			}
		}
		else {
			sum+=c1*x;
			if (x&1) {
				c0+=c1;
				c1=0;
			}
		}
		cout<<sum<<"\n";
	}
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







