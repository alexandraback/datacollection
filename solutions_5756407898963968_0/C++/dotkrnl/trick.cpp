#include <cstdio>
using namespace std;

int judge()
{
	int num[4], row, ret = 0, tmp;
	
	scanf("%d", &row);
	for(int i = 1; i <= 4; ++i)
		for(int j = 0; j < 4; ++j)
		{
			scanf("%d", &tmp);
			if(i == row)
				num[j] = tmp;
		}

	scanf("%d", &row);
	for(int i = 1; i <= 4; ++i)
		for(int j = 0; j < 4; ++j)
		{
			scanf("%d", &tmp);
			if(i == row)
			{
				for(int k = 0; k < 4; ++k)
					if(num[k] == tmp)
					{
						if(ret == 0)
							ret = tmp;
						else
							ret = -1;
					}
			}
		}

	return ret;
}

int main()
{
	int t;

	freopen("trick.in", "r", stdin);
	freopen("trick.out", "w", stdout);

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		int ret;
		switch(ret = judge())
		{
		case -1:
			puts("Bad magician!");
			break;
		case 0:
			puts("Volunteer cheated!");
			break;
		default:
			printf("%d\n", ret);
		}
	}

	fclose(stdin);
	fclose(stdout);
}
