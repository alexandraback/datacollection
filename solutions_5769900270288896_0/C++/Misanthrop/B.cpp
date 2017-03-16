#include <iostream>
#include <string>
using namespace std;

int halfperimeter(int n, int m)
{
	if(n == 1 || m == 1) return max(n, m)/2;
	return n + m - 1;
}

int even(int w, int h, int n)
{
	n -= w*h/2;
	int unhappy = 0;
	int corners = 4;
	if((w*h)%2 == 0) corners = 2;
	if(n > 0)
	{
		int d = min(n, corners);
		unhappy += d*2;
		n -= d;
	}
	if(n > 0)
	{
		int border = w + h - 2 - corners;
		int d = min(n, border);
		unhappy += d*3;
		n -= d;
	}
	return unhappy + max(0, n*4);
}

int odd(int w, int h, int n)
{
	if((w*h)%2 == 0) return even(w, h, n);
	n -= w*h/2 + 1;
	int unhappy = 0;
	if(n > 0)
	{
		int border = w + h - 2;
		int d = min(n, border);
		unhappy += d*3;
		n -= d;
	}
	return unhappy + max(0, n*4);
}

int even1(int w, int n)
{
	int unhappy = 0;

	n -= w/2;
	if(n > 0)
	{
		if(w%2 == 0) --n, ++unhappy;
	}
	if(n > 0)
	{
		unhappy += n*2;
	}
	return unhappy;
}

int odd1(int w, int n)
{
	int unhappy = 0;
	if(w%2 == 0) return even1(w, n);
	n -= w/2 + 1;
	if(n > 0)
	{
		if(w%2 == 0) --n, ++unhappy;
	}
	if(n > 0)
	{
		unhappy += n*2;
	}
	return unhappy;
}

int solve()
{
	int w, h, n; cin >> w >> h >> n;
	if(w == 1 || h == 1)
	{
		w = max(w, h);
		return min(even1(w, n), odd1(w, n));
	}
	return min(even(w, h, n), odd(w, h, n));
}

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		cout << solve() << endl;
	}
	return 0;
}

