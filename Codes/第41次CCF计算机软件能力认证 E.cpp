#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,X;
	cin>>n>>X;
	vector adj(n,vector<array<int,2>>(0));
    vector<array<int,2>> edge(n-1);
    vector<bool> f(n-1);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		edge[i]={u,v};
	}
	int k;
	cin>>k;
	vector<bool> mark(k);
	for(int i=0;i<k;i++) {
		int u;
		cin>>u;
		mark[u-1]=1;
	}
	
	int m;
	cin>>m;
	vector<array<int,2>> vec(m);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		vec[i]={u,v};
	}
	
	bool ok;
	int tar;
	auto dfs=[&](auto&& self,int u,int fa,int cnt) -> void {
		if (ok) return;
		if (u == tar) {ok=1;return;}
		
		for(auto [v,id] : adj[u]) {
			if (v == fa) continue;
			int ncnt=cnt+(!f[id] ? 1 : 0);
			if (ncnt == 2) continue;
			if (mark[v]) ncnt=0;
			self(self,v,u,ncnt);
		}
	};
	
	int q;
	cin>>q;
	int last=0;
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int u,v;
			cin>>u>>v;
			u=u^(X*last);
			v=v^(X*last);
			u--,v--;
			for(auto [v1,id] : adj[u]) {
				if (v1 == v) {
					f[id]=1;
					break;
				}
			}
		}
		else {
			int cnt=0;
			for(auto [u,v] : vec) {
				ok=0;
				tar=v;
				dfs(dfs,u,u,0);
				if (ok) cnt++;
			}
			last=cnt;
			cout<<cnt<<"\n";
		}
	}
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







