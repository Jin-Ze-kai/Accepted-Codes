// Problem: J - Traffic Light
// Contest: Virtual Judge - 重邮选拔赛线上赛
// URL: https://vjudge.net/contest/843025#problem/J
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
	int n;
	cin>>n;
	char c;
	cin>>c;
	string s;
	cin>>s;
	s+=s;
	if (c == 'g') {cout<<"0\n";return;}
	int ans=0;
	int cur=0;
	bool f=0;
	for(int i=0;i<s.size();i++) {
		if (s[i] == 'g') ans=max(ans,cur),cur=0,f=0;
		else {
			if (f == 0 and s[i] != c) continue;
			if (f == 0 and s[i] == c) {
				f=1;
				cur++;
			}
			else {
				cur++;
			}
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







