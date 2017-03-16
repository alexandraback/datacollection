#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

int N;
vector<int> numInP;
int total = 0;

int GetMax()
{
	int maxNum = 0;
	int maxPos;
	for (int i = 0; i < N; ++i)
	{
		if (numInP[i] > maxNum)
		{
			maxNum = numInP[i];
			maxPos = i;
		}
	}
	--(numInP[maxPos]);
	--total;
	return maxPos;
}

static void HandleCase(const int cse)
{
	cin >> N;

	numInP.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> numInP[i];
		total += numInP[i];
	}

	cout << "Case #" << cse << ":";

	int a;
	while (total > 0)
	{
		a = GetMax();
		cout << " " << (char)('A' + a);
		if (total == 0)
			break;
		if (total == 2)
			continue;
		a = GetMax();
		cout << (char)('A' + a);
	}

	cout << endl;
}


int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	cin >> T;

	//string str;
	//getline(cin, str, '\n');

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


