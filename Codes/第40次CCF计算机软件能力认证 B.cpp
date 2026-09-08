#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> k(m);
	vector<int> vec(n);
	for(int i=0;i<m;i++) cin>>k[i];
	for(int i=0;i<n;i++) cin>>vec[i];
	
	for(int i=m-1;i>=0;i--) {
		for(int j=0;j<n;j++) {
			int b=vec[j]>>6;
			int x=(vec[j]>>3)&7;
			int y=vec[j]&7;
			int c=x^(((b*b+k[i]*k[i])%8)^k[i]);
			int a=y^(((c*c+k[i]*k[i])%8)^k[i]);
			vec[j]=(a<<6)+(b<<3)+c;
		}
		// for(auto x : vec) cout<<x<<" ";
		// cout<<endl;
	}
	for(auto x : vec) cout<<x<<" ";
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







