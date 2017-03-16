#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

char s[110][110] , s2[110][110];
int num[110][110];

void del(int i)
{
	int len = strlen(s[i]);
	int cnt = 0;
	for (int j = 0 ; j < len ; j++)
	{
		if (j && s[i][j] == s[i][j-1]) 
		{
			num[i][cnt-1]++;
			continue;
		}
		num[i][cnt] = 1;
		s2[i][cnt++] = s[i][j];
	}
	s2[i][cnt] = '\0';
//	printf("%s\n",s2[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	int cas = 0;
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i = 0 ; i < n ; i++)
		{
			scanf("%s",s[i]);
			del(i);
		}
		bool flag = true;
		for (int i = 1 ; i < n ; i++)
			if (strcmp(s2[i],s2[i-1]) != 0)
				flag = false;

		printf("Case #%d: ",++cas);
		if (!flag)
		{
			puts("Fegla Won");
			continue;
		}
		int len = strlen(s2[0]);
		int ans = 0;
		for (int i = 0 ; i < len ; i++)
		{
			int tmp = 1000000;
			for (int j = 1 ; j <= 100 ; j++)
			{
				int tmp2 = 0;
				for (int k = 0 ; k < n ; k++)
					tmp2 += abs(num[k][i] - j);
				tmp = min(tmp,tmp2);
			}
//			printf("%d\n",tmp);
			ans += tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
