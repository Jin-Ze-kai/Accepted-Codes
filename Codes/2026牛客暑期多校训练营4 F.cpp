// Problem: 23 Subsequences
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133879/F
// Memory Limit: 2048 MB
// Time Limit: 12000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
struct SegTree {
	int n;
	vector<int> tree;
	SegTree(int _) {
		n=_;
		tree.resize(n*4);
	}
	
	void Set(int p,int l,int r,int id,int val) {
		if (l == r) {tree[p]=max(tree[p],val);return;}
		int m=l+r>>1;
		if (id <= m) Set(2*p,l,m,id,val);
		else Set(2*p+1,m+1,r,id,val);
		tree[p]=max(tree[p*2],tree[p*2+1]);
	}
	
	int query(int p,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return 0;
		if (ql <= l and r <= qr) return tree[p];
		int m=l+r>>1;
		return max(query(2*p,l,m,ql,qr),query(2*p+1,m+1,r,ql,qr));
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1),aa(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		aa[i]=a[i];
	}
	sort(aa.begin()+1,aa.end());
	aa.erase(unique(aa.begin(),aa.end()),aa.end());
	
	vector<int> l(n+1),r(n+1),p(n+1);
	for(int i=1;i<=n;i++) {
		int L=(a[i]+2)/3;
		int R=a[i]/2;
		l[i]=ranges::lower_bound(aa,L)-aa.begin()+1;
		r[i]=ranges::upper_bound(aa,R)-aa.begin();
		p[i]=ranges::lower_bound(aa,a[i])-aa.begin()+1;
	}
	
	int m=aa.size();
	vector dp(n+1,vector<int>(62));
	for(int i=1;i<=n;i++) dp[i][1]=i;
	for(int i=2;i<=60;i++) {
		SegTree st(m);
		for(int j=1;j<=n;j++) {
			if (l[j] <= r[j]) dp[j][i]=st.query(1,1,m,l[j],r[j]);
			if (dp[j][i-1]) st.Set(1,1,m,p[j],dp[j][i-1]);
		}
	}
	
	for(int i=1;i<=60;i++) {
		for(int j=1;j<=n;j++) {
			dp[j][i]=max(dp[j][i],dp[j-1][i]);
		}
	}
	
	while (q--) {
		int L,R;
		cin>>L>>R;
		int res=1;
		while (res <= 60 and dp[R][res+1] >= L) res++;
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







