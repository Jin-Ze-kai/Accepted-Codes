// Problem: P3758 [TJOI2017] 可乐
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3758
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=2017;
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
	vector A(n+1,vector<int>(n+1));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		A[u][v]=1;
		A[v][u]=1;
	}
	for(int i=0;i<=n;i++) A[i][0]=1;
	vector E(n+1,vector<int>(n+1));
	for(int i=0;i<=n;i++) E[i][i]=A[i][i]=1;
	
	int t;
	cin>>t;
	auto ans=Pow(E,A,t);
	int sum=0;
	for(int i=0;i<=n;i++) (sum+=ans[1][i])%=p;
	cout<<sum<<"\n";
	
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







