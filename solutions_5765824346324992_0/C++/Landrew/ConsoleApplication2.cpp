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

long long bb[1001];
int b, n;

long long comp(long long x)
{
	long long su = 0;
	for (int i = 0; i < b; i++)
	{
		long long rem = x%bb[i];
		if (rem == 0)
			su = su + x / bb[i] + 1;
		else
			su = su + (x - rem) / bb[i] + 1;
 	}
	return su;
}

bool done(long long x)
{
	long long su1 = comp(x);
	return (su1 >= n);
}

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

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
		fin >> b >> n;
		for (int i = 0; i < b; i++)
			fin >> bb[i];

		long long mi = 0;
		long long ma = 300000000000000;

		while ((ma - mi) > 5)
		{
			long long mid = (ma + mi) / 2;
			if (done(mid))
				ma = mid;
			else
				mi = mid;
		}
	
		bool fin = false;
		int res = -1;
		for (long long ti = mi; ti <= ma && !fin; ti++)
		{
			long long cur = comp(ti);
			if (cur >= n)
			{
				fin = true;
				long long prev = comp(ti - 1);
				long long pos = prev;
				for (int i = 0; i < b && res == -1; i++)
				{
					if (ti%bb[i] == 0)
					{
						pos++;
						if (pos == n)
							res = i;
					}
				}
			}
		}

		fout << "Case #" << tt + 1 << ": " << res+1 << endl;


	}

	return 0;
}

