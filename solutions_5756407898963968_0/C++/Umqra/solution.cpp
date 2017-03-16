#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100;
int a[N][N];
bool used[N];

void scanAns()
{
	int pos;
	scanf("%d", &pos);
	pos--;
	for (int i = 0; i < 4; i++)
		for (int s = 0; s < 4; s++)
			scanf("%d", &a[i][s]);
	for (int i = 0; i < 4; i++)
		for (int s = 0; s < 4; s++)
			if (i != pos)
				used[a[i][s]] = 0;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
	    for (int s = 1; s <= 16; s++) used[s] = 1;
		scanAns();
		scanAns();
		int cnt = 0;
		int val = 0;
		for (int s = 0; s <= 16; s++)
		{
			if (used[s])
			{
				cnt++;
				val = s;
			}
		}            
		if (cnt == 0)
			printf("Case #%d: Volunteer cheated!\n", i + 1);
		else if (cnt == 1)
			printf("Case #%d: %d\n", i + 1, val);
		else
			printf("Case #%d: Bad magician!\n", i + 1);
	}

	return 0;
}