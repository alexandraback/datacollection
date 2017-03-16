#include<cstdio>
#include<cstring>

bool tab[20];

int main()
{
	int T; scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		memset(tab,0,sizeof(tab));
		int k; scanf("%d", &k);
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
			{
				int x; scanf("%d", &x);
				if(i+1 == k) tab[x] = 1;
			}
		scanf("%d", &k);
		int res = 0;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
			{
				int x; scanf("%d", &x);
				if(i+1 == k)
					if(tab[x])
						if(res)
							res = 20;
						else
							res = x;
			}
		if(res == 20)
			printf("Case #%d: Bad magician!\n",ii+1);
		else if(res == 0)
			printf("Case #%d: Volunteer cheated!\n",ii+1);
		else
			printf("Case #%d: %d\n",ii+1,res);
	}
	return 0;
}
