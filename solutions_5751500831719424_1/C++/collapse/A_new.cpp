#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
char s[110][104],l[110];
int co[110][104];
int n;
int calc(int x)
{
	int min,max,i,j,ans=-1,d,count;
	min = 200;
	max = -1;
	for (i=1;i<=n;i++)
	{
		if (co[i][x] > max)
			max = co[i][x];
		if (co[i][x] < min)
			min =  co[i][x];
	}
	for (i=min;i<=max;i++)
	{	
		count = 0;
		for (j=1;j<=n;j++)
		{
			d = co[j][x]-i;
			if (d < 0)
				d = -d;
			count = count + d;
		}
		if (ans==-1 || ans > count)
			ans = count;
	}	
	return ans;
}
int similar()
{
	int i,j=0,k,count=0,d;
	char st[110][104];
	for (k=1;k<=n;k++)
	{
		j = 0;
		for (i=0;i<l[k];i++)
		{
			if (i==0 || s[k][i]!=s[k][i-1])
			{
				st[k][j] = s[k][i];
				co[k][j] = 1;
				j++;
			}
			else
				co[k][j-1]++;
		}
		st[k][j] = 0;
	}
	for (i=2;i<=n;i++)
		if (strcmp(st[i],st[i-1])!=0)
			return -1;
	for (i=0;i<strlen(st[1]);i++)
	{
		d = calc(i);
		count = count + d;
	}
	return count;	
}
int main()
{
	int t,ca=0,d,i;
	char ch;
	scanf("%d%c",&t,&ch);
	while(t--)
	{
		ca++;
		scanf("%d%c",&n,&ch);
		for (i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			l[i] = strlen(s[i]);
		}
		d = similar();
		if (d==-1)
			printf("Case #%d: Fegla Won\n",ca);
		else
			printf("Case #%d: %d\n",ca,d);
	}
	return 0;
}
