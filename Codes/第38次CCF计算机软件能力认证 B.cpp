#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dx[]={-1,1,2,2,1,-1,-2,-2};
int dy[]={2,2,1,-1,-2,-2,-1,1};
void solve()
{
	int n,k;
	cin>>n>>k;
	vector g(n,vector<int>(n));
	int x0,y0;
	cin>>x0>>y0;
	x0--,y0--;
	if (k == 0) {cout<<1;return;}
	vector dis(n,vector<int>(n,-1));
	queue<array<int,2>> q;
	dis[x0][y0]=0;
	q.push({x0,y0});
	int ans=0;
	while (!q.empty()) {
		auto [x,y]=q.front();
		q.pop();
		ans++;
		if (dis[x][y] == k) continue;
		for(int i=0;i<8;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= n or dis[nx][ny] != -1) continue;
			dis[nx][ny]=dis[x][y]+1;
			q.push({nx,ny});
		}
	}
	cout<<ans;
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







