// Problem: C. 101
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/C
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
	for(int i=0;i<n;i++) {
		if (a[i] == 1) break;
		else if (a[i] == -1) {a[i]=1;break;}
	}
	for(int i=n-1;i>=0;i--) {
		if (a[i] == 1) break;
		else if (a[i] == -1) {a[i]=1;break;}
	}
	for(int i=0;i<n;i++) {
		if (a[i] == -1) a[i]=0;
	}
	for(auto e1 : a) cout<<e1<<" ";
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







