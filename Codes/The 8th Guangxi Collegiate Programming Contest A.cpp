// Problem: A. Additive Combinatorics
// Contest: Codeforces - The 8th Guangxi Collegiate Programming Contest
// URL: https://codeforces.com/gym/106707/problem/A
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
	int n,m,k;
	cin>>n>>m>>k;
	set<int> a,b,c;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		a.insert(x);
	}
	for(int i=0;i<m;i++) {
		int x;
		cin>>x;
		b.insert(x);
	}
	set<int> d;
	for(auto e1 : a) {
		for(auto e2 : b) {
			d.insert(e1+e2);
		}
	}
	for(int i=0;i<k;i++) {
		int x;
		cin>>x;
		c.insert(x);
	}
	if (c == d) cout<<"YES";
	else cout<<"NO";
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







