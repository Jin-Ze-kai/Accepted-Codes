// Problem: Not Aqre 2
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133878/F
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
    const int n=A.size();
    vector C(n,vector<int>(n,0));
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
            if (A[i][k] == 0) continue;
            for (int j=0;j<n;j++) {
                (C[i][j]+=A[i][k]*B[k][j])%=p;
            }
        }
    }
    return C;
}

vector<vector<int>> Pow(vector<vector<int>> E,vector<vector<int>> A,int exp) {
    for (;exp;exp>>=1) {
        if (exp&1) E=E*A;
        A=A*A;
    }
    return E;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	if (n == 1) {
		cout<<3*Pow(2,m-1)%p<<"\n";
		return;
	}
	
	int N=1<<(n-2);
	vector A(N,vector<int>(N,0));
	vector<int> a(n),b(n);
	auto dfs=[&](auto&& self,int x,int pre) -> void {
		if (x != n) {
			for(int i=0;i<3;i++) {
				if (a[x] == i) continue;
				if (x != 0 and b[x-1] == i) continue;
				b[x]=i;
				self(self,x+1,pre);
			}
			return;
		}
		
		int c=1,B=0;
		for(int i=2;i<n;i++) {
			int p;
			if (b[i] == b[0]) p=0;
			else if (b[i] == b[1]) p=1;
			else p=2;
			if ((c+1)%3 == p) B|=(1<<(i-2));
			c=p;
		}
		A[pre][B]++;
	};
	
	for(int i=0;i<N;i++) {
		a[0]=0;
		a[1]=1;
		for(int j=2;j<n;j++) {
			if ((i>>(j-2))&1) a[j]=a[j-1]+1;
			else a[j]=a[j-1]-1;
			a[j]=(a[j]+3)%3;
		}
		dfs(dfs,0,i);
	}
	
	vector E(N,vector<int>(N,0));
	for(int i=0;i<N;i++) E[i][i]=1;
	auto ans=Pow(E,A,m-1);
	
	int sum=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			(sum+=ans[i][j])%=p;
		}
	}
	cout<<6*sum%p<<"\n";
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







