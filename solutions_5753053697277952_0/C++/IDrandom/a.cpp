#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
#include<string>
#define MAX 200000
#define INF 0x3f3f3f3f
using namespace std;
int dp[MAX+10];
int num[30];
int main(void)
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a_small.out","w",stdout);
	int n,t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		sum+=num[i];
		}
		printf("Case #%d: ",++cas);
		if(sum%2){
				int mx=0;
				int flag=-1;
			for(int i=0;i<n;i++){
				if(num[i]>mx){
					mx=num[i];
					flag=i;
				}
			}
			sum--;
			num[flag]--;
			printf("%c",'A'+flag);
			if(sum)printf(" ");
			else puts("");
		}
		while(sum){
			int mx=0;
			int flag=-1;
			for(int i=0;i<n;i++){
				if(num[i]>mx){
					mx=num[i];
					flag=i;
				}
			}
			sum--;
			num[flag]--;
			printf("%c",'A'+flag);
			mx=0;
			flag=-1;
			for(int i=0;i<n;i++){
				if(num[i]>mx){
					mx=num[i];
					flag=i;
				}
			}
			sum--;
			num[flag]--;
			printf("%c",'A'+flag);
			if(sum)printf(" ");
			else puts("");
		}
	}
	return 0;
}
