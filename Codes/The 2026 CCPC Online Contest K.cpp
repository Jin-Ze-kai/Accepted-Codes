// Problem: K. Keep on the Right Track
// Contest: Codeforces - The 2026 CCPC Online Contest
// URL: https://codeforces.com/gym/106725/problem/K
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

const int p=998244353;
const int inf=1e18;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int Inv(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int n,m,t;
	cin>>n>>m>>t;
	t--;
	string s;
	cin>>s;
	s[t]='1';
	vector adj(n,vector<array<int,2>>(0));
	vector fadj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		fadj[v].push_back({u,w});
	}
	
	queue<int> q;
	q.push(t);
	vector<int> deg(n);
	for(int i=0;i<n;i++) {
		for(auto [u,w] : fadj[i]) {
			deg[u]++;
		}
	}
	vector<int> ord;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		ord.push_back(u);
		for(auto [v,w] : fadj[u]) {
			deg[v]--;
			if (!deg[v]) q.push(v);
		}
	}
	
	vector<int> dis(n,inf);
	dis[t]=0;
	for(auto u : ord) {
		for(auto [v,w] : fadj[u]) {
			if (dis[u]+w < dis[v]) dis[v]=dis[u]+w;
		}
	}
	// for(auto x : dis) cout<<x<<" ";
	vector<int> cnt(n);
	cnt[t]=1;
	vector<int> ans(n);
	for(auto u : ord) {
		if (s[u] == '1') (ans[u]*=Inv(cnt[u]))%=p;
		else (ans[u]*=Inv(adj[u].size()))%=p;
		for(auto [v,w] : fadj[u]) {
			if (s[v] == '0') (ans[v]+=ans[u]+w)%=p;
			else if (dis[u]+w == dis[v]) (ans[v]+=cnt[u]*(ans[u]+w)%p)%=p;
			if (dis[u]+w == dis[v]) (cnt[v]+=cnt[u])%=p;
		}
	}
	// for(auto e1 : cnt) cout<<e1<<" ";
	// cout<<endl;
	
	for(auto x : ans) cout<<x<<" ";
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







