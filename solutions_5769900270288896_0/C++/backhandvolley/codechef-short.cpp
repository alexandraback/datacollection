// codechef-short.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <queue>
#include <fstream>
using namespace std;

int reverse(int num)
{
	int rev_num = 0;
	while (num > 0)
	{
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
}

int popc(int x)
{
	int c = 0;
	for (int i = 0; i < 31; i++) if (x & (1 << i)) c++;
	return c;
}
int g[18][18] = { { 0 } };

int in(int x, int y, int r, int c)
{
	if (x < 0 || y < 0)return 0;
	if (x >= r || y >= c) return 0;
	return 1;
}
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
void print()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int check(int r,int c)
{
	//print();
	int y = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (!g[i][j]) continue;
			for (int k = 0; k < 4; k++)
			{
				int tx = i + dx[k], ty = j + dy[k];
				if (!in(tx, ty, r, c)) continue;
			//	cout << "here" << endl;
				if (g[tx][ty])
					y++;
			}
		}
	}
//	cout << y << endl;
	return y/2;
}
int solve(int r, int c, int n)
{
	int m = r*c;
	int mn = INT_MAX;
	for (int i = 0; i < (1 << m); i++)
	{
		if (popc(i) != n) continue;
	//	cout << "bits " <<i << endl;
		memset(g, 0, sizeof(g));
		for (int j = 0; j < m; j++)
		{
			if ((1 << j) & i)
			{
				g[j/c][j%c] = 1;
				//print();
				
			}
		}
		mn = min(mn, check(r, c));
	}
	//cout << mn << endl;
	return mn;
}
int main()
{
	int t;
	ifstream in("in.txt");
	in >> t;
	ofstream out("out.txt");
	
	for (int tc = 1; tc<= t; tc++)
	{
		int r,c ,n;
		in >> r >> c >> n;
		int x = solve(r,c,n);
		memset(g, 0,sizeof(g));
		out << "Case #" << tc  << ": " << x << endl;
	}

	return 0;
}

