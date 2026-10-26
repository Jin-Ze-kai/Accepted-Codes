// Problem: A. Hey, It's Me, Souvlakity
// Contest: Codeforces - WorldQuant Round 1 (Codeforces Round 1128, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2261/problem/A
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int c1=ranges::count(s,'1');
	int mx=0,mn=inf;
	for(int i=1;i<=n;i++) {
		if (s[i-1] == '0') continue;
		mx=max(mx,i);
		mn=min(mn,i);
	}
	if (c1 == 1) cout<<"0\n";
	else if (c1 == 2) cout<<"1\n";
	else cout<<mx-mn<<"\n";
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







