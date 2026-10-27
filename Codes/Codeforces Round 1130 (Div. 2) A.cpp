// Problem: A. Maximize One MEX
// Contest: Codeforces - Codeforces Round 1130 (Div. 2)
// URL: https://codeforces.com/contest/2272/problem/A
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
	int n,k;
	cin>>n>>k;
	vector<int> a,b;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		if (i <= n-k) a.push_back(x);
		else b.push_back(x);
	}
	if (k == 1 or *ranges::max_element(a) == a.size()-1) cout<<"-1\n";
	else {
		int p1=ranges::max_element(a)-a.begin();
		int p2=ranges::min_element(b)-b.begin();
		cout<<p1+1<<" "<<a.size()+p2+1<<"\n";
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







