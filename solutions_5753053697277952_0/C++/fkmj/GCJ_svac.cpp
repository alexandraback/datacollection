#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair<int,char> arr[26]={};
int main()
{
	int T,n,t1,t2,nl;
	scanf("%d",&T);
	for(int z=1;z<=T;z++)
	{
		scanf("%d",&n);
		nl=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i].first);
			nl+=arr[i].first;
			arr[i].second=i+65;
		}
		printf("Case #%d: ",z);
		while(nl>0)
		{
			sort(arr,arr+n);
			if(nl==3&&arr[n-1].first==arr[n-2].first)
			{
				printf("%c ",arr[n-1].second);
				arr[n-1].first--;
				nl--;
			}
			else if(arr[n-1].first==arr[n-2].first)
			{
				printf("%c%c ",arr[n-1].second,arr[n-2].second);
				nl-=2;
				arr[n-1].first--;
				arr[n-2].first--;
			}
			else
			{
				printf("%c ",arr[n-1].second);
				arr[n-1].first--;
				nl--;
			}
		}
		printf("\n");
	}
}
