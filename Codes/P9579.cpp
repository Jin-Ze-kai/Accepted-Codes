// Problem: P9579 「Cfz Round 1」Elevator
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9579
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
	vector<array<int,2>> seg;
	int up=0;
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		up=max({up,x,y});
		if (x > y) seg.push_back({x,y});
	}
	ranges::sort(seg,greater<array<int,2>>());
	vector<array<int,2>> vec;
	int l=0,r=0;
	n=seg.size();
	int hi=0,lo=0;
	while (r < n) {
		if (l == r) {
			hi=seg[r][0];
			lo=seg[r][1];
			r++;
		}
		else {
			if (lo <= seg[r][0]) lo=min(lo,seg[r][1]),r++;
			else {
				vec.push_back({hi,lo});
				hi=lo=0;
				l=r;
			}
		}
	}
	if (l != r) vec.push_back({hi,lo});
	// for(auto [hi,lo] : vec) cout<<hi<<" "<<lo<<"\n";
	
	if (vec.empty()) {
		cout<<up;
		return;
	}
	int down=vec.back()[1];
	int ans=up+up-down;
	int cur=ans;
	// cout<<ans<<"\n";
	while (!vec.empty()) {
		auto [hi,lo]=vec.back();
		vec.pop_back();
		if (vec.empty()) down=up;
		else down=vec.back()[1];
		
		cur+=(hi-lo)*2-(down-lo);
		ans=min(cur,ans);
	}
	cout<<ans;
}

signed main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







