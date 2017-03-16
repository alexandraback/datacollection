#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point
{
	int x, y;
	Point() {x = y = 0; }
	Point(int _x, int _y) {x = _x, y = _y; }
	Point operator - (const Point &_pt) {return Point(x - _pt.x, y - _pt.y); }
	long long operator * (const Point &_pt) {return (long long)x * _pt.y - (long long)y * _pt.x; }
};
int t, n;
Point pt[3000];
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
		for(int i = 0; i < n; i++)
		{
			int ans = 2147483647;
			for(int j = 0; j < n; j++)
			{
				if(i == j)
					continue;
				int cntp = 0, cntn = 0;
				Point vec = pt[j] - pt[i];
				for(int k = 0; k < n; k++)
				{
					long long tmp = (pt[k] - pt[i]) * vec;
					if(tmp > 0)
						cntp++;
					else if(tmp < 0)
						cntn++;
				}
				ans = min(ans, min(cntp, cntn));
			}
			fprintf(fout, "%d\n", ans < 2147483647 ? ans : 0);
		}
	}
	fclose(fin), fclose(fout);
	return 0;
}
