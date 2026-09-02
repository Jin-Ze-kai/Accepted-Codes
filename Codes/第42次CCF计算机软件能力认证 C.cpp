#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e5;
struct prog {
	char type;
	int a[41],t[41];
	int st,w,k;
	int ans,l,r;
	int cur;//当前任务
	int pos;//当前进程
	int fail;//失败次数
	bool aply;//是否处于申请状态
	bool work;//是否处于任务运行状态
	bool fin;//是否已结束
	set<int> S;
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<prog> vec(n+1);
	vector<int> bel(m+1);
	for(int i=1;i<=n;i++) {
		cin>>vec[i].type;
		if (vec[i].type == 'X') {
			cin>>vec[i].st>>vec[i].k;
			for(int j=0;j<vec[i].k;j++) {
				cin>>vec[i].a[j]>>vec[i].t[j];
				// cout<<vec[i].a[j]<<" "<<vec[i].t[j]<<"\n";
			}
		}
		else {
			cin>>vec[i].st>>vec[i].w>>vec[i].k;
			for(int j=0;j<vec[i].k;j++) {
				cin>>vec[i].a[j]>>vec[i].t[j];
			}
		}
	}
	
	int cnt=0;
	for(int tim=1;tim<=inf;tim++) {
		if (cnt == n) break;
		for(int i=1;i<=n;i++) {
			if (vec[i].fin) continue;
			if (tim == vec[i].st) {
				vec[i].aply=1;
				vec[i].l=tim;
			}
		}
		
		//抢夺
		for(int i=1;i<=n;i++) {
			if (vec[i].fin or !vec[i].aply or vec[i].type != 'C' or vec[i].fail != vec[i].w) continue;
			int x=vec[i].a[vec[i].cur];
			vec[bel[x]].S.erase(x);
			vec[i].S.insert(x);
			bel[x]=i;
			vec[i].aply=0;
			vec[i].work=1;
			vec[i].fail=0;
		}
		
		//申请
		for(int i=1;i<=n;i++) {
			if (vec[i].fin or !vec[i].aply) continue;
			
			if (vec[i].type == 'X' or vec[i].type == 'C') {
				if (bel[vec[i].a[vec[i].cur]]) {vec[i].fail++;continue;}
				bel[vec[i].a[vec[i].cur]]=i;
				vec[i].S.insert(vec[i].a[vec[i].cur]);
				vec[i].aply=0;
				vec[i].work=1;
			}
			else if (vec[i].type == 'A') {
				if (bel[vec[i].a[vec[i].cur]]) vec[i].fail++;
				else {
					bel[vec[i].a[vec[i].cur]]=i;
					vec[i].S.insert(vec[i].a[vec[i].cur]);
					vec[i].aply=0;
					vec[i].work=1;
					vec[i].fail=0;
				}
			}
			else if (vec[i].type == 'B') {
				if (bel[vec[i].a[vec[i].cur]]) vec[i].fail++;
				else {
					bel[vec[i].a[vec[i].cur]]=i;
					vec[i].S.insert(vec[i].a[vec[i].cur]);
					vec[i].aply=0;
					vec[i].work=1;
					vec[i].fail=0;
				}
				
				if (vec[i].fail == vec[i].w) {
					vec[i].aply=0;
					vec[i].work=1;
					vec[i].fail=0;
				}
			}
		}
		
		//段中任务运行
		for(int i=1;i<=n;i++) {
			if (vec[i].fin or !vec[i].work) continue;
			vec[i].pos++;
			vec[i].ans+=vec[i].S.size();
			if (vec[i].pos == vec[i].t[vec[i].cur]) {
				vec[i].pos=0;
				vec[i].cur++;
				vec[i].work=0;
				vec[i].aply=1;
			}
		}
		
		//段末
		for(int i=1;i<=n;i++) {
			if (!vec[i].fin and vec[i].type == 'A' and vec[i].fail == vec[i].w) {
				vec[i].fail=0;
				for(auto x : vec[i].S) bel[x]=0;
				vec[i].S.clear();
			}
			if (!vec[i].fin and vec[i].cur == vec[i].k) {
				vec[i].fin=1;
				cnt++;
				for(auto x : vec[i].S) bel[x]=0;
				vec[i].S.clear();
				vec[i].r=tim;
			}
		}
	}
	
	for(int i=1;i<=n;i++) {
		if (vec[i].fin == 1) {
			cout<<vec[i].ans<<" "<<vec[i].r-vec[i].l+1<<"\n";
		}
		else {
			cout<<vec[i].ans<<" -1\n";
		}
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







