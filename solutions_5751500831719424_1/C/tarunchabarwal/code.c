#include<stdio.h>
#include<string.h>
#include<math.h>

char s[100][101];
int len[100];
int pos[100];
int cnt[100];
int n;
char curr;

void FillCount()
{
	int i, j;
	memset(cnt, 0, sizeof(int)*100);
	for(i=0;i<n;i++)
	{
		for(j=pos[i];;j++)
		{
			if(curr == s[i][j])
				cnt[i]++;
			else 
			{
				pos[i] = j;
				break;
			}
		}
	}
}

int IsValid()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i][pos[i]] != curr)
			return 0;
	}
	return 1;
}

int Convert()
{
	int i, j, min = cnt[0], max = cnt[0];
	int cost, min_cost = 1000000;
	for(i=1;i<n;i++)
	{
		if(cnt[i] < min) min = cnt[i];
		if(cnt[i] > max) max = cnt[i];
	}
	
	for(i = min; i <= max; i++)
	{
		cost = 0;
		for(j=0;j<n;j++)
		{
			cost += abs(i-cnt[j]);
		}
		if(cost < min_cost) min_cost = cost;
	}
	
	return min_cost;
}

int main()
{
	int cases, t_case;
	int i, j, k, fail, count;
	
	scanf("%d", &cases);
	for(t_case = 1; t_case <= cases; t_case++)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			pos[i] = 0;
		}
		fail = 0;
		count = 0;
		
		while(1)
		{
			if(pos[0] == len[0])break;
			curr = s[0][pos[0]];
			if(IsValid() == 0)
			{
				fail = 1;
				break;
			}
			FillCount();
			count += Convert();
		}
		for(i=0;i<n;i++)
		{
			if(pos[i] != len[i])
			{
				fail = 1;
				break;
			}
		}
		
		if(fail)printf("Case #%d: Fegla Won\n", t_case);
		else printf("Case #%d: %d\n", t_case, count);
	}
	return 0;
}