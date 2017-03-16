#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

pair<int,char> arr[100];

int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int tot=0;
		int p,t;
		scanf("%d",&p);
		for(int b=0;b<p;b++)
		{
			scanf("%d",&t);
			tot+=t;
			arr[b]=mp(t,'A'+b);
		}
		printf("Case #%d:",a);
		while(tot!=0)
		{
			sort(arr,arr+p);
			if(tot==3)
			{
				printf(" %c",arr[p-1].ss);
				arr[p-1].ff--;
				tot--;
			}
			else
			{
				printf(" %c",arr[p-1].ss);
				arr[p-1].ff--;
				tot--;
				sort(arr,arr+p);
				printf("%c",arr[p-1].ss);
				arr[p-1].ff--;
				tot--;
			}
		}
		printf("\n");
	}
}
