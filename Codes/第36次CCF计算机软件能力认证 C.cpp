#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int n,N,q;
struct Node {
	deque<int> dq;//记录先后
	set<int> st1;//记录是否存在
	set<int> st2;//记录是否被写过
	map<int,int> cnt;
};

void solve()
{
	cin>>n>>N>>q;
	vector<Node> vec(N);
	while (q--) {
		int opt,a;
		cin>>opt>>a;
		if (opt == 0) {
			int id=(a/n)%N;
			if (vec[id].st1.find(a) != vec[id].st1.end()) {
				vec[id].cnt[a]++;
				// erase(vec[id].dq,a);
				vec[id].dq.push_front(a);
			}
			else {
				if (vec[id].st1.size() < n) {
					cout<<"0 "<<a<<"\n";
					vec[id].dq.push_front(a);
					vec[id].st1.insert(a);
				}
				else {
					int x;
					while (1) {
						x=vec[id].dq.back();
						if (vec[id].cnt[x] > 0) {
							vec[id].cnt[x]--;
							vec[id].dq.pop_back();
						}
						else break;
					}
					if (vec[id].st2.find(x) != vec[id].st2.end()) {
						cout<<"1 "<<x<<"\n";
						vec[id].dq.pop_back();
						vec[id].st1.erase(x);
						vec[id].st2.erase(x);
						cout<<"0 "<<a<<"\n";
						vec[id].dq.push_front(a);
						vec[id].st1.insert(a);
					}
					else {
						vec[id].dq.pop_back();
						vec[id].st1.erase(x);
						cout<<"0 "<<a<<"\n";
						vec[id].dq.push_front(a);
						vec[id].st1.insert(a);
					}
				}
			}
		}
		else {
			int id=(a/n)%N;
			if (vec[id].st1.find(a) != vec[id].st1.end()) {
				vec[id].cnt[a]++;
				// erase(vec[id].dq,a);
				vec[id].dq.push_front(a);
				vec[id].st2.insert(a);
			}
			else {
				if (vec[id].st1.size() < n) {
					cout<<"0 "<<a<<"\n";
					vec[id].dq.push_front(a);
					vec[id].st1.insert(a);
					vec[id].st2.insert(a);
				}
				else {
					int x;
					while (1) {
						x=vec[id].dq.back();
						if (vec[id].cnt[x] > 0) {
							vec[id].cnt[x]--;
							vec[id].dq.pop_back();
						}
						else break;
					}
					if (vec[id].st2.find(x) != vec[id].st2.end()) { 
						cout<<"1 "<<x<<"\n";
						vec[id].dq.pop_back();
						vec[id].st1.erase(x);
						vec[id].st2.erase(x);
						cout<<"0 "<<a<<"\n";
						vec[id].dq.push_front(a);
						vec[id].st1.insert(a);
						vec[id].st2.insert(a);
					}
					else {
						vec[id].dq.pop_back();
						vec[id].st1.erase(x);
						cout<<"0 "<<a<<"\n";
						vec[id].dq.push_front(a);
						vec[id].st1.insert(a);
						vec[id].st2.insert(a);
					}
				}
			}
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







