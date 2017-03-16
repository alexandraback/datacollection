#include<stdio.h>
int arr[100000],b;
long long int check(long long int mid)
{
	int i;
	long long int ans=0;
	//mid--;
	for(i=0;i<b;i++){
		ans=ans+(mid/arr[i])+1;
	}
	return ans;
}
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\bl.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		ca++;
		int n;
		scanf("%d%d",&b,&n);
		int i;
		for(i=0;i<b;i++)
			scanf("%d",&arr[i]);
		long long int num1=n,num=b,ans1=0,j;
		for(i=0;i<b;i++){
			long long int low=0,high=10,mid,aa=0;
			for(j=0;j<16;j++)
				high=high*10;
			while(low<=high)
			{
				mid=(low+high)/2;
				long long int ans=check(mid);
				if(ans<n)
					low=mid+1;
				else if(ans>=n)
					{
						high=mid-1;
						aa=mid;
					}
			}
			mid=aa;
			//printf("%lld\n",mid);
			if(i==0){
				ans1=mid;
				n--;
				continue;
			}
			if(ans1!=mid)
			{
				num=num1-n;
				//printf("%d\n",n);
				break;
			}
			n--;
		}
		//num--;
		//printf("%d\n",num);
		for(i=0;i<b;i++){
			if((ans1)%arr[i]==0){
				num--;
			}
			if(num<=0)
				break;
		}
		printf("Case #%d: %d\n",ca,i+1);
	}
	return 0;
}