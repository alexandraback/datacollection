/* 2015.4.18 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

long long gcd(long long a, long long b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a < b)
		return gcd(b, a);
	else if (b == 0)
		return a;
	else return gcd(b, a % b);
}

class MyNumber
{
public:
	long long x;
	long long y;
	int sa;

	int plus, minus;

	MyNumber(long long x_, long long y_)
		: x(x_), y(y_), plus(0), minus(0)
	{
		long long g = gcd(x, y);
		x /= g;
		y /= g;

		if (x > 0 && y >= 0)
			sa = 1;
		else if (x <= 0 && y > 0)
			sa = 2;
		else if (x < 0 && y <= 0)
			sa = 3;
		else if (x >= 0 && y < 0)
			sa = 4;
		else
			printf("ERROR");
	}
};

int coord[5000][2];

bool compare(MyNumber* m1, MyNumber* m2)
{
	if (m1->sa == m2->sa)
	{
		return m1->y * m2->x < m2->y * m1->x;
	}
	else
	{
		return m1->sa < m2->sa;
	}
}

std::map<std::pair<int, int>, MyNumber*> map;
std::vector<MyNumber*> set;

MyNumber* get(int x, int y)
{
	int g = gcd(x, y);
	x /= g;
	y /= g;
	MyNumber* mn = map[std::make_pair(x, y)];
	if (mn == nullptr)
	{
		mn = map[std::make_pair(x, y)] = new MyNumber(x, y);
		set.push_back(mn);
	}
	return mn;
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		fprintf(fout, "Case #%d:\n", c_n);
		printf("Case #%d:\n", c_n);

		int N;
		fscanf(fin, "%d", &N);

		double tot = 0;
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			fscanf(fin, "%d%d", coord[i], coord[i] + 1);
		}

		for (int i = 0; i < N; i++)
		{
			int first = 0;
			for (int j = 0; j < N; j++)
			{
				if (i == j) continue;
				int dx = coord[j][0] - coord[i][0];
				int dy = coord[j][1] - coord[i][1];
				MyNumber* mn = get(dx, dy);
				MyNumber* mn2 = get(-dx, -dy);
				mn->plus++;
				mn2->minus++;
				if (mn2->sa < mn->sa)
					first++;
			}
			std::sort(set.begin(), set.end(), compare);

			int min = first;
			int cur = first;
			for (auto a : set)
			{
				cur -= a->minus;
				if (min > cur)
					min = cur;
				cur += a->plus;
			}
			fprintf(fout, "%d\n", min);
			for (auto a : set)
				delete a;
			set.clear();
			map.clear();
		}
	}
	return -0;
}
