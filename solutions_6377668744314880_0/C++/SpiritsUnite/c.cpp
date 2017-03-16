#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;
	Point(int a, int b): x(a), y(b) {}
	Point(): x(0), y(0) {}
};

int n;
int a[20];
Point t[20];
int T;

bool ccw(Point x, Point a, Point b)
{
	Point y(a.x - x.x, a.y - x.y);
	Point z(b.x - x.x, b.y - x.y);
	return y.x*z.y - y.y*z.x > 0;
}

bool cmp(int x, int y)
{
	return make_pair(t[x].x, t[x].y) < make_pair(t[y].x, t[y].y);
}
Point cmper;
bool cmp2(int a, int b)
{
	Point y(t[a].x - cmper.x, t[a].y - cmper.y);
	Point z(t[b].x - cmper.x, t[b].y - cmper.y);
	return y.x*z.y - y.y*z.x > 0;
}

void cv(vector<int> &p)
{
	int cut = n - p.size();

	if (p.size() <= 3)
	{
		for (auto i: p)
			a[i] = min(a[i], cut);
		return;
	}

	sort(p.begin(), p.end(), cmp);
	cmper = t[p[0]];
	sort(p.begin()+1, p.end(), cmp2);
	vector<int> s;
	s.push_back(p[0]);
	s.push_back(p[1]);
	s.push_back(p[2]);
	for (int i = 3; i < p.size(); i++)
	{
		if (!ccw(t[*(s.rbegin()+1)], t[*s.rbegin()], t[p[i]]))
			s.pop_back();
		s.push_back(p[i]);
	}
	for (int i = 0; i < s.size(); i++)
	{
		Point x = t[s[i]], y = t[s[(i+1)%s.size()]];
		for (int j = 0; j < p.size(); j++)
		{
			Point z = t[p[j]];
			if(min(x.x, y.x) <= z.x && z.x <= max(x.x, y.x) &&
					min(x.y, y.y) <= z.y && z.y <= max(x.y, y.y) &&
					!ccw(x, y, z) && !ccw(x, z, y))
				a[p[j]] = min(a[p[j]], cut);
		}
	}
}

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		for (int i = 0; i < 20; i++) a[i] = 1<<30;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> t[i].x >> t[i].y;
		for (int i = 1; i < 1<<n; i++)
		{
			vector<int> p;
			for (int j = 0; j < n; j++)
			{
				if (1<<j & i)
					p.push_back(j);
			}
			cv(p);
		}
		cout << "Case #" << C << ":\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << '\n';
	}
	return 0;
}

