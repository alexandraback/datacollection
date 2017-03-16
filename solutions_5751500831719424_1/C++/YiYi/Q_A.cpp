#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath> 
#include<cstring> 
#include<map> 
#include<set>
#include<algorithm>

using namespace std;

char s[128][128];
char base[128];
int cnt[128][128], cc;

bool GetBase(int num)
{
	int j;
	int k = 0;
	for(j = 0; j < strlen(s[num]); j ++)
	{
		if(j == 0 || s[num][j-1] != s[num][j])
		{
			k ++;
			if(num == 0)
			{
				base[k] = s[num][j];
			}
			else 
			{
				if(base[k] != s[num][j])
					return false;
			}
			cnt[num][k] = 1;
		}
		else 
		{
			cnt[num][k] ++;
		}
	}
	if(num == 0)
	{
		cc = k;
	}
	else if(cc != k)
	{
		return false;
	}
	return true;
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		int n;
		int i, j, k;
		int ans = 0;
		bool flag = true;
		scanf("%d", &n);

		for(i = 0; i < n; i ++)
		{
			scanf("%s", s[i]);
			if(GetBase(i) == false)flag = false;
		}

		for(j = 1; j <= cc; j ++)
		{
			int tmp = 0x7fffffff;
			for(i = 0; i < n; i ++)
			{
				int tt = 0;
				for(k = 0; k < n; k ++)
				{
					tt += abs(cnt[i][j] - cnt[k][j]);
				}
				tmp = min(tt, tmp);
			}
			ans += tmp;
		}

		if(flag)
		{
			printf("Case #%d: %d\n", cas, ans);
		}
		else 
		{
			printf("Case #%d: Fegla Won\n", cas);
		}
	}
	return 0;
}
