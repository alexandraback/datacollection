#include<cstdio>
#include<algorithm>
void tmain()
{
	int N;
	int arr[1010];
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",arr+i);
	int ans1=0,ans2=0,ma=0;
	for(int i=0;i<N-1;i++)
	{
		ans1+=std::max(0,arr[i]-arr[i+1]);
		ma=std::max(ma,arr[i]-arr[i+1]);
	}
	for(int i=0;i<N-1;i++) ans2+=std::min(arr[i],ma);
	printf("%d %d\n",ans1,ans2);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
	return 0;
}