#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair

using namespace std;

typedef long long ll;

const int INF = 0x60000000;
const int MINF = -1000000000;
const ll mod = 1000000007;
const int cons = 50000001;
const double pi = 3.141592653589793;



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testCases;
	scanf("%d", &testCases);

	for (int testNum = 1; testNum <= testCases; testNum++)
	{
		printf("Case #%d: ", testNum);
		
		int n;
		scanf("%d", &n);

		int arr[26] = { 0 };
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", arr + i);

			sum += arr[i];
		}

		int s = -1;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] * 2 > sum)s = i;
		}


		if (s != -1)
		{
			if (arr[s] >= 2)
			{
				printf("%c%c ", 'A' + (char)s, 'A' + (char)s);
				arr[s] -= 2;
				sum -= 2;
			}
			else
			{
				printf("%c ", 'A' + (char)s);
				arr[s]--;
				sum--;
			}
		}

		while (sum > 2)
		{
			int t = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] > t)
				{
					t = arr[i];
					s = i;
				}
			}

			printf("%c", 'A' + (char)s);
			sum--;
			arr[s]--;

			s = -1;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] * 2 > sum)
				{
					s = i;
				}
			}

			if (s == -1)printf(" ");
			else
			{
				printf("%c ", 'A' + (char)s);
				sum--;
				arr[s]--;
			}
		}

		int f =-1;
		s = -1;

		for (int i = 0; i < n; i++)
		{
			if (f == -1 && arr[i])f = i;
			else if (s == -1 && arr[i])s = i;
		}

		if (s != -1)
		{
			printf("%c%c\n", 'A' + (char)f, 'A' + (char)s);
			sum -= 2;
		}
		else
		{
			printf("%c\n", 'A' + (char)f);
			sum -= 1;
		}
	}

	return 0;
}