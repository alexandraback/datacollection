#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int card1[5], card2[5], dp[5][5];

int main()
{
	int T, a, b, tmp, ans;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		scanf("%d", &a);
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				if(j == a - 1) scanf("%d", &card1[k+1]);
				else scanf("%d", &tmp);
			}
		}
		scanf("%d", &b);
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				if(j == b - 1) scanf("%d", &card2[k+1]);
				else scanf("%d", &tmp);
			}
		}
		sort(card1 + 1, card1 + 5);
		sort(card2 + 1, card2 + 5);
		//for(int j = 0; j < 4; j++) printf("%d ", card1[j]);
		//printf("\n");
		//for(int j = 0; j < 4; j++) printf("%d ", card2[j]);
		//printf("\n");
		dp[0][0] = dp[0][1] = dp[1][0] = 0;
		memset(dp, 0, sizeof(dp));
		for(int j = 1; j <= 4; j++)
			for(int k = 1; k <= 4; k++)
			{
				if(card1[j] == card2[k]) { dp[j][k] = dp[j-1][k-1] + 1; ans = card1[j]; }
				else dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
			}
		printf("Case #%d: ", i);
		if(dp[4][4] == 1)
			printf("%d\n", ans);
		else if(dp[4][4] > 1)
			printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	return 0;
}
		