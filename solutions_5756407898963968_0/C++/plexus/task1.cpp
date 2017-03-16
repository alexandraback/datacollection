#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 10;

int a[N][N];
int b[N][N];

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);

		int answer1, answer2;
		scanf("%d", &answer1);

		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
				scanf("%d", &a[i][j]);

		scanf("%d", &answer2);

		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
				scanf("%d", &b[i][j]);			

		int cnt = 0;
		int last = 0;

		answer1--, answer2--;

		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++)
				if (a[answer1][i] == b[answer2][j])
				{
					cnt++;
					last = a[answer1][i];
				}

		//cout<<"- "<<cnt<<" "<<last<<" "<<answer1 << " " << answer2 << " -";

		if (cnt == 0)
		{
			printf("Volunteer cheated!\n");
		}
		else if (cnt > 1)
		{
			printf("Bad magician!\n");
		}
		else
		{
			printf("%d\n", last);
		}

	}

	return 0;
}