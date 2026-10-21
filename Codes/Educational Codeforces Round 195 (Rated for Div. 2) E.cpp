// Problem: E. Good Substrings
// Contest: Codeforces - Educational Codeforces Round 195 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2276/E
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector nxt(n+1,vector<int>(10,-1));
	for(int i=n-1;i>=0;i--) {
		nxt[i][s[i]-'0']=i;
		for(int j=0;j<=9;j++) {
			if (nxt[i][j] != -1) continue;
			nxt[i][j]=nxt[i+1][j];
		}
	}
	
	vector<int> ans(n);
	for(int i=0;i<n;i++) ans[i]=(i+1)*(n-i);
	vector<int> d1(n+1),d2(n+1);
	for(int l=0;l<n;l++) {
		int r1=l;
		r1=nxt[r1][2];
		if (r1 == -1) continue;
		r1=nxt[r1][0];
		if (r1 == -1) continue;
		r1=nxt[r1][2];
		if (r1 == -1) continue;
		int r2=nxt[r1][6];
		if (r2 == -1) r2=n;
		r1=nxt[r1][5];
		if (r1 == -1) continue;
		if (r1 > r2) continue;
		d1[r1+1]--;
		d1[r2]++;
		d2[l]+=r2-r1;
		d2[r2]--;
	}
	for(int i=1;i<n;i++) d1[i]+=d1[i-1];
	for(int i=1;i<n;i++) d1[i]+=d1[i-1];
	for(int i=1;i<n;i++) d2[i]+=d2[i-1];
	
	// for(int i=0;i<n;i++) cout<<d1[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<n;i++) cout<<d2[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<n;i++) cout<<d1[i]+d2[i]<<" ";
	// cout<<endl;
	
	for(int i=0;i<n;i++) cout<<ans[i]-(d1[i]+d2[i])<<" ";
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







