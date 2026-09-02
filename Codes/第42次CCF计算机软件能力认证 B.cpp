#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k,m;
	cin>>n>>k>>m;
	int lo=1,hi=1e9,res=-1;
	
	auto check=[&](int x) -> bool {
		int t=n;
		int cnt=0;
		while (1) {
			t-=(t*k+99)/100;
			t-=x;
			if (t >= 0) cnt++;
			else break; 
		}
		return cnt >= m;
	};
	
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,lo=mid+1;
		else hi=mid-1;
	}
	assert(res != -1);
	cout<<res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
//	cin>>t;
	while (t--)
		solve();
	return 0;
}
