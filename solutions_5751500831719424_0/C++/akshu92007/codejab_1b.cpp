#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
#define ll long long
using namespace std;
struct string
{
	char ar[105];
	int cnt[105];
	int length;
}str[105];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,count,k=0,mini,gsum,sum;
	char prev,s[105];
	scanf("%d",&t);
	while(t--)
	{
		k++;
		scanf("%d",&n);
		gets(s);
		for(int i=0;i<n;i++)
		{
			gets(s);
			str[i].length=0;
			str[i].ar[str[i].length]=s[0];
			prev=s[0];count=1;
			for(int j=1;s[j];j++)
			{
				if(s[j]!=prev)
				{
					str[i].cnt[str[i].length]=count;
					str[i].length++;
					str[i].ar[str[i].length]=s[j];
					count=0;
				}
				count++;
				prev=s[j];
			}
			str[i].cnt[str[i].length]=count;
			str[i].length++;
			str[i].ar[str[i].length]='\0';
		}
		/*for(int i=0;i<n;i++)
		{
			puts(str[i].ar);
			for(int j=0;j<str[i].length;j++)
			{
				printf("%d ",str[i].cnt[j]);
			}
			printf("\n");
		}*/
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if(strcmp(str[i].ar,str[0].ar)!=0)
			{
				flag=1;break;
			}
		}
		printf("Case #%d: ",k);
		if(flag==0)
		{
			gsum=0;
			for(int j=0;j<str[0].length;j++)
			{
				mini=INT_MAX;
				for(int w=1;w<=100;w++)
				{
					sum=0;
					for(int i=0;i<n;i++)
					{
						sum+=(max(w,str[i].cnt[j])-min(w,str[i].cnt[j]));
					}
					mini=min(mini,sum);
				}
				gsum+=mini;
			}
			printf("%d\n",gsum);
				
		}
		else
		printf("Fegla Won\n");
		
	}
}

