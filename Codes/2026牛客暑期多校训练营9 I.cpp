// Problem: Slay the Spire
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133884/I
// Memory Limit: 1024 MB
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
	int x,a,b;
	cin>>x>>a>>b;
	int lo=1,hi=x,res=-1;
	
	auto calc=[&](int t,int p) {
		int pre=p+p*(p+1)/2*(a-1);
		int m=min(t-p,(a-1)*p);
		int cur=m*(a-1)*p-m*(m-1)/2;
		return (t-p)*b+pre+cur;
	};
	
	auto check=[&](int t) -> bool {
		if (a == 1) return t*b >= x;
		int s=(t+a-1)/a;//毒够用
		int ans=calc(t,0);
		if (s >= 1) ans=max(ans,calc(t,s-1));
		int lo=s,hi=t,res=-1;
	    while (hi-lo > 3) {
	        int m1=lo+(hi-lo)/3;
	        int m2=hi-(hi-lo)/3;
	        if (calc(t,m1) < calc(t,m2)) lo=m1+1;
	        else hi=m2-1;
	    }
	    res=calc(t,lo);
	    for (int i=lo+1;i<=hi;i++){
	        res=max(res,calc(t,i));
	    }
	    ans=max(res,ans);
	    return ans >= x;
	};
	
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) hi=mid-1,res=mid;
		else lo=mid+1;
	}
	cout<<res<<"\n";
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







