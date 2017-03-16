#include<stdio.h>
int arr[100000],arr1[10000];
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\aa.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		ca++;
		int n;
		scanf("%d",&n);
		int i;
		int max=0;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]>max)
				max=arr[i];
		}
		int fir=0;

		for(i=1;i<n;i++)
		{
			if(arr[i]<arr[i-1])
				fir=fir+arr[i-1]-arr[i];
		}
		int sec=100000000,j,min=100000000;
		for(i=0;i<=max;i++)
		{
			int sum=0;
			for(j=0;j<n-1;j++)
			{
				arr1[j]=arr[j]-i;
				if(arr1[j]<0){
					arr1[j]=0;
					sum=sum+arr[j];
				}
				else
					sum=sum+i;
			}
			for(j=1;j<n;j++)
			{
				if(arr[j]<arr1[j-1])
					break;
			}
			if(j==n){
				//printf("%d\n",i);
				if(sum<sec)
					sec=sum;
			}
		}
		printf("Case #%d: %d %d\n",ca,fir,sec);
	}
	return 0;
}