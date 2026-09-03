#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct Node {
	int t,a,b;
    bool operator<(const Node& other) const {
        return b*other.a > other.b*a;
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<Node> v1;
	vector<Node> v2;
	int sum=0;
	for(int i=0;i<n;i++) {
		int o,t,a,b;
		cin>>o>>t>>a>>b;
		if (o) v1.push_back({t,a,b});
		else v2.push_back({t,a,b});
		sum+=t;
	}
	sort(v2.begin(),v2.end());
	
	vector<int> dp(m+1);
	for(int i=0;i<v1.size();i++) {
		for(int j=m;j>=v1[i].a;j--) {
			dp[j]=max(dp[j],dp[j-v1[i].a]+v1[i].b);
		}
	}
	
	double ans=sum;
	for(int i=0;i<=m;i++) {
		double cur=sum-dp[i];
		int rest=m-i;
		for(int j=0;j<v2.size();j++) {	
			if (rest == 0) break;
			if (rest >= v2[j].a) rest-=v2[j].a,cur-=v2[j].b;
			else {
				cur-=(double)rest/v2[j].a*v2[j].b;
				break;
			}
		}
		ans=min(ans,cur);
	}
	cout<<fixed<<setprecision(10)<<ans<<"\n";
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







