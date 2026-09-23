// Problem: K. Kingdom Rush 5: Alliance
// Contest: Codeforces - The 8th Guangxi Collegiate Programming Contest
// URL: https://codeforces.com/gym/106707/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double eps = 1e-9;

int sign(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }
    
    bool operator==(const Point& b) const { 
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0; 
    }
    
    // 按 x 坐标升序排列，x 相同则按 y 坐标升序排列
    bool operator<(const Point& b) const {
        int c = cmp(x, b.x);
        if (c != 0) return c == -1; 
        return cmp(y, b.y) == -1;   
    }
};
typedef Point Vector;

struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(0, 0), double r = 0) : c(c), r(r) {}
    
    // 通过圆心角求圆上坐标 (逆时针方向，a 为弧度)
    Point point(double a) const {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
};

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}


bool get(Point a, Point b, Circle C, double& t1, double& t2) {
    Vector D = b - a;
    Vector F = a - C.c;
    double a_ = dot(D, D);
    double b_ = 2 * dot(F, D);
    double c_ = dot(F, F) - C.r * C.r;
    
    // 如果 A 和 B 几乎重合（线段退化为点）
    if (sign(a_) == 0) {
        if (sign(c_) <= 0) { 
            t1 = 0.0; t2 = 1.0; 
            return true; 
        }
        return false;
    }
    
    i128 delta = (i128)b_ * (i128)b_ - 4 * (i128)a_ * (i128)c_;
    if (delta < 0) return false; 
    
    double sqrt_delta = sqrt((double)delta);
    t1 = (-b_ - sqrt_delta) / (2 * a_);
    t2 = (-b_ + sqrt_delta) / (2 * a_);
    
    // 截取参数域 [0, 1] 的交集
    t1 = max((double)0.0, t1);
    t2 = min((double)1.0, t2);
    if (cmp(t1, t2) > 0) return false; 
    
    return true;
}

void solve()
{
	Circle c1,c2;
	cin>>c1.c.x>>c1.c.y>>c1.r;
	cin>>c2.c.x>>c2.c.y>>c2.r;
	Point p1,p2;
	cin>>p1.x>>p1.y>>p2.x>>p2.y;
	vector<array<double,2>> vec;
	double t1,t2;
	if (get(p1,p2,c1,t1,t2)) {
		vec.push_back({t1,t2});
	}
	if (get(p1,p2,c2,t1,t2)) {
		vec.push_back({t1,t2});
	}
	
	double t=0;
	if (!vec.empty()) {
		sort(vec.begin(),vec.end());
		double st=vec[0][0];
		double ed=vec[0][1];
		for(int i=1;i<vec.size();i++) {
			if (vec[i][0] <= ed) ed=max(ed,vec[i][1]);
			else {
				t+=ed-st;
				st=vec[i][0];
				ed=vec[i][1];
			}
		}
		t+=ed-st;
	}
	double ans=hypot(p1.x-p2.x,p1.y-p2.y);
	cout<<fixed<<setprecision(10)<<t*ans;
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







