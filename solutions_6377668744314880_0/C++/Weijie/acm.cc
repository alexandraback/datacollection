#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>

using namespace std;

#define INF 0x3f3f3f3f

#define PI 3.1415926535897932384626433832795

bool zero(double x){
	if(fabs(x) < 1e-6)
		return true;
	return false;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){x = _x;y = _y;}
	bool operator<(Point t) const{
		if(x == t.x)
			return y < t.y;
		return x < t.x;
	}
	bool operator==(Point t) const{
		if(zero(x - t.x) && zero(y - t.y))
			return true;
		return false;
	}
};

vector<Point> a;


bool isRight(Point a,Point b,Point c){
	Point l,r;
	l.x = a.x - b.x;
	l.y = a.y - b.y;
	r.x = c.x - b.x;
	r.y = c.y - b.y;
	return l.x * r.y - l.y * r.x >= 0;
}

double dist(Point a,Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));    
}

bool on_convex(vector<Point> a,Point p){
	int n = a.size();
	if(a.size() <= 3)
		return true;
	vector<Point> upper;
	vector<Point> lower;
	sort(a.begin(),a.end());
	upper.push_back(a[0]);
	upper.push_back(a[1]);
	for(int i = 2;i < a.size();++i){
		upper.push_back(a[i]);
		while(upper.size() > 2 && 
			  !isRight(upper[upper.size() - 3],
				       upper[upper.size() - 2],
					   upper[upper.size() - 1]))
			upper.erase(upper.begin() + upper.size() - 2);
	}
	lower.push_back(a[n - 1]);
	lower.push_back(a[n - 2]);
	for(int i = n - 3;i >= 0;--i){
		lower.push_back(a[i]);
		while(lower.size() > 2 && 
			  !isRight(lower[lower.size() - 3],
				       lower[lower.size() - 2],
					   lower[lower.size() - 1]))
			lower.erase(lower.begin() + lower.size() - 2);
	}
	for(int i = 0;i < lower.size();++i)
		upper.push_back(lower[i]);
	double ans = 0;
	
	/*printf("p %f %f\n",p.x,p.y);
	for(int i = 0;i < a.size();++i)
		printf("(%f,%f) ",a[i].x,a[i].y);
	puts("");
	printf("up %lu\n",upper.size());
	for(int i = 0;i < upper.size();++i)
		printf("(%f,%f) ",upper[i].x,upper[i].y);
	printf("\nlow %lu\n",lower.size());
	for(int i = 0;i < lower.size();++i)
		printf("(%f,%f) ",lower[i].x,lower[i].y);
	puts("\n");*/
	
	for(int i = 0;i < upper.size();++i){
		if(upper[i] == p)
			return true;
//		ans += dist(upper[i],upper[(i + 1) % upper.size()]);
        //printf("%f %f\n",upper[i].x,upper[i].y);
    }
//	ans += PI * l * 2;
//	printf("%.0f\n",ans);
//	return 0;
	return false;
}

int ans[1010];

int main(){
	int T;
	scanf("%d",&T);
	for(int cas = 1;cas <= T;++cas){
		memset(ans,0x3f3f3f3f,sizeof(ans));
		int n;
		scanf("%d",&n);
		vector<Point> a;
		for(int i = 0;i < n;++i){
			Point p;
			scanf("%lf%lf",&p.x,&p.y);
			a.push_back(p);
		}
		for(int i = 0;i < n;++i){
			for(int x = 0;x < (1 << n);++x){
				if(!(x & (1 << i)))
					continue;
				vector<Point> now;
				int cnt = 0;
				for(int j = 0;j < n;++j){
					if(x & (1 << j))
						now.push_back(a[j]);
					else
						++cnt;
				}
				if(on_convex(now,a[i])){
					ans[i] = min(ans[i],cnt);
				//	printf("yes\n");
				}//else
				//	printf("no\n");
			}
		}
		printf("Case #%d:\n",cas);
		for(int i = 0;i < n;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}

