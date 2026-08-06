// Problem: C2. Marenol (hard version)
// Contest: Codeforces - Codeforces Round 1114 (Div. 3)
// URL: https://codeforces.com/contest/2254/problem/C2
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
	string s1,s2;
	cin>>s1>>s2;
	vector<int> a,b;
	int ans=0;
	for(int i=0;i<n;i+=2) {
		if (s1[i] == '1') a.push_back(i);
		if (s2[i] == '1') b.push_back(i);
	}
	if (a.size() != b.size()) {cout<<"-1\n";return;}
	for(int i=0;i<a.size();i++) ans+=abs(a[i]-b[i]);
	
	a.clear();
	b.clear();
	for(int i=1;i<n;i+=2) {
		if (s1[i] == '1') a.push_back(i);
		if (s2[i] == '1') b.push_back(i);
	}
	if (a.size() != b.size()) {cout<<"-1\n";return;}
	for(int i=0;i<a.size();i++) ans+=abs(a[i]-b[i]);
	
	cout<<ans/2<<"\n";
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







