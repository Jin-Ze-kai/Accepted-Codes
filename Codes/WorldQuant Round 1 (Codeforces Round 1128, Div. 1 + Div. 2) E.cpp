// Problem: E. What Does the Cow Say?
// Contest: Codeforces - WorldQuant Round 1 (Codeforces Round 1128, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2261/problem/E
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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	vector<int> stk(1,0);
	for(int i=0;i<n;i++) {
		if (s[i] == '(') {
			int p=ranges::lower_bound(stk,stk.back()-k)-stk.begin();
			ans=max(ans,(int)stk.size()-p);
			if (stk.back() <= k) ans=max(ans,min(n/2,(int)stk.size()+k));
			stk.push_back(stk.back());
		}
		else {
			int x=stk.back();
			stk.pop_back();
			stk.pop_back();
			stk.push_back(x+1);
		}
	}
	cout<<ans<<"\n";
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







