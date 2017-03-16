#include <iostream>
#include <stdio.h>
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	int T;
	int y1,temp,chet;
	int row1[4], otvet;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		chet = 0;
		scanf_s("%d", &y1);
		for (int j = 1; j <= 4; j++)
		{
			if (j == y1)
			{
				for (int k = 0; k < 4; k++)
				{
					scanf_s("%d", &row1[k]);
				}
			}
			else
			for (int k = 0; k < 4; k++)
			{
				scanf_s("%d", &temp);

			}
		}
		scanf_s("%d", &y1);
		for (int j = 1; j <= 4; j++)
		{
			if (j == y1)
			{
				for (int k = 0; k < 4; k++)
				{
					scanf_s("%d", &temp);
					for (int h = 0; h < 4; h++)
					{
						if (row1[h] == temp)
						{
							chet++;
							otvet = temp;
						}
					}
				}
			}
			else
			for (int k = 0; k < 4; k++)
			{
				scanf_s("%d", &temp);

			}
		}

		switch (chet)
		{
		case 0: printf("Case #%d: Volunteer cheated!\n",i); break;
		case 1: printf("Case #%d: %d\n",i,otvet); break;
		default: printf("Case #%d: Bad magician!\n", i); break;
		}
	}
}
