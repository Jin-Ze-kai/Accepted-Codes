#include<bits/stdc++.h>
// #define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e9;
const int N=1e6;
int tree[N][26];
int val[N];
int len=1;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	val[0]=inf;
	for(int i=n-1;i>=0;i--) {
		int cur=0;
		for(int j=i;j<n;j++) {
			if (!tree[cur][s[j]-'a']) {
				if (val[cur] > i) {
					tree[cur][s[j]-'a']=len++;
					cur=tree[cur][s[j]-'a'];
					val[cur]=i;
				}
				else break;
			}
			else cur=tree[cur][s[j]-'a'];
		}
	}
	
	queue<array<int,2>> q;
	q.push({0,0});
	int ans=0;
	while (!q.empty()) {
		auto [u,d]=q.front();
		q.pop();
		// cout<<u<<" "<<d<<"\n";
		for(int i=0;i<26;i++) {
			if (!tree[u][i]) continue;
			ans=max(ans,d+1);
			q.push({tree[u][i],d+1});
		}
	}
	cout<<ans<<"\n";
	
	for(int i=0;i<len;i++) {
		val[i]=0;
		for(int j=0;j<26;j++) tree[i][j]=0;
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







