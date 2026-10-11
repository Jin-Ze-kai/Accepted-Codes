// Problem: P10034 「Cfz Round 3」Circle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10034
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct Sieve {
    vector<int> spf,primes;

    Sieve(int n=5e5) : spf(n+1) {
        for (int i=2;i<=n;i++) {
            if (!spf[i]) primes.push_back(spf[i]=i);
            for (int p : primes) {
                if (i*p > n) break;
                spf[i*p]=p;
                if (i%p == 0) break;
            }
        }
    }

    // [质因子,指数] O(logn)
	vector<pair<int,int>> fact(int v) {
	    vector<pair<int,int>> res;
	    for (int p : primes) {
	        if (p*p > v or v < spf.size()) break;
	        if (v%p == 0) {
	            int c=0;
	            while (v%p == 0) v/=p,c++;
	            res.emplace_back(p,c);
	        }
	    }
	    while (v > 1 and v < spf.size()) {
	        int p=spf[v];
	        int c=0;
	        while (v%p == 0) v/=p,c++;
	        res.emplace_back(p,c);
	    }
	    if (v > 1) res.emplace_back(v,1);
	    return res;
	}

	//所有因数,O(O(fact)+因数个数)
    vector<int> divs(int v) {
        vector<int> res={1};
        for (auto [p,c] : fact(v)) {
            int sz=res.size();
            int x=p;
            for (int i=0;i<c;i++,x*=p)
                for (int j=0;j<sz;j++) res.push_back(res[j]*x);
        }
        return res;
    }
};

Sieve sieve;
void solve()
{
	int n,l;
	cin>>n>>l;
	string s;
	cin>>s;
	int c1=ranges::count(s,'1');
	if (l == 0 or c1 == 0) {
		for(int i=0;i<n;i++) cout<<(i+1)%n+1<<" ";
		cout<<"\n";
		return;
	}
	
	auto vec=sieve.fact(l);
	vector<int> dp(n+1);
	vector<int> f(n+1);
	dp[0]=1;
	for(int i=0;i<vec.size();i++) {
		int p=vec[i].first;
		for(int j=p;j<=n;j++) {
			dp[j]|=dp[j-p];
			if (!f[j] and dp[j-p]) f[j]=p;
		}
	}
	dp[n-1]=0;
	int x=0;
	for(int i=c1;i<=n;i++) {
		if (dp[i] != 0) {x=i;break;}
	}
	if (x == 0) {cout<<"-1\n";return;}
	
	vector<int> res;
	int sum=0;
	while (x != 0) {
		res.push_back(f[x]);
		sum+=f[x];
		x-=f[x];
	}
	if (sum != n) res.push_back(n-sum);
	ranges::reverse(res);
	// for(auto x : res) cout<<x<<" ";
	// cout<<"\n";
	vector<int> v,v0;
	for(int i=0;i<n;i++) {
		if (s[i] == '1') v.push_back(i+1);
		else v0.push_back(i+1);
	}
	for(auto x : v0) v.push_back(x);
	ranges::reverse(v);
	vector<int> ans(n+1);
	while (!res.empty()) {
		int c=res.back();
		res.pop_back();
		int st=v.back(),pre=st;
		v.pop_back();
		c--;
		while (c) {
			int cur=v.back();
			v.pop_back();
			ans[pre]=cur;
			pre=cur;
			c--;
		}
		ans[pre]=st;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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







