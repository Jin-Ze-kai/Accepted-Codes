// Problem: H. Hollow Knight: Silksong
// Contest: Codeforces - The 8th Guangxi Collegiate Programming Contest
// URL: https://codeforces.com/gym/106707/problem/H
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

int d[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	while (a != 2025 or b != 9 or c != 18) {
		ans++;
		c++;
		int nb=d[b]+(b == 2 and a%4 == 0);
		if (c > nb) {
			c=1;
			b++;
			if (b > 12) {
				a++;
				b=1;
			}
		}
	}
	cout<<ans;
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







