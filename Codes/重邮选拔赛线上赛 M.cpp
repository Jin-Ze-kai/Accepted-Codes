// Problem: M - MEX vs MED
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/M
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),p(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		p[a[i]]=i;
	}
	
	int l=p[0],r=p[0];
	int ans=0;
	for(int i=0;i<n;i++) {
		l=min(l,p[i]);
		r=max(r,p[i]);
		// cout<<l<<" "<<r<<"\n";
		int len=2*i+1;
		if (len >= r-l+1) {
			ans+=max(0ll,min(l,n-len)-max(0ll,r-len+1)+1);
		}
		// cout<<ans<<"\n";
		if (len >= n) break;
		len=2*i+2;
		if (len >= r-l+1) {
			ans+=max(0ll,min(l,n-len)-max(0ll,r-len+1)+1);
		}
		// cout<<ans<<"\n";
		if (len >= n) break;
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







