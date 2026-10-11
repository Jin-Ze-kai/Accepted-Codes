// Problem: P10308 「Cfz Round 2」Osmanthus
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10308
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct BIT {
	int n;
	vector<int> c;
	BIT(int n) : n(n),c(n+1,0) {}

	void add(int x,int y) {
		for (;x<=n;x+=x&-x) c[x]+=y;
	}

	int query(int x) {
		int res=0;
		for (;x;x-=x&-x) res+=c[x];
		return res;
	}
};

const int mod=1e9+7;
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	BIT b(n);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]) b.add(i,1);
	}
	// auto c=a;
		// for(auto x : a) cout<<x<<" ";
		// cout<<"\n";
	// for(int k=1;k<=16;k++) {
		// int cur=0;
		// for(int i=0;i<n;i++) {
			// cur^=a[i];
			// c[i]=cur;
		// }
		// a=c;
		// for(auto x : a) cout<<x<<" ";
		// cout<<"\n";
	// }
	
	int c0=0;
	for(int i=1;i<=n;i++) {
		if (a[i] == 0) c0++;
		else break;
	}
	while (q--) {
		int x,p;
		cin>>x>>p;
		if (a[x] != p) {
			if (a[x] == 0 and p != 0) {
				b.add(x,1);
				if (x <= c0) c0=x-1;
			}
			else if (a[x] != 0 and p == 0) {
				b.add(x,-1);
				if (x == c0+1) {
					int lo=1,hi=n,res=0;
					while (lo <= hi) {
						int mid=lo+hi>>1;
						if (b.query(mid) == 0) res=mid,lo=mid+1;
						else hi=mid-1;
					}
					c0=res;
				}
			}
			a[x]=p;
		}
		
		int c=n-c0;
		int ans=1;
		if (c > 1) {
			int pw=1;
			while (pw < c) pw<<=1;
			ans=pw%mod;
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







