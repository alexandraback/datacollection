#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int result(int corners, int sides, int inside, int free)
{
	int res = 0;
	res += min(free, inside) * 4;
	free -= inside;
	res += min(max(free, 0), sides) * 3;
	free -= sides;
	res += min(max(free, 0), corners) * 2;
	return res;
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int r, c, n;
		cin >> r >> c >> n;
		if (r < c)
			swap(r, c);
		int area = r * c;
		int free = area - n;
		if (c == 1)
		{
			if (n <= area / 2)
			{
				cout << 0 << endl;
				continue;
			}
			else
			{
				cout << max(0, area - 1 - 2 * free) << endl;
				continue;
			}
		}
		int leadingTotalNumber = (area + 1) / 2;
		int secondTotalNumber = area - leadingTotalNumber;
		int leadingCorners = ((r * c) % 2 == 1) ? 4 : 2;
		int secondCorners = 4 - leadingCorners;
		int leadingSides;
		int secondSides;
		if (area % 2 == 1)
		{
			 leadingSides = ((r + 1) / 2) * 2 + ((c + 1) / 2) * 2 - 2 * leadingCorners;
			 secondSides = r * 2 + c * 2 - leadingSides - 8;
		} else {
			leadingSides = (2 * r + 2 * c - 8) / 2;
			secondSides = leadingSides;
		}
		int leadingInside = leadingTotalNumber - leadingCorners  - leadingSides;
		int secondInside = secondTotalNumber - secondCorners  - secondSides;
		//printf("\n\n r: %d  c: %d\n", r, c);
		//printf("Leading Total: %d corners: %d sides: %d inside: %d\n", leadingTotalNumber, leadingCorners, leadingSides, leadingInside);
		//printf("Second Total: %d corners: %d sides: %d inside: %d\n", secondTotalNumber, secondCorners, secondSides, secondInside);
		int innerWalls = r * (c - 1) + c * (r - 1);
		//printf("Inner walls: %d\n", innerWalls);

		int withLeading = innerWalls - result(leadingCorners, leadingSides, leadingInside, free);
		int withSecond= innerWalls - result(secondCorners, secondSides, secondInside, free);
		cout << min(withLeading, withSecond) << endl;
	}
	return 0;
}
