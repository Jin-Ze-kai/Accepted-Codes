// Problem: C. K Is Important
// Contest: Codeforces - Codeforces Round 1124 (Div. 2)
// URL: https://codeforces.com/contest/2269/problem/C
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int p1=k-1,p2=n-k;
	int ans=0;
	int x=0;
	if (p1 <= p2) {
		for(int i=p1;i<=p2;i++) ans+=a[i],x++;
	}
	
	for(int i=0;i<p1;i++) {
		if (x > n-k) break;
		x++;
		ans+=max(a[i],a[n-i-1]);
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







