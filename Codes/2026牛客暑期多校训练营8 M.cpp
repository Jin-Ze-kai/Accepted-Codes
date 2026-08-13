// Problem: KV Cache
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133883/M
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
const int N=2e6;
int tree[N][26];
int ed[N];
int len=1;
int tt;
vector<int> nxt[N];
int fa[N];
int np[N];
bool mark[N];
int deg[N];

void insert(const string& s) {
	int cur=0;
	for(char c : s) {
		tt++;
		if (tree[cur][c-'a'] == 0) {
			tree[cur][c-'a']=len++;
			fa[len-1]=cur;
		}
		cur=tree[cur][c-'a'];
		nxt[cur].push_back(tt);
	}
	ed[cur]++;
}

int next(int u) {
	if (np[u] < nxt[u].size()) return nxt[u][np[u]];
	return inf;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<string> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i],insert(vec[i]);
	
	priority_queue<array<int,2>> q;//{time,u}
	mark[0]=1;
	int siz=0;
	int ans=0;
	for(int i=0;i<n;i++) {
		int cur=0;
		vector<int> vis;
		for(auto c : vec[i]) {
			cur=tree[cur][c-'a'];
			vis.push_back(cur);
		}
		
		for(auto u : vis) {
			if (!mark[u]) {
				mark[u]=1;
				siz++;
				deg[fa[u]]++;
				ans++;
			}
			np[u]++;
		}
		
		for(auto u : vis) {
			if (deg[u] == 0) q.push({next(u),u});
		}
		
		while (siz > m) {
			auto [t,u]=q.top();
			q.pop();
			if (!mark[u] or deg[u]) continue;
			mark[u]=0;
			siz--;
			deg[fa[u]]--;
			if (fa[u] != 0 and deg[fa[u]] == 0) q.push({next(fa[u]),fa[u]});
		}
	}
	cout<<ans<<"\n";
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







