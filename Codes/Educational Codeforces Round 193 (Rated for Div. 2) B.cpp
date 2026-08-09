// Problem: B. Hypercarp and the Control Panel
// Contest: Codeforces - Educational Codeforces Round 193 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2253/problem/B
// Memory Limit: 512 MB
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
	vector<int> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=1;
	for(int i=1;i<=n-1;i++) {
		if (a[i] != a[i+1]) cnt++;
	}
	// cout<<cnt<<"\n";
	int f=0;
	for(int i=3;i<=n+1;i++) {
		if (a[i-3] == a[i-2] and a[i-2] != a[i-1] and a[i-1] != a[i] and a[i-2] != a[i]) f=1;
		if (a[i-3] != a[i-2] and a[i-2] != a[i-1] and a[i-1] == a[i] and a[i-3] != a[i]) f=1;
		
	}
	for(int i=3;i<=n+1;i++) {
		if (a[i-3] == a[i-2] and a[i-2] != a[i-1] and a[i-1] == a[i]) f=2;
	}
	cout<<cnt+f<<"\n";
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







