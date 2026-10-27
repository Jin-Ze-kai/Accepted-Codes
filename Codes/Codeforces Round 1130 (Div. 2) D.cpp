// Problem: D. Connecting the Conflicts
// Contest: Codeforces - Codeforces Round 1130 (Div. 2)
// URL: https://codeforces.com/contest/2272/problem/D
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
	int k;
	cin>>k;
	vector<int> n(k+1);
	array<int,2> a{-1,-1};
	for(int i=0;i<k;i++) {
		cin>>n[i];
		vector adj(n[i],vector<int>(0));
		for(int j=0;j<n[i]-1;j++) {
			int u,v;
			cin>>u>>v;
			u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		if (a[0] != -1) continue;
		for(int j=0;j<n[i];j++) {
			if (adj[j].size() == 1) a={i,adj[j][0]};
		}
	}
	if (a[0] == -1) a={0,0};
	for(int i=0;i<k;i++) {
		if (i == a[0]) continue;
		cout<<a[0]+1<<" "<<a[1]+1<<" "<<i+1<<" 1\n";
	}
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







