// Problem: E. Chronostasis
// Contest: Codeforces - Codeforces Round 1114 (Div. 3)
// URL: https://codeforces.com/contest/2254/problem/E
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
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>b[i];
	int sum=accumulate(b.begin(),b.end(),0ll);
	if (sum <= 0) {cout<<"-1\n";return;}
	
	multiset<int> st;
	for(int i=0;i<n;i++) st.insert(b[i]);
	int cur=0;
	for(int i=0;i<n;i++) {
		auto it=st.lower_bound(1-cur);
		assert(it != st.end());
		cur+=*it;
		st.erase(it);
		cout<<cur<<" ";
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







