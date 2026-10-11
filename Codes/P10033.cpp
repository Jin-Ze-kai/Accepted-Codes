// Problem: P10033 「Cfz Round 3」Sum of Permutation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10033
// Memory Limit: 512 MB
// Time Limit: 500 ms
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
	vector<int> a(n),v(n+1);
	for(int i=0;i<n;i++) cin>>a[i],v[a[i]]=i;
	if (n == 2) cout<<"-1\n";
	else if (abs(v[1]-v[2]) == 1) {
		if (abs(v[1]-v[3]) == 1) {
			if (n == 3) {
				for(int i=0;i<n;i++) {
					if (a[i] == 3) cout<<"2 ";
					else cout<<"3 ";
				}
				cout<<"\n";
			}
			else {
				for(int i=0;i<n;i++) {
					if (a[i] == 1) cout<<"4 ";
					else if (a[i] == 3) cout<<"2 ";
					else cout<<"1 ";
				}
				cout<<"\n";
			}
		}
		else {
			for(int i=0;i<n;i++) {
				if (a[i] == 1) cout<<"3 ";
				else cout<<"1 ";
			}
			cout<<"\n";
		}
	}
	else {
		for(int i=0;i<n;i++) {
			if (a[i] == 1) cout<<"2 ";
			else cout<<"1 ";
		}
		cout<<"\n";
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







