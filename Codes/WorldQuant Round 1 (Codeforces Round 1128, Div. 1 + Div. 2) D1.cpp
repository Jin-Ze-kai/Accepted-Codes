// Problem: D1. Come Be My Friend, Don't Be So Scared (Easy Version)
// Contest: Codeforces - WorldQuant Round 1 (Codeforces Round 1128, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2261/problem/D1
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

void solve()
{
	int n,m;
	cin>>n>>m;
	if (n == 1) {cout<<"0\n";return;}
	cout<<(n+1>>1)<<"\n";
	if (n&1) {
		for(int i=1;i<=n>>1;i++) {
			cout<<i<<" "<<i+(n>>1)-1<<"\n";
		}
		cout<<n<<" "<<n<<"\n";
	}
	else {
		for(int i=1;i<=n+1>>1;i++) {
			cout<<i<<" "<<i+(n+1>>1)-1<<"\n";
		}
	}
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







