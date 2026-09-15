// Problem: E. Treasure Map Destruction (Constructive Version)
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/E
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> d(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] != -1) d[i]=a[i];
	}
	for(int i=n-1;i>0;i--) d[i-1]=max(d[i-1],d[i]-1);
	for(int i=0;i<n-1;i++) d[i+1]=max(d[i+1],d[i]-1);
	
	vector<int> h(n);
	for(int i=0;i<n;i++) {
		if (d[i] == 0) h[i]=0;
		else h[i]=inf;
	}
	for(int i=n-1;i>0;i--) h[i-1]=min(h[i-1],h[i]+1);
	for(int i=0;i<n-1;i++) h[i+1]=min(h[i+1],	h[i]+1);
	
	bool ok=1;
	for(int i=0;i<n;i++) {
		if (a[i] != -1 and a[i] != h[i]) ok=0;
	}
	if (!ok) cout<<"-1\n";
	else {
		for(int i=0;i<n;i++) {
			cout<<(d[i] == 0);
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







