// Problem: Sequence（Mex Version）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133880/K
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

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	auto mex=[&](int x,int y,int z) -> int {
		vector<int> cnt(3);
		if (x < 3) cnt[x]=1;
		if (y < 3) cnt[y]=1;
		if (z < 3) cnt[z]=1;
		for(int i=0;i<3;i++) {
			if (!cnt[i]) return i;
		}
		return 3;
	};
	auto work=[&]() -> void {
		for(int i=0;i<n;i++) {
			b[i]=mex(a[i],a[(i+n-1)%n],a[(i+1)%n]);
		}
		swap(a,b);
	};
	
	// for(auto e1 : a) cout<<e1<<" ";
	// cout<<"\n";
	// for(int i=0;i<k;i++) {
		// work();
		// for(auto e1 : a) cout<<e1<<" ";
		// cout<<"\n";
	// }
	
	// for(int i=0;i<k;i++) work();
	// for(auto e1 : a) cout<<e1<<" ";
	// cout<<"\n";
	
	if (k < 4) {
		for(int i=0;i<k;i++) work();
		for(auto e1 : a) cout<<e1<<" ";
	}
	else {
		for(int i=0;i<4;i++) work();
		if ((k-4)%2 == 0) {
			for(auto e1 : a) cout<<e1<<" ";
		}
		else {
			work();
			for(auto e1 : a) cout<<e1<<" ";
		}
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







