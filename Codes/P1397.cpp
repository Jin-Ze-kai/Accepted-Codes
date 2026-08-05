// Problem: P1397 [NOI2013] 矩阵游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1397
// Memory Limit: 256 MB
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

vector<vector<int>> Pow10(vector<vector<int>> A,string exp) {
    int n=A.size();
    vector<vector<int>> E(n,vector<int>(n,0));
    for (int i=0;i<n;i++) E[i][i]=1;
    vector<vector<vector<int>>> tmp(10);
    tmp[0]=E;
    for (int i=1;i<=9;i++) tmp[i]=tmp[i-1]*A;
    for (char c : exp) {
    	E=Pow(E,10)*tmp[c-'0'];
    }
    return E;
}


void solve()
{
	int a,b,c,d;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=s1.size()-1;i>=0;i--) {
		if (s1[i] != '0') {
			s1[i]--;
			break;
		}
		s1[i]='9';
	}
	for(int i=s2.size()-1;i>=0;i--) {
		if (s2[i] != '0') {
			s2[i]--;
			break;
		}
		s2[i]='9';
	}
	cin>>a>>b>>c>>d;
	vector A(2,vector<int>(2));
	A={
		{a,b},
		{0,1}
	};
	vector A0(2,vector<int>(1,1));
	auto tmp=Pow10(A,s2);
	A0[0][0]=(tmp*A0)[0][0];
	vector B(2,vector<int>(2));
	B={
		{c,d},
		{0,1}
	};
	auto C=tmp*B;
	auto ans=Pow10(C,s1)*A0;
	cout<<ans[0][0];
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







