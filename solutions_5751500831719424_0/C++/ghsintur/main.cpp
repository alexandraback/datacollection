
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <iomanip>
#define UINT64 unsigned __int64
using namespace std;
ifstream  fin("b.txt");
ofstream  fout("c.txt");

char srtingArr[100][101];
int arrRep[100];
int nextStringCh[100];

int solve(unsigned int n)
{
	unsigned int		result			=0;
	unsigned int		i;
	unsigned int		j;
	unsigned int		temp;
	unsigned int		min;
	unsigned int		maxRep = 1;
	char c;

	memset(arrRep, 0, sizeof(arrRep));
	memset(nextStringCh, 0, sizeof(nextStringCh));
	while(true)
	{
		c = srtingArr[0][nextStringCh[0]];
	
		if(c ==0)
		{
			//make sure all strin equal 0
			for (i = 0; i < n; i++)
			{
				if(srtingArr[i][nextStringCh[i]]!= 0)
				{
					return -1;
				}
			}

			return result;
		}
		else
		{
			memset(arrRep, 0, sizeof(arrRep));
			//find rep of c
			maxRep = 1;
			for (i = 0; i < n; i++)
			{
				j=nextStringCh[i];
				temp = 0;
				while(c == srtingArr[i][j])
				{
					temp++;
					j++;

				}
				arrRep[i] = temp;
				nextStringCh[i] = j;
				if(0 == temp)
				{
					return -1;
				}
				if(temp > maxRep)
				{
					maxRep = temp;
				}
			}

			
			for(j=1;j<=maxRep;j++)
			{
				temp =0;
				for (i = 0; i < n; i++)
				{
					if(arrRep[i] > j)
					{
						temp += (arrRep[i] -j);
					}
					else
					{
						temp += (j- arrRep[i]);
					}
				}

				if(j == 1)
				{
					min = temp;
				}
				else if(temp < min)
				{
					min = temp;
				}
			}
			
			result += min;
			
		}

	}



	return result;
}

void solveAndPrint(unsigned int n)
{
	int res;

	res = solve(n);
	
	if(res == -1)
	{
		fout << "Fegla Won" <<endl;
	}
	else
	{
		fout << res <<endl;
	}
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int l;
	unsigned int j;
	unsigned int c;
	fin >> numOfTests;
	fout << std::setprecision(9) << fixed;
	for (i = 0; i<numOfTests; i++)
	{
		fin >> l;
		memset(srtingArr, 0, sizeof(srtingArr));
		for(j=0; j<l;j++)
		{
			fin>>srtingArr[j];
		}
	
		fout << "Case #" << i + 1 << ": ";
		solveAndPrint(l);

	}
	
}
