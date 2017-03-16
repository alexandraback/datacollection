#include <cstdio>
#include <cstring>
using namespace std;

int cnt[32];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int l = 0; l < 2; l++)
		{
			int ti;
			scanf("%d", &ti);
			ti--;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
				{
					int num;
					scanf("%d", &num);
					if(i == ti)
						cnt[num]++;
				}
		}
		int c2 = 0, ans = -1;
		for(int i = 1; i <= 16; i++)
			if(cnt[i] >= 2)
			{
				c2++;
				ans = i;
			}
		printf("Case #%d: ", t);
		if(c2 == 0)
			printf("Volunteer cheated!\n");
		else if(c2 == 1)
			printf("%d\n", ans);
		else
			printf("Bad magician!\n");
	}
	return 0;
}
