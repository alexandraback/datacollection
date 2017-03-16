#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


typedef long long int64;
const double pi = 3.141592653589;
const double eps = 1e-9;


int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		int n;
		vector<pair<int, int> > xy;
		vector<int> ans;

		scanf("%d", &n);
		xy.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &xy[i].first, &xy[i].second);

		for(auto point : xy) {

			const int x = point.first;
			const int y = point.second;
			vector<double> c1, c;
			int candy = n;

			for(auto xyi : xy) {
				const double dx = xyi.first - x;
				const double dy = xyi.second - y;
				const double dx2 = dx * dx;
				const double d2 = dx * dx + dy * dy;
				if(dx == 0 && dy == 0)
					continue;
				const int dxsign = dx >= 0 ? 1 : -1;
				double t = acos(sqrt(dx2 / d2) * dxsign);
				if(dy < 0) t = 2 * pi - t;
				c1.push_back(t);
			}

			sort(c1.begin(), c1.end());
			c = c1;
			for(auto t : c1)
				c.push_back(t + 2 * pi);

			int nc = c1.size();

			/*printf("%d %d:\n", x, y);
			for(int i = 0; i < nc * 2; ++i)
				printf("    %d: %lf\n", i, c[i]);*/

			for(int s = 0; s < nc; ++s) {

				if(c[s + nc - 1] - c[s] < pi - eps) {
					candy = 0;
					break;
				}

				// lb: <pi, ub: >=pi
				int lb = s, ub = s + nc - 1;

				while(ub - lb > 1) {

					int mid = (lb + ub) / 2;

					if(c[mid] - c[s] < pi - eps)
						lb = mid;
					else
						ub = mid;
				}

				candy = min(candy, lb - s);
			}

			ans.push_back(candy);
		}

		printf("Case #%d:\n", case_num);
		for(auto a : ans)
			printf("%d\n", a);
	}

	return 0;
}
