// Problem: Sequence Operation 2
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133880/I
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(1<<n);
	int sum=0;
	for(int i=1;i<(1<<n);i++) {
		a[i]=s[i-1]-'0';
		if (a[i]) sum^=i;
	}
	
	vector<int> ans(1<<n);
	for(int i=(1<<n)-1;i>=1;i--) {
		if (a[i] == 1 and i == sum) continue;
		if (a[i] == 0 and sum == 0 or a[i] == 0 and i != sum) continue;
		int b=__lg(i);
		int y=1<<b;
		int z=i^y;
		a[i]^=1;
		a[y]^=1;
		a[z]^=1;
		ans[i]=y;
	}
	
	for(int i=1;i<(1<<n);i++) cout<<ans[i]<<" ";
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







