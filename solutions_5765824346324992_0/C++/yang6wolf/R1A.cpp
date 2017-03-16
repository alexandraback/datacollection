// R1A.cpp : 定义控制台应用程序的入口点。
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

char Func(char cLeft, char cRight, bool &bNegative)
{
	if (cLeft == '1')
	{
		return cRight;
	}

	if (cLeft == 'i')
	{
		switch (cRight)
		{
		case '1':
			return 'i';
		case 'i':
			bNegative = true;
			return '1';
		case 'j':
			return 'k';
		case 'k':
			bNegative = true;
			return 'j';
		}
	}

	if (cLeft == 'j')
	{
		switch (cRight)
		{
		case '1':
			return 'j';
		case 'i':
			bNegative = true;
			return 'k';
		case 'j':
			bNegative = true;
			return '1';
		case 'k':
			return 'i';
		}
	}
	if (cLeft == 'k')
	{
		switch (cRight)
		{
		case '1':
			return 'k';
		case 'i':
			return 'j';
		case 'j':
			bNegative = true;
			return 'i';
		case 'k':
			bNegative = true;
			return '1';
		}
	}

	return 'Z';
}

void Find(string strData, int nBegin, int nEnd, char cTarget, vector<int> &vecData)
{
	char cResult = '1';
	bool bNegative = false;
	vecData.clear();

	for (int i = nBegin; i < nEnd; i++)
	{
		bool bChange = false;
		cResult = Func(cResult, strData[i%strData.length()], bChange);

		if (bChange)
		{
			bNegative = !bNegative;
		}

		if (bNegative == false && cResult == cTarget)
		{
			vecData.push_back(i);
		}
	}
}
int _tmain(){
	freopen("D:\\CodeJam\\a.in", "r", stdin);
	freopen("D:\\CodeJam\\a.out", "w", stdout);

	CASET{

		cout << "Case #" << case_n++ << ": ";

		int B,N;
		int Data[1050];
		memset(Data, 0, sizeof(Data));
		cin >> B;
		cin >> N;
		for (int i = 0; i < B; i++)
		{
			cin >> Data[i];
		}

		long long llLow = 0;
		long long llHigh = 10e17;

		int nCount = 0;
		int ans = -1;
		while (nCount++ < 1000)
		{
			long long llCur = (llLow + llHigh) / 2;

			long long llBegin = 0;
			for (int i = 0; i < B; i++)
			{
				if (llCur - 1 >= 0)
				{
					llBegin += ((llCur - 1) / Data[i])+1;
				}
			}

			vector<int> Can;
			for (int i = 0; i < B; i++)
			{
				if (llCur%Data[i] == 0)
				{
					Can.push_back(i + 1);
				}
			}

			if (llBegin >= N)
			{
				llHigh = llCur;
			}
			else if (llBegin + Can.size() < N)
			{
				llLow = llCur;
			}
			else
			{
				ans = Can[N - llBegin - 1];
				cout << ans << endl;
				break;
			}
			
		}
		if (ans == -1)
		{
			cout << "Error!" << endl;
		}	
	}
	return 0;
}
