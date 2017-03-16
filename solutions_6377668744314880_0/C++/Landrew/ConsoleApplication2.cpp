#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>



#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin("INP111.txt");


vector <int> x1;
vector <int> o1;
vector <int> res;
vector <int> indx;


//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

long long Area2(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	return ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
}

bool LeftOn(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (Area2(x1, y1, x2, y2, x3, y3) >= 0);
}


void CH()
{
	int n = x1.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				bool ext = true;
				for (int k = 0; k < n && ext; k++)
				{
					if (i != k && j != k)
					{
						if (!LeftOn(x1[i], o1[i], x1[j], o1[j], x1[k], o1[k]))
							ext = false;
					}
				}
				if (ext)
				{
					res.push_back(indx[i]);
					res.push_back(indx[j]);
				}
			}
		}
	}

	return;
}


int main() {

	//FILE* pFile;
	//pFile = fopen("ou.txt","w");

	// string na;
	// if (tt == 0)
	//  getline(fin,na);

	// getline(fin,na);

	// istringstream sin(na); 
	// string v; 
	// while (sin>>v) 
	//   names.push_back(v); 

	//fprintf(pFile, "Case #%d: ", t+1);
	//fprintf(pFile,"%d\n",res);

	int TT;
	fin >> TT;

	for (int tt = 0; tt<TT; tt++)
	{
		int n;
		fin >> n;
		int x[3003];
		int y[3003];

		for (int i = 0; i < n; i++)
			fin >> x[i] >> y[i];

		vector <int> bes;
		for (int i = 0; i < n; i++)
			bes.push_back(n - 1);


		for (int mask = 0; mask < (1 << n); mask++)
		{
			x1.clear();
			o1.clear();
			res.clear();
			indx.clear();
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i))
				{
					x1.push_back(x[i]);
					o1.push_back(y[i]);
					indx.push_back(i);
				}
			}
				CH();
				int xx = n;
				for (int j = 0; j < n; j++)
				{
					if (mask & (1 << j))
						xx--;
				}

				for (int i = 0; i < n; i++)
				{
					if (find(res.begin(), res.end(), i) != res.end())
					{
						if (bes[i] > xx)
							bes[i] = xx;
					}
				}
			}
		

		fout << "Case #" << tt + 1 << ": " << endl;
		for (int i = 0; i < n; i++)
			fout << bes[i] << endl;

	}

	return 0;
}

