// Problem: P3216 [HNOI2011] 数学作业
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3216
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int p;
vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
    int n=A.size();
    int l=A[0].size();
    int m=B[0].size();
    vector C(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int k=0;k<l;k++) {
            if (A[i][k] == 0) continue;
            for (int j=0;j<m;j++) {
                (C[i][j]+=A[i][k]*B[k][j])%=p;
            }
        }
    }
    return C;
}

vector<vector<int>> Pow(vector<vector<int>> A,int exp) {
	int n=A.size();
	vector E(n,vector<int>(n));
	for(int i=0;i<n;i++) E[i][i]=1;
	for(;exp;exp>>=1) {
		if (exp&1) E=E*A;
		A=A*A;
	}
	return E;
}

void solve()
{
	int n;
	cin>>n>>p;
	vector A0(3,vector<int>(1));
	A0={{0},{0},{1}};
	int b=log10(n);
	vector A(3,vector<int>(3));
	A={
		{1,1,1},
		{0,1,1},
		{0,0,1}
	};
	int cur=0;
	for(int k=0;k<b;k++) {
		(A[0][0]*=10)%=p;
		A0=Pow(A,(cur+1)*10-1-cur)*A0;
		cur=(cur+1)*10-1;
	}
	A[0][0]*=10;
	A0=Pow(A,n-cur)*A0;
	cout<<A0[0][0];
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







