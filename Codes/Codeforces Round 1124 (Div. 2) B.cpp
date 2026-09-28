// Problem: B. KiaKio and Squared Numbers
// Contest: Codeforces - Codeforces Round 1124 (Div. 2)
// URL: https://codeforces.com/contest/2269/problem/B
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) {
		for(int j=0;j<100;j++) {
			int x=0;
			int c=0;
			while (a[i]) {
				x+=a[i]%10*(a[i]%10);
				a[i]/=10;
			}
			a[i]=x;
		}
	}
	
	int ans=0;
	int c1=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 1) {c1++;continue;}
		for(int j=0;j<i;j++) {
			if (a[i] == a[j]) ans++;
		}
	}
	cout<<ans+(c1-1)*c1/2<<"\n";
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







