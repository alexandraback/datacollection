// GCJ.cpp : 定义控制台应用程序的入口点。
//

// Standing Ovation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<sstream>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; (C); ++I)
#define CASET int ___t, case_n = 1; cin>>___t; while (___t-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
#define SIZE 1000

int Test1(int R, int C, int N)
{
	int *pData = new int[R*C];
	memset(pData, 0, sizeof(int)*R*C);

	int nZero = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if ((i + j) % 2 == 0)
			{
				pData[i*C + j] = 1;
				nZero++;
			}
		}
	}

	int nTwo = 0;
	int nThree = 0;
	int nFour = 0;

	int X[4] = { 0, 1, 0, -1 };
	int Y[4] = { 1, 0, -1, 0 };
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (pData[i*C + j] == 0)
			{
				int nCur = 0;
				for (int k = 0; k < 4; k++)
				{
					int nX = i + X[k];
					int nY = j + Y[k];

					if (nX >= 0 && nX < R && nY >= 0 && nY < C)
					{
						if (pData[nX*C + nY] == 1)
						{
							nCur++;
						}
					}
				}

				if (nCur == 2)
				{
					nTwo++;
				}
				else if (nCur == 3)
				{
					nThree++;
				}
				else
				{
					nFour++;
				}
			}
		}
	}

	int ans = 0;
	N -= nZero;

	if (N > 0)
	{
		ans += 2 * min(nTwo, N);
		N -= nTwo;
	}

	if (N > 0)
	{
		ans += 3 * min(nThree, N);
		N -= nThree;
	}

	if (N > 0)
	{
		ans += 4 * min(nFour, N);
		N = 0;
	}


	delete[]pData;

	return ans;
}

int Func(int *pData, int R, int C, int nNum)
{
	int X[4] = { 0, 1, 0, -1 };
	int Y[4] = { 1, 0, -1, 0 };
	int ans = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (pData[i*C + j] == 0)
			{
				int nCur = 0;
				for (int k = 0; k < 4; k++)
				{
					int nX = i + X[k];
					int nY = j + Y[k];

					if (nX >= 0 && nX < R && nY >= 0 && nY < C)
					{
						if (pData[nX*C + nY] == 0)
						{
							nCur++;
						}
					}
				}

				if (nCur == nNum)
				{
					pData[i*C + j] = 1;
					ans++;
				}
			}
		}
	}

	return ans;
}
int Test2(int R, int C, int N)
{
	int *pData = new int[R*C];
	memset(pData, 0, sizeof(int)*R*C);

	int nFour = Func(pData, R, C, 4);
	int nThree = Func(pData, R, C, 3);
	int nTwo = Func(pData, R, C, 2);
	int nOne = Func(pData, R, C, 1);

	N = R*C - N;

	int nTotal = (R - 1)*C + R*(C - 1);

	if (N > 0)
	{
		nTotal -= 4 * min(nFour, N);
		N -= nFour;	
	}

	if (N > 0)
	{
		nTotal -= 3 * min(nThree, N);
		N -= nThree;
	}

	if (N > 0)
	{
		nTotal -= 2 * min(nTwo, N);
		N -= nTwo;
	}

	if (N > 0)
	{
		nTotal -=  min(nOne, N);
		N -= nOne;
	}

	return nTotal;
}
int _tmain(){
	freopen("E:\\CodeJam\\a.in", "r", stdin);
	freopen("E:\\CodeJam\\a.out", "w", stdout);

	CASET{

		cout << "Case #" << case_n++ << ": ";

		int R, C, N;
		cin >> R >> C >> N;


		int ans = min(Test1(R,C,N), Test2(R, C, N));


		cout << ans<< endl;

		
	}
	return 0;
}



