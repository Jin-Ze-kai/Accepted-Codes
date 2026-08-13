// Problem: B. 最大数码 2
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/B
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

pair<int,string> work(int x) {
	auto s=to_string(x);
	return {*ranges::max_element(s)-'0',s};
}

void solve()
{
	int l,r;
	cin>>l>>r;
	if ((int)log10(l) == (int)log10(r)) {
		auto [ans,s]=work(l);
		for(int i=l+1;i<=min(l+10,r);i++) {
			auto [cur,ns]=work(i);
			if (cur > ans) ans=cur,s=ns;
		}
		cout<<ans<<" "<<s<<"\n";
	}
	else {
		auto [ans1,s1]=work(l);
		for(int i=l+1;i<=min(l+10,r);i++) {
			auto [cur,ns]=work(i);
			if (cur > ans1) ans1=cur,s1=ns;
		}
		
		l=(int)pow(10,(int)log10(l)+1);
		while (l < r) {
			auto [ans2,s2]=work(l);
			for(int i=l+1;i<=min(l+10,r);i++) {
				auto [cur,ns]=work(i);
				if (cur > ans2) ans2=cur,s2=ns;
			}
			if (ans1 < ans2) ans1=ans2,s1=s2;
			else if (ans1 == ans2) {
				if (s1 > s2) ans1=ans2,s1=s2;
			}
			l=(int)pow(10,(int)log10(l)+1);
		}
		cout<<ans1<<" "<<s1<<"\n";
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







