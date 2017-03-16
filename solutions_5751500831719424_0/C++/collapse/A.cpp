#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
char s[2][400];
int similar(int l[])
{
	int i,j=0,k,count=0,d;
	char st[2][400];
	int co[2][400]={0};
	for (k=0;k<2;k++)
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
	if (strcmp(st[0],st[1])!=0)
		return -1;
	for (i=0;i<strlen(st[0]);i++)
	{
		d = co[0][i]-co[1][i];
		if (d < 0)
			d = -d;
		count = count + d;
	}
	return count;	
}
int main()
{
	int t,ca=0,l[2],d,n;
	char ch;
	scanf("%d%c",&t,&ch);
	while(t--)
	{
		ca++;
		scanf("%d%c",&n,&ch);
		scanf("%s%s",s[0],s[1]);
		l[0] = strlen(s[0]);
		l[1] = strlen(s[1]);
		d = similar(l);
		if (d==-1)
			printf("Case #%d: Fegla Won\n",ca);
		else
			printf("Case #%d: %d\n",ca,d);
	}
	return 0;
}
