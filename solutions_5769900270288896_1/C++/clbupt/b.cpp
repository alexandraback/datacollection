#include <iostream>

using namespace std;

int rent(int r, int c, int n)
{
	if (r > c)
	{
		return rent(c, r, n);
	}
	int area = r * c;
	if (n <= (area + 1) / 2)
	{
		return 0;
	}
	if (r == 1)
	{
		if (c % 2 == 0)
		{
			return (n - (c / 2)) * 2 - 1;
		}
		else
		{
			return min((n-(c/2+1))*2, (n-c/2)*2-2);
		}
	}
	if (area % 2 == 1)
	{
		int t = n - (area+1)/2;
		int e = r + c - 2;
		int a = 0;
		if (t <= e)
		{
			a = t * 3;
		}
		else
		{
			a = e * 3 + (t - e) * 4;
		}
		t = n - area / 2;
		int b = 0;
		if (t <= 4)
		{
			b = 2 * t;
		}
		else if (t > 4 && t <= (r+c-2))
		{
			b = 3 * t - 4;
		}
		else
		{
			b = (r+c-2)*3-4+(t-(r+c-2))*4;
		}
		return min(a, b);
	}
	int e = (r+c-2);
	int t = n - (area/2);
	if (t <= 2)
	{
		return 2 * t;
	}
	else if (t <= e)
	{
		return t*3-2;
	}
	else
	{
		return e*3-2+(t-e)*4;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int cc = 1; cc <= t; ++cc)
	{
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << cc << ": " << rent(r, c, n) << endl;
	}
	return 0;
}