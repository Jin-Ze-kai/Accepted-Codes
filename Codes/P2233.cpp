// Problem: P2233 [HNOI2002] 公交车路线
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2233
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

const int p=1000;
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
	int n;
	cin>>n;
	vector A(8,vector<int>(8));
	A={
		{0,1,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0},
		{0,1,0,1,0,0,0,0},
		{0,0,1,0,1,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,1,0},
		{0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,1,0}
	};
	vector E(8,vector<int>(8));
	for(int i=0;i<8;i++) E[i][i]=1;
	auto ans=Pow(E,A,n);
	cout<<ans[0][4];
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







