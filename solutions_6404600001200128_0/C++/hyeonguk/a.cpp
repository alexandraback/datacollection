#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

void testCase()
{
	int n;
	scanf("%d", &n);
	int answerA = 0, answerB = 0;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 1; i < n; i++)
	{
		if (data[i - 1] > data[i])
		{
			answerA += data[i - 1] - data[i];
			answerB = max(answerB, data[i - 1] - data[i]);
		}
	}
	int answerC = 0;
	for (int i = 1; i < n; i++)
	{
		answerC += min(data[i - 1], answerB);
	}
	printf("%d %d", answerA, answerC);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		testCase();
		printf("\n");
	}

	return 0;
}