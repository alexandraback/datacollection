#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct point{
	long long x, y;
	int pos;
	point(const long long &a = 0, const long long &b = 0):x(a),y(b){}
	point operator+(const point &another) const{
		return point(x+another.x,y+another.y);
	}
	point operator-(const point &another) const{
		return point(x-another.x,y-another.y);
	}
	point operator*(const double &r) const{
		return point(r*x,r*y);
	}
	long long operator % (const point &another) const{
		return x * another.y - y * another.x;
	}
	bool operator==(const point &another) const{
		return x==another.x&&y==another.y;
	}
	bool operator!=(const point &another) const{
		return !(*this==another);
	}
};

bool cmp(point a, point b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int side(point a, point b, point c){
	long long tmp = (a-b) % (c-b);
	if(tmp > 0) return 1;
	if(tmp < 0) return -1;
	return 0;
}

vector<point> convex_hull(vector<point> p){
	sort(p.begin(), p.end(), cmp);
	if(p.size() <= 2){
		p.push_back(p.front());
		return p;
	}
	vector<point> ch;
	int n = 0;
	for(int i = 0 ; i < p.size() ; i++){
		while(n >= 2 && (ch[n-2] - ch[n-1]) % (p[i] - ch[n-1]) < 0){
			ch.pop_back(), n--;	
		}
		ch.push_back(p[i]);
		ch.back().pos = i;
		n++;
	}
	int m = n;
	for(int i = (int)p.size() - 2 ; i >= 0 ; i--){
		while(n > m && (ch[n-2] - ch[n-1]) % (p[i] - ch[n-1]) < 0){
			ch.pop_back();
			n--;
		}
		ch.push_back(p[i]);
		ch.back().pos = i;
		n++;
	}
	return ch;
}

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		int n;
		scanf("%d", &n);
		long long x, y;
		vector<point> v;
		for(int i = 0 ; i < n ; i++){
			scanf("%I64d %I64d", &x, &y);
			v.push_back(point(x,y));
		}
		vector<point> hull = convex_hull(v);
		int siz = (int)hull.size();
		printf("Case #%d:\n", casen);
		for(int i = 0 ; i < n ; i++){
			bool get = false;
			for(int j = 0 ; !get && j < siz ; j++){
				get |= hull[j] == v[i];
			}
			if(get){
				puts("0");
				continue;
			}
			int ans = n;
			for(int p = 0 ; p < siz-1 ; p++){
				for(int q = p+1 ; q < siz-1 ; q++){
					//hull[p], hull[q]
					int crs = side(hull[p], hull[q], v[i]);
					if(crs == 0){
						int s1 = 0, s2 = 0;
						for(int j = 0 ; j < n ; j++) if(v[j]!=v[i]&&v[j]!=hull[p]&&v[j]!=hull[q]){
							int tmp = side(hull[p], hull[q], v[j]);
							if(tmp<0)s1++;
							else if(tmp>0)s2++;
						}
						ans = min(ans, min(s1,s2));
					}else{
						int sum = 0;
						if(crs < 0){
							for(int j = 0 ; j < n ; j++) if(v[j]!=v[i]&&v[j]!=hull[p]&&v[j]!=hull[q]){
								if(side(hull[p], v[i], v[j]) < 0 || side(v[i], hull[q], v[j]) < 0)
									sum++;
							}
						}else if(crs > 0){
							for(int j = 0 ; j < n ; j++) if(v[j]!=v[i]&&v[j]!=hull[p]&&v[j]!=hull[q]){
								if(side(hull[p], v[i], v[j]) > 0 || side(v[i], hull[q], v[j]) > 0)
									sum++;
							}
						}
						ans = min(ans, sum);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
