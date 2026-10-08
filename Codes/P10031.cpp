// Problem: P10031 「Cfz Round 3」Xor with Gcd
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10031
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	if (n&1) {
		cout<<n<<"\n";
	}
	else {
		cout<<(n^gcd(n/2,n))<<"\n";
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







