// 2014rnd1b.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
//#include <cmath>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

int Cal1(vector<string> strArr)
{
	string str1 = strArr[0];
	char perC = str1[0];
	string strA = "";
	strA += perC;
	for (int i = 1; i < str1.length(); i++)
	{
		if (str1[i]!=perC)
		{
			perC = str1[i];
			strA += perC;
		}
	}

	int nR = 0; 
	vector<int> nPosArr(strArr.size(), 0);
	vector<int> nSizeArr(strArr.size(), 0);
	for (int i = 0; i < strA.length(); i++)
	{
		char curC = strA[i];
		for (int j = 0; j < strArr.size(); j++)
		{
			if (nPosArr[j] >= strArr[j].length())
			{
				return -1;
			}
			if (strArr[j][nPosArr[j]] != curC)
			{
				return -1;
			}
			nSizeArr[j] = 0;
			for (int k = nPosArr[j]; k < strArr[j].length(); k++)
			{
				if (strArr[j][k] != curC)
				{
					break;
				}
				nSizeArr[j]++;
				nPosArr[j]++;
			}
		}

		set<int> nSet(nSizeArr.begin(), nSizeArr.end());
		int nTotalMin = 100000;
		for (auto a = nSet.begin(); a != nSet.end(); ++a)
		{
			int nTotalT = 0;
			for (int j = 0; j < nSizeArr.size(); j++)
			{
				nTotalT += abs(nSizeArr[j]-*a);
			}
			nTotalMin = min(nTotalMin, nTotalT);
		}
		nR += nTotalMin;
	}
	for (int i = 0; i < strArr.size(); i++)
	{
		if (nPosArr[i] != strArr[i].length())
		{
			return -1;
		}
	}
	return nR;	
}

void main1()
{
	int T = 0;
	cin >> T;
	for (int nT  = 0; nT < T; nT++)
	{
		int n = 0;
		cin >> n;
		vector<string> strArr(n);
		for (int nn = 0; nn < n; nn++)
		{
			cin >> strArr[nn];
		}
		int nR = Cal1(strArr);
		cout << "Case #" << nT+1 << ": ";
		if (nR<0)
		{
			cout << "Fegla Won" << endl;
		}
		else
		{
			cout << nR << endl;
		}
	}
}

int _tmain(
	int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	main1();
	return 0;
}

