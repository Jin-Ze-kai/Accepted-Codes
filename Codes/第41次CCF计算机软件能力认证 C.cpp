#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct prog {
	vector<array<int,3>> vec;//{l,r,pos}
};

const int inf=1e18;
void solve()
{
	int n,q;
	cin>>n>>q;
	set<array<int,2>> st;
	vector<prog> a(n+1);
	st.insert({0,inf});
	while (q--) {
		string s;
		cin>>s;
		if (s == "new") {
			int p,L;
			cin>>p>>L;
			int l=-1,r=-1,len=2e18;
			for(auto x : st) {
				if (x[1]-x[0]+1 >= L and x[1]-x[0]+1 < len) {
					l=x[0];
					r=l+L-1;
					len=x[1]-x[0]+1;
				}
			}
			assert(l != -1);
			a[p].vec.push_back({l,r,0});
			auto it=st.lower_bound({l,0});
			int nr=(*it)[1];
			st.erase(it);
			if (nr >= r+1) st.insert({r+1,nr});
			cout<<l<<"\n";
		}
		else if (s == "send") {
			int p;
			cin>>p;
			int res=0;
			for(int i=0;i<a[p].vec.size();i++) {
				res+=a[p].vec[i][0]+a[p].vec[i][2]++;
				a[p].vec[i][2]%=a[p].vec[i][1]-a[p].vec[i][0]+1;
			}
			cout<<res<<"\n";
		}
		else {
			int p,pos;
			cin>>p>>pos;
			pos--;
			int l=a[p].vec[pos][0];
			int r=a[p].vec[pos][1];
			int nl=l,nr=r;
			a[p].vec.erase(a[p].vec.begin()+pos);
			auto it=st.lower_bound({r+1,0});
			if (it != st.end() and (*it)[0] == r+1) {
				nr=(*it)[1];
				st.erase(it);
			}
			it=st.lower_bound({l,0});
			if (it != st.begin()) {
				it=prev(it);
				if ((*it)[1] == l-1) {
					nl=(*it)[0];
					st.erase(it);
				}
			}
			st.insert({nl,nr});
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







