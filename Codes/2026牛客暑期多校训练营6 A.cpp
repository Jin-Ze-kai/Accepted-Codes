// Problem: A Permutation Problem
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133881/A
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
struct DSU {
    vector<int> f,siz;
    int cnt;

    DSU(int n) {init(n);}

    void init(int n) {
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
        cnt=n;
    }

    int find(int x) {
    	if (x == f[x]) return x;
    	int r=find(f[x]);
        return f[x]=r;
    }

    bool merge(int x,int y) {
        int fx=find(x);
        int fy=find(y);
        if (fx == fy) return 0;
        siz[fx]+=siz[fy];
        f[fy]=fx;
        cnt--;
        return 1;
    }
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),pos(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
		pos[a[i]]=i;
	}	
	DSU dsu(n);
	int ans=1;
	for(int i=n-1;i>=0;i--) {
		(ans*=dsu.siz[dsu.find(pos[i])]--)%=p;
		if (pos[i] > 0 and pos[i] < n-1 and dsu.siz[dsu.find(pos[i]-1)] and dsu.siz[dsu.find(pos[i]+1)]) {
			dsu.merge(pos[i]-1,pos[i]+1);
		}
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







