// Problem: B. Bad LaTeX
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	string _;
	getline(cin,_);
	auto check1=[&](string s) -> bool {
		for(auto c : s) {
			if ('0' <= c and c <= '9') continue;
			else return 0;
		}
		return 1;
	};
	
	for(int i=0;i<n;i++) {
		string s;
		getline(cin,s);
		s=" "+s+" ";
		// cout<<s<<"\n";
		int l,r=0;
		string res;
		while (1) {
			l=r,r=s.find(" ",r+1);
			while (r != -1 and !check1(s.substr(l+1,r-l-1))) {
				res+=s.substr(l+1,r-l-1)+" ";
				l=r,r=s.find(" ",r+1);
			}
			if (r == -1) break;
			string s1=s.substr(l+1,r-l-1);
			int c0=0;
			for(int j=s1.size()-1;j>=0;j--) {
				if (s1[j] != '0') break;
				c0++;
			}
			if (c0 < 4) res+=s1+" ";
			else if (c0 == s1.size()-1 and s1[0] == '1') {
				res+="10^{"+to_string(c0)+"} ";
				// s.replace(l+1,r-l-1,"10^{"+to_string(c0)+"}");
			}
			else if (c0 == s1.size()-1) {
				res+=s1.substr(0,1)+"\\cdot10^{"+to_string(c0)+"} ";
				// s.replace(l+1,r-l-1,s1.substr(0,1)+"\\cdot10^{"+to_string(c0)+"}");
			}
			else {
				res+=s1.substr(0,1)+"."+s1.substr(1,s1.size()-1- c0)+"\\cdot10^{"+to_string(s1.size()-1)+"} ";
				// s.replace(l+1,r-l-1,s1.substr(0,1)+"."+s1.substr(1,s1.size()-1-c0)+"\\cdot10^{"+to_string(s1.size()-1)+"}");
			}
		}
		cout<<res.substr(0,res.size()-1)<<"\n";
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







