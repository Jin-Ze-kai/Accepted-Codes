// Problem: D. MEX Multiset
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/D
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=ranges::count(a,0);
	
	if (cnt == 0) {
		cout<<"YES\n";
		for(int i=0;i<n;i++) cout<<"A";
		cout<<"\n";
	}
	else if (cnt == 1) {
		cout<<"NO\n";
	}
	else {
		cout<<"YES\n";
		int c0=0;
		for(int i=0;i<n;i++) {
			if (a[i] != 0) cout<<"C";
			else {
				if (c0 == 0) cout<<"B";
				else cout<<"A";
				c0++;
			}
		}
		cout<<"\n";
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







