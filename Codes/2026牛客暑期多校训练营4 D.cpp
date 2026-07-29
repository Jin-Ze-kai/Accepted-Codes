// Problem: The Game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133879/D
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
int n;
vector<int> vec;
vector<bool> mark;
vector<int> f1(int p);
vector<int> f2(int p);

vector<int> work(vector<int>& v) {
	auto res=v;
	int m=v.size();
	for(int i=1;i<m;i++) {
		vector<int> v1;
		for(int j=0;j<m;j++) v1.push_back(v[(i+j)%m]);
		if (v1 < res) res=v1;
	}
	return res;
};

vector<int> f1(int p) {
	if (p == n) return work(vec);
	vector<int> res;
	for(int i=1;i<=n;i++) {
		if (mark[i]) continue;
		mark[i]=1;
		vec.push_back(i);
		vector<int> v1=f2(p+1);
		if (res.empty() or res > v1) res=v1;
		mark[i]=0;
		vec.pop_back();
	}
	return res;
}

vector<int> f2(int p) {
	if (p == n) return work(vec);
	vector<int> res;
	for(int i=1;i<=n;i++) {
		if (mark[i]) continue;
		mark[i]=1;
		vec.push_back(i);
		vector<int> v1=f1(p+1);
		if (res.empty() or res < v1) res=v1;
		mark[i]=0;
		vec.pop_back();
	}
	return res;
}

void solve()
{
	cin>>n;
	vec.clear();
	mark.assign(n+1,0);
	vector<int> ans=f1(0);
	for(auto e1 : ans) cout<<e1<<" ";
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







