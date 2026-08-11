// Problem: B. Domino Tiles
// Contest: Codeforces - Codeforces Round 1116 (Div. 2)
// URL: https://codeforces.com/contest/2256/problem/B
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=1;
	if (s[0] == '?') ans<<=1;
	if (s[1] == '?') ans<<=1;
	for(int i=2;i<n;i++) {
		if (s[i] == '?') {
			if (s[i-2] == '0') s[i]='1';
			if (s[i-2] == '1') s[i]='0';
		}
		else {
			if (s[i-2] == '?') ans/=2;
			if (s[i-2] == s[i]) {cout<<"0\n";return;}
		}
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







