#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<vector<int>> fa;
vector<int> deep;
void build(vector<vector<int>> &adj,int r) {
	int n=adj.size();
    int m=__lg(n)+1;
    fa.assign(m+1,vector<int>(n,-1));
    deep.assign(n,-1);
    
    queue<int> q;
    q.push(r);
    deep[r]=0;
    fa[0][r]=-1;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (deep[v] == -1) {
                deep[v]=deep[u]+1;
                fa[0][v]=u;
                q.push(v);
            }
        }
    }
    
    for (int k=1;k<=m;k++) {
        for (int u=0;u<n;u++) {
            if (fa[k-1][u] != -1) {
                fa[k][u]=fa[k-1][fa[k-1][u]];
            } else {
                fa[k][u]=-1;
            }
        }
    }
}

int lift(int u,int target) {
    int dif=deep[u]-target;
    int k=0;
    while (dif > 0) {
        if (dif&1) u=fa[k][u];
        dif>>=1;
        k++;
    }
    return u;
}

int query(int u,int v) {
    if (deep[u] < deep[v]) swap(u,v);
    u=lift(u,deep[v]);
    if (u == v) return u;
    
    int m=fa.size()-1;
    for (int k=m;k>=0;k--) {
        if (fa[k][u] != fa[k][v]) {
            u=fa[k][u];
            v=fa[k][v];
        }
    }

    return fa[0][u];
}

int dist(int u,int v) {
    return deep[u]+deep[v]-2*deep[query(u,v)];
}

bool onpath(int z,int x,int y) {
	return dist(x,z)+dist(z,y) == dist(x,y);
}

void solve()
{
	int n,q;
	cin>>n>>q;
	vector adj(n,vector<int>(0));
	vector<int> a(n);
	vector<int> pos(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(adj,pos[0]);

	vector<int> U(n+1),V(n+1);
	U[0]=pos[0];
	V[0]=pos[0];
	int maxn=0;
	for(int i=1;i<n;i++) {
		int u=U[i-1];
		int v=V[i-1];
		int w=pos[i];
		if (onpath(w,u,v)) {
			U[i]=u;
			V[i]=v;
		}
		else if (onpath(u,w,v)) {
			U[i]=w;
			V[i]=v;
		}
		else if (onpath(v,w,u)) {
			U[i]=w;
			V[i]=u;
		}
		else break;
		maxn=i;
	}
	
	while (q--) {
		int x,y;
		cin>>x>>y;
		x--,y--;
		int lo=0,hi=maxn+1,res=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (mid == 0 or onpath(U[mid-1],x,y) and onpath(V[mid-1],x,y)) res=mid,lo=mid+1;
			else hi=mid-1;
		}
		cout<<res<<"\n";
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







