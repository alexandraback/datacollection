#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct point
{
	int x,y;
	int i;
	double angle;
	point():x(0),y(0),i(0){}
	point(int x, int y, int i):x(x),y(y),i(i){}
	bool operator < (const point &other) const {
		return angle < other.angle;
	}
};

const double PI = atan(1.0)*4;
const double eps = 5e-14;

bool angleCheck(double r, double l)
{
	double ul = l + PI;
	if (l <= r+eps && r <= ul+eps) return true;
	if (l - 2*PI <= r+eps && r <= ul-2*PI+eps ) return true;
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		printf("Case #%d:\n", testcase);
		int n;
		vector<point> dat;
		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			dat.emplace_back(a,b,i);
		}
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			vector<point> np;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				point P = dat[j];
				P.x -= dat[i].x;
				P.y -= dat[i].y;
				P.angle = atan2(P.y, P.x);
				np.push_back(P);
			}
			sort(np.begin(),np.end());
			int cur = n-1;
			int r = 0;
			for (int l = 0; l < np.size(); l++) {
				while (r < l + np.size() && angleCheck(np[r%np.size()].angle, np[l].angle)) {
					r++;
				}
				cur = min(cur, n-1-(r-l));
			}
			ans[dat[i].i] = cur;
		}
		for (int i = 0; i < n; i++) {
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}