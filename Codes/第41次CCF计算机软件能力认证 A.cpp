#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		if (__lg(x)+1 == __builtin_popcount(x)*2) cnt++;
	}
	cout<<cnt<<"\n";
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







