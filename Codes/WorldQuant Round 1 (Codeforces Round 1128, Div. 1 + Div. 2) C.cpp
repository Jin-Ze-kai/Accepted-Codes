// Problem: C. I Know About a Million Things
// Contest: Codeforces - WorldQuant Round 1 (Codeforces Round 1128, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2261/problem/C
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
	int n;
	cin>>n;
	int c1=0,c2=0;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		if (x&1) c1++;
		else c2++;
	}
	if (c1 == 0) cout<<"Moggity\n";
	else if (c1 == 1) {
		if (n == 2) cout<<"Larpity\n";
		else cout<<"Moggity\n";
	}
	else if (c1 == 3) {
		if (n == 3) cout<<"Larpity\n";
		else cout<<"Moggity\n";
	}
	else cout<<"Moggity\n";
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







