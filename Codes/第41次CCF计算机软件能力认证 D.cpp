#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int n,m,k;
int calc(int x,int y)
{
	int t=1;
	int ans=0;
	while (x or y) {
		ans+=t*((x%k+y%k)%k);
		t*=k;
		x/=k;
		y/=k;
	}
	return ans;
}

int f1(int x) {
	if (x == 0) return 0;
	return calc(x,f1(x-1));
}

int f2(int x) {
	int y=x%k;
	int ans=(1+y)*y/2%k;
	x/=k;
	int t=k;
	while (x) {
		ans+=t*(x%k*(y+1)%k);
		y+=t*(x%k);
		x/=k;
		t*=k;
	}
	return ans;
}

void solve()
{
	cin>>n>>m>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	// for(int i=1;i<=1000;i++) {
		// cout<<i<<" "<<f1(i)<<" "<<f2(i)<<"\n";
	// }
	
	while (m--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int l,r,v;
			cin>>l>>r>>v;
			l--,r--;
			for(int i=l;i<=r;i++) {
				a[i]=calc(a[i],v);
			}
		}
		else {
			int l,r;
			cin>>l>>r;
			l--,r--;
			int ans=0;
			for(int i=l;i<=r;i++) {
				ans=calc(ans,f2(a[i]));
			}
			cout<<ans<<"\n";
		}
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







