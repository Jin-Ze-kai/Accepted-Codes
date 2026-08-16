// Problem: Escape Root
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133884/D
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
	int n,m;
	cin>>n>>m;
	vector adj(n+1,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> ans(m+1,1);
	vector<map<int,int>> vec(n+1);
	vector tmp(n+1,vector<int>(0));
	for(int i=1;i<=m;i++) {
		int u,t;
		cin>>u>>t;
		if (vec[u].count(t)) {
			ans[i]=ans[vec[u][t]]=0;
			vec[u][t]=0;
			tmp[u].push_back(t);
		}
		else vec[u][t]=i;
	}
	
	vector<int> fa(n+1),deg(n+1);
	auto dfs=[&](auto&& self,int u) -> void {
		for(auto v : adj[u]) {
			if (v == fa[u]) continue;
			deg[u]++;
			fa[v]=u;
			self(self,v);
		}
	};
	dfs(dfs,1);
	queue<int> q;
	for(int i=1;i<=n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	// for(auto e1 : deg) cout<<e1<<" ";
	
	vector<int> t(n+1);//偏移量
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		if (u == 1) break;
		deg[fa[u]]--;
		if (deg[fa[u]] == 0) q.push(fa[u]);
		
		for(auto tt : tmp[u]) vec[u].erase(tt);
		
		// for(auto it=vec[u].begin();it!=vec[u].end();) {
			// if (it->second == 0) it=vec[u].erase(it);
			// else ++it;
		// }
		
		if (vec[fa[u]].size() >= vec[u].size()) {
			for(auto [tt,id] : vec[u]) {
				int cur=tt+t[fa[u]]-t[u]+1;
				if (vec[fa[u]].count(cur)) {
					ans[id]=ans[vec[fa[u]][cur]]=0;
					vec[fa[u]][cur]=0;
					tmp[fa[u]].push_back(cur);
				}
				else vec[fa[u]][tt+t[fa[u]]-t[u]+1]=id;
			}
		}
		else {
			swap(vec[fa[u]],vec[u]);
			swap(t[fa[u]],t[u]);
			tmp[fa[u]].clear();
			t[fa[u]]--;
			for(auto [tt,id] : vec[u]) {
				int cur=tt+t[fa[u]]-t[u];
				if (vec[fa[u]].count(cur)) {
					ans[id]=ans[vec[fa[u]][cur]]=0;
					vec[fa[u]][cur]=0;
					tmp[fa[u]].push_back(cur);
				}
				else {
					vec[fa[u]][cur]=id;
					if (id == 0) tmp[fa[u]].push_back(cur);
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i];
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







