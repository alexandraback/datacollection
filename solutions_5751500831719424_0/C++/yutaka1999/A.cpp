#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define INF 1000000000

using namespace std;

char str[SIZE];
char as[SIZE][SIZE];
int sz[SIZE],cnt[SIZE][SIZE];
int arr[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			int len=strlen(str);
			sz[i]=0;
			for(int j=0;j<len;)
			{
				as[i][sz[i]]=str[j];
				int s=j;
				for(;j<len&&str[s]==str[j];j++);
				cnt[i][sz[i]]=j-s;
				sz[i]++;
			}
		}
		bool up=true;
		for(int i=0;i<n;i++)
		{
			if(sz[0]!=sz[i])
			{
				up=false;
				break;
			}
			else
			{
				for(int j=0;j<sz[i];j++)
				{
					if(as[0][j]!=as[i][j])
					{
						up=false;
						break;
					}
				}
				if(!up) break;
			}
		}
		if(!up)
		{
			puts("Fegla Won");
			continue;
		}
		int ret=0;
		for(int i=0;i<sz[0];i++)
		{
			for(int j=0;j<n;j++) arr[j]=cnt[j][i];
			sort(arr,arr+n);
			int mn=INF;
			for(int j=max(0,n/2-5);j<=min(n-1,n/2+5);j++)
			{
				int sum=0;
				for(int k=0;k<n;k++) sum+=abs(arr[k]-arr[j]);
				mn=min(mn,sum);
			}
			ret+=mn;
		}
		printf("%d\n",ret);
	}
	return 0;
}
