// Problem: D. Hypercarp and Interdimensional Jumps
// Contest: Codeforces - Educational Codeforces Round 193 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2253/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int x,y;
	cin>>x>>y;
	int m=0;
	while ((m+1)*(m+2)/2 <= x+y) m++;
	// cout<<m<<"\n";
	int ax=0;
	int dis=inf;
	for(int i=max(0ll,m*(m+1)/2-y);i<=x;i++) {
		int cur=(i-x)*(i-x)+(m*(m+1)/2-i-y)*(m*(m+1)/2-i-y);
		if (cur < dis) dis=cur,ax=i;
	}
	// cout<<ax<<"\n";
	for(int i=0;i<m;i++) {
		if (ax-(m-i) >= 0) ax-=m-i,cout<<"X";
		else cout<<"Y";
	}
	cout<<"\n";
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






