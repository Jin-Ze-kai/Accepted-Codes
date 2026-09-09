#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
struct Sieve {
    vector<int> spf,primes;

    Sieve(int n=1e6) : spf(n+1) {
        for (int i=2;i<=n;i++) {
            if (!spf[i]) primes.push_back(spf[i]=i);
            for (int p : primes) {
                if (i*p > n) break;
                spf[i*p]=p;
                if (i%p == 0) break;
            }
        }
    }

    // [质因子,指数] O(logn)
	vector<pair<int,int>> fact(int v) {
	    vector<pair<int,int>> res;
	    for (int p : primes) {
	        if (p*p > v or v < spf.size()) break;
	        if (v%p == 0) {
	            int c=0;
	            while (v%p == 0) v/=p,c++;
	            res.emplace_back(p,c);
	        }
	    }
	    while (v > 1 and v < spf.size()) {
	        int p=spf[v];
	        int c=0;
	        while (v%p == 0) v/=p,c++;
	        res.emplace_back(p,c);
	    }
	    if (v > 1) res.emplace_back(v,1);
	    return res;
	}

	//所有因数,O(O(fact)+因数个数)
    vector<int> divs(int v) {
        vector<int> res={1};
        for (auto [p,c] : fact(v)) {
            int sz=res.size();
            int x=p;
            for (int i=0;i<c;i++,x*=p)
                for (int j=0;j<sz;j++) res.push_back(res[j]*x);
        }
        return res;
    }

	//可筛1e12
    bool isPrime(int v) {
        if (v < spf.size()) return v > 1 and spf[v] == v;
        for (int p : primes) {
            if (p*p > v) break;
            if (v%p == 0) return 0;
        }
        return v > 1;
    }
};

Sieve sieve;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

void solve()
{
	int op,n;
	cin>>op>>n;
	int ans=0;
	if (n <= 10) {
		for(int b=1;b<=n;b++) {
			auto vec=sieve.divs(b*b);
			for(auto a : vec) {
				int c=b*b/a;
				for(auto e : vec) {
					int g=b*b/e;
					if (a*b%e) continue;
					int d=a*b/e;
					if (op == 1) {
						unordered_set<int> st;
						// cout<<c<<" "<<b<<" "<<a<<"\n";
						// cout<<d<<"\n";
						// cout<<e<<" "<<b<<" "<<g<<"\n";
						// cout<<endl;
						st.insert(a);
						st.insert(b);
						st.insert(c);
						st.insert(d);
						st.insert(e);
						st.insert(g);
						// cout<<st.size()<<"\n";
						if (st.size() == 6) ans+=d;
					}
					else {
						ans+=d;
					}
				}
			}
		}
	}
	cout<<ans;
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







