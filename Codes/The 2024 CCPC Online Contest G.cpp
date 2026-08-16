// Problem: G. 疯狂星期六
// Contest: Codeforces - The 2024 CCPC Online Contest
// URL: https://codeforces.com/gym/105336/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
struct Flow {
    int n;
    vector<array<int,2>> edge;//[v,残量]
    vector<vector<int>> adj;
    vector<int> cur,h;
    
    Flow() {};
    Flow(int n) : n(n) {init(n);}
    
    void init(int n) {
        edge.clear();
        if (adj.size() < n) adj.resize(n);
        for(auto &e : adj) e.clear();
        if (cur.size() < n) cur.resize(n);
        if (h.size() < n) h.resize(n);
    }
    
    void add(int u,int v,int c) {
        adj[u].push_back(edge.size());
        edge.push_back({v,c});
        adj[v].push_back(edge.size());
        edge.push_back({u,0});
    }
    
    bool bfs(int s, int t) {
    	fill(h.begin(),h.end(),-1);
        queue<int> q;
        h[s]=0;
        q.push(s);
        while (!q.empty()) {
            auto u=q.front();
            q.pop();
            for (auto p : adj[u]) {
                auto [v,c]=edge[p];
                if (c > 0 and h[v] == -1) {
                    h[v]=h[u]+1;
                    if (v == t) return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    
    int dfs(int u,int t,int f) {
        if (u == t) return f;
        int r=f;
        for (int &i=cur[u];i<adj[u].size();i++) {
            int j=adj[u][i];	
            auto [v,c]=edge[j];
            if (c > 0 and h[v] == h[u]+1) {
                int nf=dfs(v,t,min(r,c));
                edge[j][1]-=nf;
                edge[j^1][1]+=nf;
                r-=nf;
                if (r == 0) return f;
            }
        }
        return f-r;
    }
    
    int flow(int s,int t) {
        int ans=0;
        while (bfs(s,t)) {
        	fill(cur.begin(),cur.end(),0);
            ans+=dfs(s,t,inf);
        }
        return ans;
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> V(n+1);
	for(int i=1;i<=n;i++) cin>>a[i]>>V[i];
	vector<array<int,2>> vec(m+1);
	vector<int> W(m+1);
	for(int i=1;i<=m;i++) cin>>vec[i][0]>>vec[i][1]>>W[i];
	
	int cur=0;
	for(int i=1;i<=m;i++) {
		auto [x,y]=vec[i];
		if (x == 1 or y == 1) cur+=W[i];
	}
	int mx=min(a[1]-V[1],cur)+V[1];
	
	Flow f(n+m+2);
	for(int i=1;i<=m;i++) {
		f.add(0,i,W[i]);
	}
	for(int i=1;i<=m;i++) {
		auto [x,y]=vec[i];
		f.add(i,m+x,W[i]);
		f.add(i,m+y,W[i]);
	}
	f.add(m+1,m+n+1,mx-V[1]);
	for(int i=2;i<=n;i++) {
		int c;
		if (mx <= a[i]) c=mx-V[i]-1;
		else c=a[i]-V[i];
		if (c < 0) {cout<<"NO\n";return;}
		f.add(m+i,m+n+1,c);
	}
	
	int sum=accumulate(W.begin(),W.end(),0ll);
	if (f.flow(0,n+m+1) == sum) cout<<"YES\n";
	else cout<<"NO\n";
	
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







