#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

struct Vector
{
	int id;
	int64_t x, y;

	int64_t cross(Vector v2) const
	{
		return x * v2.y - y * v2.x;
	}

	Vector operator-(Vector v2) const
	{
		Vector out;
		out.x = x - v2.x;
		out.y = y - v2.y;
		return out;
	}
};

bool xsort(Vector a, Vector b)
{
	if(a.x < b.x) return true;
	if(a.x > b.x) return false;

	return a.y < b.y;
}

bool xsortrev(Vector a, Vector b)
{
	if(a.x < b.x) return true;
	if(a.x > b.x) return false;

	return a.y > b.y;
}

void solve()
{
	int n;
	cin >> n;

	vector<Vector> points(n);
	for(int i = 0; i < n; i++)
	{
		points[i].id = i;
		cin >> points[i].x >> points[i].y;
	}

	sort(points.begin(), points.end(), xsort);
	vector<Vector> pointsb = points;
	sort(pointsb.begin(), pointsb.end(), xsortrev);

	vector<int> ans(n, INT_MAX);

	for(int j = 0; j < n; j++)
	{
		vector<int> upper;
		vector<int> lower;

		int upperNeeded = 0;
		int lowerNeeded = 0;

		upper.push_back(0);
		upper.push_back(1);
		lower.push_back(0);
		lower.push_back(1);

		for(int i = 2; i < n; i++)
		{
			bool removed = false;

			while(upper.size() >= 2)
			{
				Vector start = points[upper[upper.size() - 2]];
				Vector endA = points[upper[upper.size() - 1]];
				Vector endB = points[i];

				Vector a = endA - start;
				Vector b = endB - start;

				if(a.cross(b) > 0)
				{
					if(upper[upper.size() - 1] == j)
					{
						upperNeeded++;
						removed = true;
						break;
					}
					else
					{
						upper.pop_back();
					}
				}
				else
				{
					break;
				}
			}

			if(!removed)
			{
				upper.push_back(i);
			}
		}

		for(int i = 2; i < n; i++)
		{
			bool removed = false;

			while(lower.size() >= 2)
			{
				Vector start = pointsb[lower[lower.size() - 2]];
				Vector endA = pointsb[lower[lower.size() - 1]];
				Vector endB = pointsb[i];

				Vector a = endA - start;
				Vector b = endB - start;

				if(a.cross(b) < 0)
				{
					if(lower[lower.size() - 1] == j)
					{
						lowerNeeded++;
						removed = true;
						break;
					}
					else
					{
						lower.pop_back();
					}
				}
				else
				{
					break;
				}
			}

			if(!removed)
			{
				lower.push_back(i);
			}
		}

		int remF = 0;
		int remL = 0;

		for(int i = 0; i < j; i++)
		{
			if(points[i].x < points[j].x)
			{
				remF++;
			}
		}

		for(int i = n - 1; i > j; i--)
		{
			if(points[i].x > points[j].x)
			{
				remL++;
			}
		}

		ans[points[j].id] = min(min(ans[points[j].id], upperNeeded), min(remF, remL));
		ans[pointsb[j].id] = min(ans[pointsb[j].id], lowerNeeded);
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cout << "Case #" << i << ": " << endl;
		solve();
	}

	return 0;
}