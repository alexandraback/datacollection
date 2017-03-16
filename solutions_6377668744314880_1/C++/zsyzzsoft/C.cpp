#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
	int x, y;
	bool rev;
	Point() {x = y = 0, rev = false; }
	Point(int _x, int _y) {x = _x, y = _y, rev = false; }
	Point operator - () const {return Point(-x, -y); }
	Point operator - (const Point &_pt) const {return Point(x - _pt.x, y - _pt.y); }
	long long operator * (const Point &_pt) const {return (long long)x * _pt.y - (long long)y * _pt.x; }
};
int t, n;
Point pt[3000], sub[3000];
bool _stdcall Cmp(const Point &_a, const Point &_b)
{
	return _a * _b < 0;
}
int main()
{
	FILE *fin = fopen("C.in", "r"), *fout = fopen("C.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d", &n);
		for(int i = 0; i < n; i++)
			fscanf(fin, "%d%d", &pt[i].x, &pt[i].y);
		fprintf(fout, "Case #%d:\n", t_id);
		if(n == 1)
		{
			fprintf(fout, "0\n");
			continue;
		}
		for(int i = 0; i < n; i++)
		{
			int ans = 2147483647, sum = 0, len = 0;
			for(int j = 0; j < n; j++)
			{
				if(j == i)
					continue;
				Point tmp = pt[j] - pt[i];
				if(tmp.x < 0 || tmp.x == 0 && tmp.y < 0)
					tmp = -tmp, tmp.rev = true;
				sub[len++] = tmp;
			}
			sort(sub, sub + len, Cmp);
			for(int j = 0; j < n; j++)
				sum += sub[0] * (pt[j] - pt[i]) > 0;
			for(int j = 0, r = 1; j < len; j = r++)
			{
				while(r < len && sub[j] * sub[r] == 0)
					r++;
				if(j)
				{
					for(int k = j; k < r; k++)
						sum += sub[k].rev ? -1 : 0;
				}
				ans = min(ans, min(sum, n - sum - (r - j)));
				for(int k = j; k < r; k++)
					sum += sub[k].rev ? 0 : 1;
			}
			fprintf(fout, "%d\n", ans);
		}
	}
	fclose(fin), fclose(fout);
	return 0;
}
