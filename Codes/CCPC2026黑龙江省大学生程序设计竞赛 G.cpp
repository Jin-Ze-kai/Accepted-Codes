// Problem: G. 卡卡数
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/G
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

const int p=998244353;
int calc(int x) {
	int res=0;
	while (x) {
		if (x%10 == 1) res++;
		x/=10;
	}
	return res;
}

int Pow(int base,int exp) {
	if (exp < 0) return 0;
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) (res*=base%p)%=p;
		(base*=base)%=p;
	}
	return res;
}

void solve()
{
	// int n;
	// cin>>n;
	// int sum=0;
	// for(int i=1;i<=n;i++) {
		// sum+=calc(i);
	// }
	// cout<<sum<<"\n";
	int x;
	cin>>x;
	cout<<x*Pow(10,x-1)%p<<"\n";
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







