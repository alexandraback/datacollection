#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;

struct point
{
	int pos;
	long long x;
	long long y;
};
vector <point> a, b;

bool used[32];

int res[32];
long long minx, maxx;

bool sortUpper(point p1, point p2)
{
	if(p1.x == p2.x)
	{
		if(p1.x == minx)
		{
			return p1.y < p2.y;
		}
		return p1.y > p2.y;
	}
	return p1.x < p2.x;
}

bool sortLower(point p1, point p2)
{
	
	if(p1.x == p2.x)
	{
		if(p1.x == minx)
		{
			return p1.y < p2.y;
		}
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}

long long ddw(point p0, point p1, point p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

void convexHull(int mask)
{

	vector <point> temp;
	int i;
	for(i = 0; i < a.size(); i ++)
	{
		if((mask & (1 << a[i].pos)) == 0)
			continue;

		while(temp.size() >= 2 && ddw(temp[temp.size()-2], temp[temp.size() -1], a[i]) > 0)
		{
			temp.pop_back();
		}

		temp.push_back(a[i]);
	}
	
	for(i = 0; i < temp.size(); i ++)
	{
		used[temp[i].pos] = true;
		//cout << temp[i].pos << " ";
		
	}
	//cout << endl;
	temp.clear();

	for(i = 0; i < b.size(); i ++)
	{
		if((mask & (1 << b[i].pos)) == 0)
			continue;

		while(temp.size() >= 2 && ddw(temp[temp.size()-2], temp[temp.size() -1], b[i]) < 0)
		{
			temp.pop_back();
		}

		temp.push_back(b[i]);
	}

	for(i = 0; i < temp.size(); i ++)
	{
		used[temp[i].pos] = true;
		//cout << temp[i].pos << " ";

	}	//cout << endl;

	int k = n - __builtin_popcount(mask);

	for(i = 0; i < n; i ++)
	{
		if(used[i])
		{
			res[i] = min(res[i], k);
		}
	}
}

void solve()
{
	scanf ("%d", &n);
	a.clear(); b.clear();
	int i;
	for(i =0; i <n ; i++)
	{
		point temp;
		scanf ("%lld%lld", &temp.x, &temp.y);
		temp.pos = i;
		a.push_back(temp);
		b.push_back(temp);
	}

	minx = a[0].x, maxx = a[0].x;
	for(i = 0; i < n; i ++)
	{
		minx = min( minx, a[i].x);
		maxx = max( maxx, a[i].x);
			
	}
	

	sort(a.begin(), a.end(), sortUpper);
	sort(b.begin(), b.end(), sortLower);
	

	for(i =0 ; i < n; i++)
		res[i] = n;

	for(int mask=0; mask < (1<<n); mask ++)
	{
		//int mask = 511;
		memset(used, 0, sizeof(used));
		convexHull(mask);
	}

	for(i = 0; i < n; i ++)
	{
		printf ("%d\n", res[i]);
	}
}
int main ()
{
	int t;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d:\n", i);solve();
	}
	return 0;
}