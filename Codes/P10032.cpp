// Problem: P10032 「Cfz Round 3」Mex of Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10032
// Memory Limit: 512 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void MEX(vector<int>& a,vector<int>& b,int n) {
	vector<int> cnt(n);
	for(int i=0;i<n;i++) {
		if (a[i] >= n) continue;
		cnt[a[i]]++;
	}
	int mex=0;
	for(int i=0;i<n;i++) {
		if (cnt[i]) mex++;
		else break;
	}
	
	for(int i=0;i<n;i++) {
		if (a[i] >= n) b[i]=mex;
		else if (cnt[a[i]] == 1) {
			if (a[i] > mex) b[i]=mex;
			else b[i]=a[i];
		}
		else b[i]=mex;
	}
	swap(a,b);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	auto b=a;
	if (m <= 3) {
		for(int i=1;i<=m;i++) MEX(a,b,n);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	else {
		for(int i=1;i<=3;i++) MEX(a,b,n);
		if (m%2 == 0) {
			for(int i=0;i<n;i++) cout<<b[i]<<" ";
			cout<<"\n";
		}
		else {
			for(int i=0;i<n;i++) cout<<a[i]<<" ";
			cout<<"\n";
		}
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







