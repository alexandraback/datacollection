#include<stdio.h>
#include<string>
#pragma warning(disable : 4996)
int num[1005];
int index[27];
int main(void)
{
	freopen("C:\\Users\\user\\Desktop\\inb.in","r",stdin);
    freopen("C:\\Users\\user\\Desktop\\output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(num,0,sizeof(num));
		memset(index,0,sizeof(index));
		int n;
		int tot=0;
		scanf("%d",&n);
		for(int k=0;k<n;k++)
		{
			scanf("%d",&num[k]);
			tot=tot+num[k];
		}
		printf("Case #%d:",i);
		int count=0;
		while(tot)
		{
			int max=0;
		    for(int j=0;j<n;j++)
			{
				if(num[j]>max)
				{
					memset(index,0,sizeof(index));
					max=num[j];
					index[j]=1;
					count=1;
				}
				else
				if(num[j]==max)
				{
					index[j]=1;
					count++;
				}
			}
			while(count)
			{
				if(count%2)
				{
					for(int i=0;i<=25;i++)
					{
						if(index[i])
						{
							printf(" %c",i+'A');
							index[i]=0;
							num[i]--;
							count--;
							tot--;
							break;
						}
					}
				}
				else
				{
					int pt=0;
					printf(" ");
					for(int i=0;i<=25;i++)
					{
						if(index[i])
						{
							printf("%c",i+'A');
							index[i]=0;
							pt++;
							num[i]--;
							count--;
							tot--;
						}
						if(pt==2)
						break;
					}
				}
			}
		}
		printf("\n");
	}
}


					





