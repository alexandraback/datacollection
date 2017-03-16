#include <cstdio>

using namespace std;

int main()
{
	int t, i;
	scanf("%d",&t);

	char s[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (i=1;i<=t;i++)
	{
		int n, j;
		scanf("%d",&n);

		int a[26];
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}

		printf("Case #%d: ",i);
		while(1)
		{
			int large=0;
			int li=-1;
			int c=0;
			for (j=0;j<n;j++)
			{
				if (a[j]>large){
					large=a[j];
					li=j;
				}
				if (a[j]>0)
					c++;
			}

			

			if (c>2)
			{
				printf("%c ",s[li]);
				a[li]--;
			}
			else
			{
				int lesslarge=0;
				int lli=-1;
				for (j=0;j<n;j++)
				{
					if (a[j]>lesslarge && j!=li){
						lesslarge=a[j];
						lli=j;
					}
				}

				for (j=0;j<large;j++)
				{
					printf("%c%c ",s[li],s[lli]);
				}
				printf("\n");
				break;
			}



		}
	}
}