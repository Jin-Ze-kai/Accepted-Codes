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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	string s;
	cin>>s;
	vector<int> l1,r0;
	int c0=0;
	for(int i=n-1;i>=0;i--) {
		if (a[i]) r0.push_back(c0);
		else c0++;
	}
	int c1=0;
	for(int i=0;i<n;i++) {
		if (!a[i]) l1.push_back(c1);
		else c1++;
	}
	
	int cl=0,cr=0;
	int ans=accumulate(l1.begin(),l1.end(),0ll);
	cout<<ans<<" ";
	for(auto x : s) {
		if (ans == 0) cout<<"0 ";
		else if (x == '1') {
			ans-=r0.back()-cr;
			cl++;
			r0.pop_back();
			cout<<ans<<" ";
		}
		else {
			ans-=l1.back()-cl;
			cr++;
			l1.pop_back();
			cout<<ans<<" ";
		}
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







