// Problem: F. MEX Replacement
// Contest: Codeforces - Codeforces Round 1122 (Div. 3)
// URL: https://codeforces.com/contest/2266/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e16;
void solve()
{
	int n;
	cin>>n;
	
	int maxn=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		mp[x]=y;
		maxn=max(x,maxn);
	}
	if (maxn >= 2e5+500) {cout<<maxn<<"\n";return;}
	int ans=maxn;
	for(int c=0;c<500;c++) {
		int cnt=0;
		int d=1;
		bool ok=1;
		for(int i=maxn+c;i>=1;i--) {
			if (mp.count(i)) {
				if (mp[i] == d) continue;
				else if (mp[i] > d) {
					cnt+=mp[i]-d;
				}
				else {
					d*=2;
					d-=mp[i];
				}
			}
			else {
				d*=2;
			}
			if (d > inf) {ok=0;break;}
		}
		if (ok and mp[0]+cnt >= d) ans++;
		else break;
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







