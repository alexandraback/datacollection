#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int mx = 110;

int n;
int a[mx][mx];
char u[mx];
int len[mx];
char s[mx][mx];

int main()
{
	int T;
	int ca = 1;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		bool bLose = false;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			len[i] = strlen(s[i]);
			int len_tmp = 0;
			static char str_tmp[mx];
			for(j=0;j<len[i];j++)
			{
				if( 0 == j || s[i][j] != s[i][j-1] )
				{
					a[len_tmp][i] = 1;
					str_tmp[len_tmp++] = s[i][j];
				}
				else
				{
					a[len_tmp - 1][i]++;
				}
			}
			str_tmp[len_tmp++] = '\0';
			if( 0 == i ) strcpy(u,str_tmp);
			else if( strcmp(u,str_tmp) != 0 ) bLose = true;
		}
		if( !bLose )
		{
			int len_u = strlen(u);
			int ans = 0;
			//for(i=0;i<len_u;i++)
			//{
			//	for(j=0;j<n;j++)
			//	{
			//		printf("%d ",a[i][j]);
			//	}
			//	printf("\n");
			//}
			for(i=0;i<len_u;i++)
			{
				sort(a[i],a[i] + n);
				int mid = a[i][n/2];
				for(j=0;j<n;j++)
					ans += (a[i][j]>mid)?(a[i][j]-mid):(mid-a[i][j]);
			}
			printf("Case #%d: %d\n",ca++,ans);
		}
		else
		{
			printf("Case #%d: Fegla Won\n",ca++);
		}
	}
	return 0;
}

