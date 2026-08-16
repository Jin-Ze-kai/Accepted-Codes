// Problem: Light the Lamp
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133884/F
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

struct Node {
	int l,r;
	int siz,type,time;
};

int cost(Node x,int op) {
	int res=x.time;
	if (x.type == -op) res+=x.siz-1;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	vector<Node> st;
	for(int i=0;i<n;i++) {
		int p;
		cin>>p;
		st.push_back({p,p,1,0,0});
		while (st.size() >= 2) {
			Node y=st.back();
			st.pop_back();
			Node x=st.back();
			st.pop_back();
			int op=1;
			if (x.r == y.l-1) op=1;
			else if (x.l == y.r+1) op=-1;
			else {
				st.push_back(x);
				st.push_back(y);
				break;
			}
			
			Node z;
			z.l=min(x.l,y.l);
			z.r=max(x.r,y.r);
			z.siz=x.siz+y.siz;
			z.type=op;
			z.time=max(y.siz+cost(x,op),x.siz+cost(y,op));
			st.push_back(z);
		}
	}
	if (st.size() != 1) cout<<"-1\n";
	else cout<<st.back().time<<"\n";
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







