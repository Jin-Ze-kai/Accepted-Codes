// Problem: F. Whiplash
// Contest: Codeforces - Codeforces Round 1114 (Div. 3)
// URL: https://codeforces.com/contest/2254/problem/F
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
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector<int> aa(n),bb(n);
	int x=0,y=0;
	for(int i=0;i<n;i++) x^=a[i];
	for(int i=0;i<n;i++) y^=b[i];
	for(int i=0;i<n;i++) aa[i]=x^a[i];
	for(int i=0;i<n;i++) bb[i]=y^b[i];
	
	aa.push_back(x);
	bb.push_back(y);
	ranges::sort(aa);
	ranges::sort(bb);
	if (aa == bb) cout<<"YES\n";
	else cout<<"NO\n";
	
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







