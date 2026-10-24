// Problem: B. Sequence Decreasing
// Contest: Codeforces - Codeforces Round 1129 (Div. 2)
// URL: https://codeforces.com/contest/2277/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n;
	cin>>n;
	int mx=inf;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		mx=min(mx,x);
	}
	if (mx >= n) cout<<"0\n";
	else cout<<n<<"\n";
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







