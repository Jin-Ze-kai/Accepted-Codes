#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<double> a(n),b(n);
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		auto s1=s.substr(0,s.size()-2);
		auto s2=s.substr(s.size()-1,1);
		auto x=stoll(s1);
		auto y=stoll(s2);
		if (y <= 4) a[i]=x;
		else a[i]=x+1;
		if (y <= 4) b[i]=x;
		else if (y >= 6) b[i]=x+1;
		else {
			if (x&1) b[i]=x+1;
			else b[i]=x;
		}
	}
	
	for(auto x : a) cout<<x<<" ";
	cout<<"\n";
	for(auto x : b) cout<<x<<" ";
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


