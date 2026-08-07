// Problem: D-Mail Institution Codes
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133882/K
// Memory Limit: 2048 MB
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
	string _;
	getline(cin,_);
	vector<vector<string>> vec(n);
	for(int i=0;i<n;i++) {
		string s;
		getline(cin,s);
		string res;
		for(int j=0;j<s.size();j++) {
			if (s[j] == ' ') continue;
			res+=s[j];
		}
		string t;
		vec[i].push_back(res);
		// cout<<res<<"\n";
		for(int p=res.size()-1;p>=0;p--) {
			if ('a' <= res[p] and res[p] <= 'z') continue;
			t=res[p]+t;
			vec[i].push_back(res.substr(0,p)+t);
		}
		ranges::reverse(vec[i]);
	}
	
	vector<int> a(n);
	vector<bool> mark(n);
	while (1) {
		map<string,int> cnt;
		for(int i=0;i<n;i++) cnt[vec[i][a[i]]]++;
		for(int i=0;i<n;i++) {
			if (!mark[i] and cnt[vec[i][a[i]]] == 1) mark[i]=1;
		}
		bool ok=1;
		for(int i=0;i<n;i++) {
			if (!mark[i]) {
				ok=0;
				if (a[i] < vec[i].size()-1) a[i]++;
			}
		}
		if (ok) break;
	}
	
	for(int i=0;i<n;i++) {
		cout<<vec[i][a[i]]<<"\n";
	}
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







