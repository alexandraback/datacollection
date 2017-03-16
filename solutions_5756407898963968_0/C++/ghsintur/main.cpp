
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

unsigned int  firstarr[4][4];
unsigned int  sectarr[4][4];

void solve(unsigned int firstRow, unsigned int secRow)
{
	unsigned int res;
	unsigned int numOfCards = 0;
	unsigned int i;
	unsigned int j;
	
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (firstarr[firstRow][i] == sectarr[secRow][j])
			{
				res = firstarr[firstRow][i];
				numOfCards++;
			}
		}
	}

	if (0 == numOfCards)
	{
		fout << "Volunteer cheated!" << endl;
	}
	else if (1 == numOfCards)
	{
		fout << res << endl;
	}
	else
	{
		fout << "Bad magician!" << endl;
	}

}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	unsigned int first;
	unsigned int sec;

	char c;
	fin >> c;
	fin >> c;
	fin >> c;
	fin >> numOfTests;

	for (i = 0; i<numOfTests; i++)
	{
		fin >> first;
		for (j = 0; j < 4; j++)
		{
			fin >> firstarr[j][0] >> firstarr[j][1] >> firstarr[j][2] >> firstarr[j][3];
		}
		fin >> sec;
		for (j = 0; j < 4; j++)
		{
			fin >> sectarr[j][0] >> sectarr[j][1] >> sectarr[j][2] >> sectarr[j][3];
		}
	
		fout << "Case #"<<i+1<<": ";
		solve(first-1, sec-1);
	}
}
