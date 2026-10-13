// Problem: P10309 「Cfz Round 2」Max of Distance
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10309
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
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<array<int,2>>(0));
	vector<int> w(n-1);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		w[i]=1;
	}
	
	int E,V;
	for(int i=0;i<n;i++) {
		if (adj[i].size() == 1) {
			E=adj[i][0][1];
			V=i;
			break;
		}
	}
	
	int num;
	cin>>num;
	if (n == 2) {
		if (num == 0) num=p;
		cout<<num;
		return;
	}
	(num*=n)%=p;
	w[E]=n;
	int sum=0,mx=0;
	auto dfs=[&](auto&& self,int u,int fa,int dis) -> void {
		mx=max(mx,dis);
		for(auto [v,edge] : adj[u]) {
			if (v == fa) continue;
			sum+=dis+w[edge];
			// cout<<"v:"<<v<<" "<<dis+w[edge]<<"\n";
			self(self,v,u,dis+w[edge]);
		}
	};
	dfs(dfs,V,V,0);
	sum+=mx;
	// cout<<sum<<"\n";
	
	w[E]=((num-sum+n*n)%p+p)%p*Pow(n,p-2)%p;
	if (w[E] < n) w[E]+=p;
	for(auto x : w) cout<<x<<"\n";
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







