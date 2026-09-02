#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	if (n == 1) {
		while (q--) {
			int l,r;
			cin>>l>>r;
			cout<<(a[1] == 0)<<"\n";
		}
		return;
	}
	
	auto pre=a;
	for(int i=3;i<=n;i++) {
		pre[i]^=pre[i-2];
	}
	
	unordered_map<int,int> mp;
	vector<int> nxt(n+1,inf);
	for(int i=n;i>=1;i-=2) {
		mp[pre[i]]=i;
		int t=i>=3 ? pre[i-2] : 0;
		if (mp.count(t)) nxt[i]=mp[t];
	}
	mp.clear();
	for(int i=n-1;i>=1;i-=2) {
		mp[pre[i]]=i;
		int t=i>=3 ? pre[i-2] : 0;
		if (mp.count(t)) nxt[i]=mp[t];
	}
	
	for(int i=n-1;i>=1;i--) {
		nxt[i]=min(nxt[i],nxt[i+1]);
	}
	
	vector up(30,vector<int>(n+2,inf));
	for(int i=1;i<=n;i++) {
		up[0][i]=nxt[i]+1;
	}
	for(int i=1;i<30;i++) {
		for(int j=1;j<=n+1;j++) {
			if (up[i-1][j] <= n+1) up[i][j]=up[i-1][up[i-1][j]];
		}
	}
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		int p=l;
		int ans=0;
		for(int i=29;i>=0;i--) {
			if (up[i][p] > r+1) continue;
			else {
				p=up[i][p];
				ans+=1<<i;
			}
		}
		cout<<ans<<"\n";
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







