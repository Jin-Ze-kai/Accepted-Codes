// Problem: Joyride
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133885/J
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

struct VBCC {
    int n;
    vector<vector<array<int,2>>> adj;
    vector<array<int,2>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    vector<int> vis;
    int cur,cnt;

    VBCC() {};

    void init(int n) {
        this->n=n;
        adj.assign(n,{});
        edge.clear();
        dfn.assign(n,-1);
        low.assign(n,-1);
        vis.clear();
        stk.clear();
        cur=cnt=0;
    }

    VBCC(int n) {
        init(n);
    }

    void add(int u,int v) {
        adj[u].push_back({v,(int)edge.size()});
        adj[v].push_back({u,(int)edge.size()});
        edge.push_back({u,v});
    }

    void dfs(int u) {
        dfn[u]=low[u]=cur++;
        for (auto [v,pos] : adj[u]) {
            if (vis[pos]) continue;
            vis[pos]=1;
            stk.push_back(pos);
            if (dfn[v] == -1) {
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v] >= dfn[u]) {
                    int y;
                    do {
                        y = stk.back();
                        bel[y] = cnt;
                        stk.pop_back();
                    } while (y != pos);
                    cnt++;
                }
            }
            else low[u]=min(low[u],dfn[v]);
        }
    }

    vector<int> work() {
        bel.assign(edge.size(),-1);
        vis.assign(edge.size(),0);
        for (int i=0;i<n;i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return bel;
    }
    
    vector<set<int>> getEdge() {
    	work();
	    vector<set<int>> E(cnt);
	    for(int i=0;i<edge.size();i++) {
	    	if (bel[i] == -1) continue;
	        auto [u,v]=edge[i];
	        E[bel[i]].insert(i);
	    }
	    return E;
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	VBCC vbcc(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		vbcc.add(u,v);
	}
	
	auto vec=vbcc.getEdge();
	vector<int> ans(n);
	for(auto st : vec) {
		map<int,int> mp;
		for(int i : st) {
			int u=vbcc.edge[i][0];
			int v=vbcc.edge[i][1];
			mp[u]++;
			mp[v]++;
		}
		for(auto [u,cnt] : mp) ans[u]+=cnt/2;
	}
	for(auto x : ans) cout<<x<<" ";
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







