// Problem: C. Sum of Distinct Values in a Matrix
// Contest: Codeforces - Educational Codeforces Round 193 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2253/problem/C
// Memory Limit: 512 MB
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
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<int> a(x),b(y);
	for(int i=0;i<x;i++) cin>>a[i];
	for(int i=0;i<y;i++) cin>>b[i];
	map<int,int,greater<int>> mark;
	for(int i=0;i<x;i++) mark[a[i]]=1;
	for(int i=0;i<y;i++) {
		if (mark[b[i]]) mark[b[i]]=3;
		else mark[b[i]]=2;
	}
	int c1=0,c2=0,c3=0;
	int sum=0;
	for(auto [num,f] : mark) {
		if (c1+c2+c3 == n+m-1) break;
		if (f == 3) sum+=num,c3++;
		else if (f == 1 and c1 < n) sum+=num,c1++;
		else if (f == 2 and c2 < m) sum+=num,c2++;
	}
	cout<<sum<<"\n";
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







