#include<stdio.h>
#include<string.h>
char s1[101], s2[101];
char c1[101], c2[101];
int main()
{
	int cases;
	int i, j, k, n, count;
	int l1, l2;
	int pos1, pos2, p1, p2;
	int match;
	
	scanf("%d", &cases);
	for(i=1;i<=cases;i++)
	{
		scanf("%d", &n);
		scanf("%s %s", s1, s2);
		
		l1 = strlen(s1);
		l2 = strlen(s2);
		
		pos1 = -1;
		c1[++pos1] = s1[0];
		for(j=1;j<l1;j++)
		{
			if(s1[j] != c1[pos1])
			{
				c1[++pos1] = s1[j];
			}
		}
		c1[++pos1] = 0;
		
		pos2 = -1;
		c2[++pos2] = s2[0];
		for(j=1;j<l2;j++)
		{
			if(s2[j] != c2[pos2])
			{
				c2[++pos2] = s2[j];
			}
		}
		c2[++pos2] = 0;
		
		if(strcmp(c1, c2))
		{
			printf("Case #%d: Fegla Won\n", i);
		}
		else
		{
			count = 0;k=0;
			p1=p2=0;match = 0;
			while(p1<l1 && p2 < l2)
			{
				if(s1[p1] == s2[p2])
				{
					while(s1[p1] == c1[k] && s1[p1] == s2[p2])
					{
						p1++;
						p2++;
					}
					k++;
				}
				else
				{
					while(c1[k] != s1[p1])
					{
						count++;
						p1++;
					}
					while(c2[k] != s2[p2])
					{
						count++;
						p2++;
					}
				}
			}
			while(p1<l1)
			{
				p1++;count++;
			}
			while(p2<l2)
			{
				p2++;count++;
			}
			printf("Case #%d: %d\n", i, count);
		}
	}
	return 0;
}