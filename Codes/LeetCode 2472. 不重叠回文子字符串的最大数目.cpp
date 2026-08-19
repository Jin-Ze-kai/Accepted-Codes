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
	string s;
	int k;
	cin>>s>>k;
    auto r=manacher(s);
    int n=s.size();
	vector<int> dp(n+1);
	for(int i=0;i<n;i++) {
		dp[i+1]=dp[i-1+1];
		int l=i-k+1;
		if (l < 0) continue;
		int p=l+i+1;
		if (r[p]-1 >= k) dp[i+1]=max(dp[i+1],dp[i-k+1]+1);
		
		l=i-k;
		if (l < 0) continue;
		p=l+i+1;
		if (r[p]-1 >= k) dp[i+1]=max(dp[i+1],dp[i-k-1+1]+1);
	}
	// for(auto e1 : dp) cout<<e1<<" ";
	// cout<<endl;
	cout<<dp.back()<<"\n";
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






