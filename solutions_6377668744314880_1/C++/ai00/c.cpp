#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
const double PI = acos(-1);
#define sqr(x)  ((x)*(x))
#define eps  (1e-6)
#define abs(x) ((x)>=0?(x):(-(x)))
#define zero(x) (abs(x)<eps)
struct NODE{
	long long x, y;
	double c;
	NODE(int X, int Y){
		x = X;
		y = Y;
		/*
		x -= 5;
		y -= 5;
		c = acos(x / sqrt(sqr(x) + sqr(y)));
		if (y < 0) c = 2 * PI - c;
		cout<<x<<' '<<y<<' '<<c<<endl;
		*/
	}
	NODE(NODE a, NODE b){
		x = a.x - b.x;
		y = a.y - b.y;
		//cout<<x<<' '<<y<<endl;
		c = acos(x / sqrt(sqr(x) + sqr(y)));
		//cout<<sqr(x) + sqr(y)<<endl;
		//cout<<c<<endl;
		//cout<<c<<endl;
		if (y < 0) c = 2 * PI - c;
	}
	bool operator < (const NODE &a) const{
		//if (zero(c - a.c))
		return c < a.c;
	}
	bool left(const NODE &a) const{
		//cout<<a.c - c<<endl;
		if (a.c - c > PI + 1) return false;
		long long p = x * a.y - y * a.x;
		//cout<<"xx "<<p<<endl;
		//cout<<x<<' '<<y<<' '<<a.x<<' '<<a.y<<endl;
		//cout<<p<<' '<<c<<' '<<a.c<<' '<<zero(c - a.c)<<' '<<abs(c - a.c)<<' '<<eps<<' '<<(abs(c - a.c)<eps)<<endl;
		if (p > 0) return true;
		if (p < 0) return false;
		return zero(c - a.c);
	}
	NODE(const NODE &a, double add){
		x = a.x;
		y = a.y;
		c = a.c + add;
	}
};
vector<NODE> v;
int gao(int i){
	vector<NODE> line;
	for (int j = 0; j < n; ++j){
		if (j == i)
			continue;
		line.push_back(NODE(v[j], v[i]));
	}
	sort(line.begin(), line.end());
	int n = line.size();
	for (int i = 0; i < n; ++i)
		line.push_back(NODE(line[i], 2 * PI));
	//for (int i = 0; i < line.size(); ++i)
	//	cout<<line[i].x<<' '<<line[i].y<<' '<<line[i].c<<endl;
	int j = 0;
	int ans = n;
	for (int i = 0; i < n; ++i){
		while (j < line.size()&&(line[i].left(line[j])))  ++j;
		//cout<<"adf"<<i<<' '<<j<<endl;
		ans = min(ans, j - i - 1);
	}
	return ans;
}
int main(){
	int t = 0, tt;
	for (scanf("%d ", &tt); t < tt; ++t){
		scanf("%d ", &n);
		v.clear();
		for (int i = 0; i < n; ++i){
			int x, y;
			scanf("%d %d ", &x, &y);
			v.push_back(NODE(x, y));
		}
		printf("Case #%d:\n", t + 1);
		for (int i = 0; i < n; ++i){
		//	gao(i);
			printf("%d\n", gao(i));
		
		}
		//printf("%d\n", gao(4));
	}
}