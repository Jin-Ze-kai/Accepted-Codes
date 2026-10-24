// Problem: C. Edge Addeleting
// Contest: Codeforces - Codeforces Round 1129 (Div. 2)
// URL: https://codeforces.com/contest/2277/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<int> st;
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		x--;
		st.insert(x);
	}
	
	queue<int> q;
	vector<int> d(n,-1);
	d[n-1]=0;
	q.push(n-1);
	vector<int> fa(n,-1);
	fa[n-1]=n-1;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : adj[u]) {
			if (d[v] != -1) continue;
			d[v]=d[u]+1;
			fa[v]=u;
			q.push(v);
		}
	}
	
	q.push(0);
	vector<bool> mark(n);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : adj[u]) {
			if (fa[u] == v) continue;
			mark[v]=1;
			q.push(v);
		}
	}
	// for(auto x : d) cout<<x<<" ";
	// cout<<endl;
	int ans=d[0];
	for(auto x : st) {
		if (mark[x]) continue;
		ans=max(ans,d[x]+1);
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







