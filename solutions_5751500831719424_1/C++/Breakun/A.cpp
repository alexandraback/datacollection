#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int sz = 128;
int T, n;
char buf[sz];
int len[sz], str[sz][sz], cnt[sz][sz], a[sz];

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++)
	{
		memset(len, 0, sizeof(len));
		memset(str, 0, sizeof(str));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			for(int j = 0; buf[j]; j++)
			{
				if(j == 0 || buf[j] != buf[j - 1])
				{
					str[i][len[i]] = buf[j];
					cnt[i][len[i]] = 1;
					len[i]++;
				}
				else
					cnt[i][len[i] - 1]++;
			}
		}
		printf("Case #%d: ", tt);
		bool ok = true;
		for(int i = 1; i < n; i++)
			if(len[i] != len[0])
				ok = false;
		if(ok)
		{
			for(int i = 1; i < n; i++)
				for(int j = 0; j < len[0]; j++)
					if(str[i][j] != str[0][j])
						ok = false;
			if(ok)
			{
				int ans = 0;
				for(int j = 0; j < len[0]; j++)
				{
					for(int i = 0; i < n; i++)
						a[i] = cnt[i][j];
					sort(a, a + n);
					for(int st = 0, ed = n - 1; st < ed; st++, ed--)
						ans += a[ed] - a[st];
				}
				printf("%d\n", ans);
			}
		}
		if(!ok)
			printf("Fegla Won\n");
	}
	return 0;
}
