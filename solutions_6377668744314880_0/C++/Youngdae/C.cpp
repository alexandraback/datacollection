#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("output.txt");

long long x[3000], y[3000];
int N;

int side(int a, int b, int t)
{
	long long x1, x2, y1, y2, lhs, rhs;

	if(x[a]!=x[b])
	{
		if(x[a]<x[b])
		{
			x1 = x[a];
			y1 = y[a];
			x2 = x[b];
			y2 = y[b];
		}
		else
		{
			x1 = x[b];
			y1 = y[b];
			x2 = x[a];
			y2 = y[a];
		}

		lhs = (y[t]-y1)*(x2-x1);
		rhs = (y2-y1)*(x[t]-x1);
	}
	else
	{
		if(y[a]<y[b])
		{
			x1 = x[a];
			y1 = y[a];
			x2 = x[b];
			y2 = y[b];
		}
		else
		{
			x1 = x[b];
			y1 = y[b];
			x2 = x[a];
			y2 = y[a];
		}

		lhs = (x[t]-x1)*(y2-y1);
		rhs = (x2-x1)*(y[t]-y1);
	}

	if(lhs>rhs)
		return 1;
	else if(lhs==rhs)
		return 0;
	else if(lhs<rhs)
		return -1;
}

int cut(int t)
{
	if(N<=3)
		return 0;

	int mincut = 10000;

	for(int i=0; i<N; i++)
	{
		if(i==t)
			continue;

		int up=0, down=0;
		for(int j=0; j<N; j++)
		{
			if(j==t || j==i)
				continue;

			int s=side(t, i, j);
			
			if(s>0)
				up++;
			else if(s<0)
				down++;
		}

		if(up<mincut)
			mincut=up;
		if(down<mincut)
			mincut=down;
	}

	return mincut;
}

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": " << endl;
		////////////////////////////////////////////////////

		fin >> N;
		for(int i=0; i<N; i++)
			fin >> x[i] >> y[i];

		for(int i=0; i<N; i++)
			fout << cut(i) <<endl;
	}

	return 0;
}