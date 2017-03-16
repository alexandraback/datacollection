#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define int long long int

using namespace std;

struct point
{
	int x, y;
	point() : x(0LL), y(0LL) { }
	point(int a, int b): x(a), y(b) { }
};

struct vect
{
    int x, y;
    vect() : x(0LL), y(0LL) { }
    vect(int a, int b) : x(a), y(b) { }
    vect(point a, point b) : x(b.x - a.x), y(b.y - a.y) { }
};

int cross(vect a, vect b)
{
    return a.x * b.y - a.y * b.x;
}

main()
{
	int TESTS;
	cin >> TESTS;
	for (int test = 0; test < TESTS; ++test)
	{
		cout << "Case #" << test + 1 << ": " << endl;
		int n;
		cin >> n;
		vector<point> P(n);
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			P[i] = point(x, y);
		}
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; ++i)
		{
			point A = P[i];
			int answer = 1000LL * 1000;
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
					continue;
				point B = P[j];
				int left = 0, right = 0;
				for (int k = 0; k < n; ++k)
				{
					if (i == k || j == k)
						continue;
					point C = P[k];
					if (cross(vect(A, B), vect(A, C)) > 0)
						left += 1;
					if (cross(vect(A, B), vect(A, C)) < 0)
						right += 1;
				}
				answer = min(answer, min(left, right));
			}
			cout << answer << endl;
		}
	}	
}