// Problem: H. Hidden Symmetry of Valdris
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/H
// Memory Limit: 256 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<int> manacher(string s) {
    string t="#";
    for (auto c : s) {
        t+=c;
        t+='#';
    }
    int n=t.size();
    vector<int> r(n);
    for (int i=0,j=0;i<n;i++) {
        if (2*j-i >= 0 and i < j+r[j]) r[i]=min(r[2*j-i],j+r[j]-i);
        while (i-r[i] >= 0 and i+r[i] < n and t[i-r[i]] == t[i+r[i]]) r[i]+=1;
        if (i+r[i] > j+r[j]) j=i;
    }
    return r;
}

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int ans=0;
	for(int i=0;i<n;i++) {
		if (s1[i] == s2[n-i-1] and s2[i] == s1[n-i-1]) ans++;
		else break;
	}
	// cout<<ans<<"\n";
	auto r1=manacher(s1);
	auto r2=manacher(s2);
	vector<int> pre(n+1);
	for(int i=0;i<2*n+1;i++) {
		int len=min(r1[i],r2[i])-1;
		if (len <= 0) continue;
		int l1=i-len>>1;
		int l2=i-1>>1;
		pre[l1]++;
		pre[l2+1]--;
	}
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
	for(int i=0;i<n;i++) {
		if (s1[i] == s2[n-i-1] and s2[i] == s1[n-i-1]) {
			if (i+1 < n) ans+=pre[i+1];
		}
		else break;
	}
	
	ranges::reverse(s1);
	ranges::reverse(s2);
	r1=manacher(s1);
	r2=manacher(s2);
	pre.assign(n+1,0);
	for(int i=0;i<2*n+1;i++) {
		int len=min(r1[i],r2[i])-1;
		if (len <= 0) continue;
		int l1=i-len>>1;
		int l2=i-1>>1;
		pre[l1]++;
		pre[l2+1]--;
	}
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
	for(int i=0;i<n;i++) {
		if (s1[i] == s2[n-i-1] and s2[i] == s1[n-i-1]) {
			if (i+1 < n) ans+=pre[i+1];
		}
		else break;
	}
	
	cout<<ans<<"\n";
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







