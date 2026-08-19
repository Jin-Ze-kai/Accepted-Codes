// Problem: P1659 [国家集训队] 拉拉队排练
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1659
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=19930726;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	auto r=manacher(s);
	vector<int> c(n+1);
	for(int i=1;i<r.size();i+=2) {
		// assert((r[i]-1)&1);
		c[r[i]-1]++;
	}
	
	int ans=1;
	int sum=0;
	if (n%2 == 0) n--;
	for(int i=n;i>=1;i-=2) {
		sum+=c[i];
		if (k >= sum) (ans*=Pow(i,sum))%=p,k-=sum;
		else {
			(ans*=Pow(i,k))%=p;
			k-=sum;
			break;
		}
	}
	if (k > 0) cout<<"-1";
	else cout<<ans;
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







