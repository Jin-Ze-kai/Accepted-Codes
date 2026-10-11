// Problem: P10307 「Cfz Round 2」Binary
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10307
// Memory Limit: 512 MB
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
	vector<int> a(n+1);
	for(int i=0;i<=n;i++) cin>>a[i];
	int cur=0;
	int ans=0;
	string s="0";
	for(int i=0;i<n;i++) {
		if (cur == a[i]) s+="1";
		else s+="0";
		cur^=a[i];
	}
	if (cur == a.back()) {
		for(int i=s.size()-1;i>=0;i--) {
			if (s[i] == '1') s[i]='0';
			else {s[i]='1';break;} 
		}
	}
	ranges::reverse(s);
	while (s.size() > 1 and s.back() == '0') s.pop_back();
	ranges::reverse(s);
	cout<<s<<"\n";
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







