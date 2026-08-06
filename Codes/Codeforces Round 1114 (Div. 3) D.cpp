// Problem: D. Silhouette
// Contest: Codeforces - Codeforces Round 1114 (Div. 3)
// URL: https://codeforces.com/contest/2254/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>b[i];
	
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[b[i]]++;
	auto [x0,pcnt]=*mp.begin();
	if (x0 != 0) {cout<<"-1\n";return;}
	mp.erase(mp.begin());
	
	int px=0;
	map<int,int> ans;
	int ed=0;
	for(auto [x,cnt] : mp) {
		if ((x-px)%pcnt) {cout<<"-1\n";return;}
		ans[px]=(x-px)/pcnt;
		if (ed >= ans[px]) {cout<<"-1\n";return;}
		ed=ans[px];
		pcnt=cnt;
		px=x;
	}
	ans[px]=ed+1;
	for(int i=0;i<n;i++) {
		cout<<ans[b[i]]<<" ";
	}
	cout<<"\n";
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







