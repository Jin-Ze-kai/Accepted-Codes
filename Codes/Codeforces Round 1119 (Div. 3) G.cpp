// Problem: G. Index Removal
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
struct Info {
	int sum;
	Info() : sum(0) {};
    Info(int val) : sum(val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.sum=sum+other.sum;
    	return res;
    }
};

struct SegTree {
	int n;
	vector<Info> tree;
	SegTree(int _) {
		n=_;
		tree.resize(n*4);
	}
	
	void Set(int p,int l,int r,int id,int val) {
		if (l == r) {tree[p]=Info(val);return;}
		int m=l+r>>1;
		if (id <= m) Set(2*p,l,m,id,val);
		else Set(2*p+1,m+1,r,id,val);
		tree[p]=tree[p*2]+tree[p*2+1];
	}
	
	Info query(int p,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return tree[p];
		int m=l+r>>1;
		return query(2*p,l,m,ql,qr)+query(2*p+1,m+1,r,ql,qr);
	}
};


void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> b(n+1);
	for(int i=1;i<=n;i++) {
		b[i]=k-(a[i]-a[i-1]);
	}
	auto pre=b;
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
	// for(auto e1 : b) cout<<e1<<" ";
	// cout<<endl;
	// for(auto e1 : pre) cout<<e1<<" ";
	// cout<<endl;
	SegTree st(n+1);
	for(int i=1;i<=n;i++) st.Set(1,1,n,i,pre[i]);
	
	cout<<"0 ";
	for(int i=2;i<=n-1;i++) {
		int x=k-b[i];
		if (x == 0) {cout<<"0 ";continue;}
		int lo=i+1,hi=n,res=n+1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (pre[mid]-pre[i] >= x) res=mid,hi=mid-1;
			else lo=mid+1;
		}
		// if (i == 2) cout<<st.query(1,1,n,i+1,res-1).sum<<endl;
		cout<<(res-i-1)*x-(st.query(1,1,n,i+1,res-1).sum-(res-i-1)*pre[i])<<" ";
	}
	cout<<"0\n";
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







