// Problem: D. Divide and Conquer
// Contest: Codeforces - The 2026 ICPC Asia EC Regionals Online Contest (II)
// URL: https://codeforces.com/gym/106701/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n,q;
	cin>>n>>q;
	int N=1<<(n+1);
	vector<int> b(N,1<<n);
	vector<vector<int>> R((1<<n)+1);
	for(int i=0;i<q;i++) {
		int u,x;
		cin>>u>>x;
		b[u]=min(b[u],x);
		R[x].push_back(u);
	}
	
	for(int i=2;i<N;i++) {
		b[i]=min(b[i],b[i/2]);
	}
	
	vector<vector<int>> vec((1<<n)+1);//上限恰好为x的叶子节点
	for(int i=1<<n;i<N;i++) {
		vec[b[i]].push_back(i);
	}
	
	int cnt=0;
	int ans=1;
	for(int x=1<<n;x>=1;x--) {
		(cnt+=vec[x].size())%=p;
		if (!R[x].empty()) {
			int v=0;
			for(auto u : R[x]) v=max(v,u);
			for(auto u : R[x]) {
				bool ok=0;
				int v1=v;
				while (v1) {
					if (u == v1) {ok=1;break;}
					v1>>=1;
				}
				if (!ok) {cout<<"0";return;}
			}
			
			int c=0;
			for(auto u : vec[x]) {
				while (u) {
					if (u == v) {c++;break;}
					u>>=1;
				}
			}
			if (c == 0) {cout<<"0";return;}
			(ans*=c)%=p;
			cnt--;
		}
		else {
			(ans*=cnt)%=p;
			cnt--;
		}
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







