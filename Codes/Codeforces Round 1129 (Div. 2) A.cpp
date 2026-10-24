// Problem: A. Subset Selecting
// Contest: Codeforces - Codeforces Round 1129 (Div. 2)
// URL: https://codeforces.com/contest/2277/problem/A
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
	vector<int> cnt(110);
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	int rest=0;
	for(int i=0;i<110;i++) {
		if (cnt[i] and cnt[i]+rest >= k) {
			rest+=cnt[i]-k;
		}
		else {cout<<i<<"\n";return;}
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







