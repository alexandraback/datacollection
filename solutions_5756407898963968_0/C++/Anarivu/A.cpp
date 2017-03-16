#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

int a[2][4][4];


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);

		int r[2];
		for(int t = 0; t < 2; t++)
		{
			scanf("%d", &r[t]);
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					scanf("%d", &a[t][i][j]);
		}
		r[0]--;
		r[1]--;
		int id = 0;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(a[0][r[0]][i] == a[1][r[1]][j])
				{
					if(!id)
						id = a[0][r[0]][i];
					else if(id > 0)
						id = -1;
				}
			}
		}
		if(id == 0)
			printf("Volunteer cheated!\n");
		else if(id < 0)
			printf("Bad magician!\n");
		else
			printf("%d\n", id);
	}

	return 0;
}