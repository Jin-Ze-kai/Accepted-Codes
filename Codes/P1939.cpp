// Problem: P1939 矩阵加速（数列）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1939
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

const int p=1e9+7;
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
        if (exp&1) E=A*E;
        A=A*A;
    }
    return E;
}

void solve()
{
	int n;
	cin>>n;
	vector E(3,vector<int>(1,1));
	vector A(3,vector<int>(3));
	A={
		{1,0,1},
		{1,0,0},
		{0,1,0}
	};
	auto ans=Pow(E,A,n-1);
	cout<<ans[2][0]<<"\n";
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







