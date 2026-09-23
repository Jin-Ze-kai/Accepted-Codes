// Problem: C. AND, OR, Sort!
// Contest: Codeforces - Codeforces Round 1122 (Div. 3)
// URL: https://codeforces.com/contest/2266/problem/C
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
	string s;
	cin>>s;
	vector<int> a(n);
	for(int i=0;i<n;i++) a[i]=s[i]-'0';
	if (a[0]) {
		cout<<ranges::count(a,0)<<"\n";
		return;
	}
	
	int c0=ranges::count(a,0);
	int ans=n;
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;i++) {
		if (a[i]) cnt1++;
		else cnt0++;
		ans=min(ans,cnt1+c0-cnt0);
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







