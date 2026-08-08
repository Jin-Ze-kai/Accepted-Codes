// Problem: Tenkaichi Budōkai
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133882/D
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,x;
	cin>>n>>x;
	x--;
	vector<int> p(n),q(n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) {
		cin>>p[i];
		p[i]--;
		a[p[i]]=i;
	}
	for(int i=0;i<n;i++) {
		cin>>q[i];
		q[i]--;
		b[q[i]]=i;
	}
	
	int i=0,j=0;
	vector<int> vis(n);
	vector<int> ans;
	while (1) {
		while (vis[p[i]]) i++;
		while (vis[q[j]]) j++;
		if (p[i] == q[j]) break;
		if (p[i] == x or q[j] != x and max(a[p[i]],b[p[i]]) >= max(a[q[j]],b[q[j]])) {
			vis[q[j]]=1;
			ans.push_back(q[j]);
			j++;
		}
		else {
			vis[p[i]]=1;
			ans.push_back(p[i]);
			i++;
		}
	}
	
	if (ans.size() != n-1) cout<<"NO\n";
	else {
		cout<<"YES\n";
		for(auto e1 : ans) cout<<e1+1<<" ";
		cout<<"\n";
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







