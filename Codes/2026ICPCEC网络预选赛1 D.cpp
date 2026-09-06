#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> cnt(n);
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	int ans=1;
	int x=0,y=0;
	for(int i=0;i<n;i++) {
		if (x == y and cnt[x]) {
			cnt[x]--;
			(ans*=2)%=p;
			x++;
		}
		else if (x != y) {
			int mn=min(x,y);
			int mx=max(x,y);
			if (cnt[mn] > 0) {
				cnt[mn]--;
				if (x == mn) y++;
				else x++;
			}
			else if (cnt[mx] > 0) {
				cnt[mx]--;
				if (x == mx) y++;
				else x++;
			}
		}
	}
	cout<<ans<<"\n";
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







