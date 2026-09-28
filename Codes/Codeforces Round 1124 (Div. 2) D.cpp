// Problem: D. What a SauSaGe! It's All Meat
// Contest: Codeforces - Codeforces Round 1124 (Div. 2)
// URL: https://codeforces.com/contest/2269/problem/D
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> cnt(16);
	for(int i=0;i<n;i++) {
		cnt[a[i]]++;
	}
	auto calc=[&]() -> int {
		return cnt[0]+cnt[3]+cnt[6]+cnt[9]+cnt[12]+cnt[15]+cnt[5]+cnt[10];
	};
	
	cout<<calc()<<" ";
	while (q--) {
		int p,x;
		cin>>p>>x;
		p--;
		cnt[a[p]]--;
		a[p]=x;
		cnt[a[p]]++;
		cout<<calc()<<" ";
	}
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







