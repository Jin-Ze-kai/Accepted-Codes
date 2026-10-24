// Problem: D1. Number Operating (Easy Version)
// Contest: Codeforces - Codeforces Round 1129 (Div. 2)
// URL: https://codeforces.com/contest/2277/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int l,r;
	cin>>l>>r;
	// if (l == 0) l++;
	// int lst=l;
	// int ans=0;
	// for(int b=0;b<61;b++) {
		// int x=(1ll<<b)-1;
		// if (x < l) continue;
		// if (x > r) {
			// if (lst > r) break;
			// ans+=(r-lst+1)*b+(x-r+x-lst)*(r-lst+1)/2;
			// break;
		// }
		// ans+=(x-lst+1)*b+(x-lst)*(x-lst+1)/2;
		// lst=x+1;
	// }
	
	// unordered_map<int,int> mp;
	// for(int b=0;b<60;b++) {
		// int x=(1ll<<b)-1;
		// mp[x]=b;
		// for(int i=1;i<200;i++) {
			// if (x-i < 0) break;
			// if (mp.count(x-i)) mp[x-i]=min(mp[x-i],b+i);
			// else mp[x-i]=b+i;
		// }
	// }
// 	
	// auto calc=[&](auto&& self,int x) -> int {
		// if (mp.count(x)) return mp[x];
		// for(int i=60;i>=0;i--) {
			// if ((1ll<<i)&x) {
				// return i+3+self(self,x-(1ll<<i));
			// }
		// }
	// };
	
	auto calc=[&](auto&& self,int x) -> int {
		int b=__lg(x+1);
		int val=(1ll<<b)-1;
		if (x == val) return b;
		
		int res1=b+1+(1ll<<(b+1))-1-x;
		if (b == 1) return 3;
		int res2=b+1+self(self,x-val+1);
		return min(res1,res2);
	};
	
	int ans=0;
	for(int i=l;i<=r;i++) {
		(ans+=calc(calc,i))%=p;
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







