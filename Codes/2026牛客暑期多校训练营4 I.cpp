// Problem: Rounddog II
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133879/I
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
	string s;
	cin>>s;
	int n=s.size();
	int k;
	cin>>k;
	string s1="Rounddo"+string(k,'g');
	string ns=s+s;
	ns.pop_back();
	int cnt=0;
	int pos=ns.find(s1);
	if (pos == -1) cout<<"0\n";
	else {
		pos=ns.find(s1,pos+1);
		if (pos == -1 or pos >= n) cout<<n-s1.size()+1<<"\n";
		else cout<<n<<"\n";
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







