// Problem: C. Yet Another Black Cell Problem
// Contest: Codeforces - Codeforces Round 1130 (Div. 2)
// URL: https://codeforces.com/contest/2272/problem/C
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
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	auto check=[&](int k) -> bool {
		vector<int> mark(n);
		int cnt=0;
		for(int i=0;i<n-1;i++) {
			if (mark[i]) {
				if (a[i+1]-a[i] <= k) mark[i+1]=1;
				else continue;
			}
			else {
				if (a[i+1]-a[i] <= k) mark[i]=mark[i+1]=1;
				else if (a[i+1]-a[i] <= 2*k) cnt++,mark[i]=mark[i+1]=1;
				else cnt++,mark[i]=1;
			}
		}
		
		if (mark[n-1] == 0) cnt++;
		return cnt <= x;
	};	
	int lo=1,hi=1e9,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res<<"\n";
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







