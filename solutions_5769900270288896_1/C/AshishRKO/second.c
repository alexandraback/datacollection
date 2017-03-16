#include <stdio.h>
 
int main(void) {
	// your code goes here
	int T,i;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		long long int c,a,R,w,C,N,j,prod,k,sum=0;
		scanf("%lld %lld %lld",&R,&C,&N);
		long long int arr[R][C];
		prod=R*C;
		k=prod/2;
		if(R<C)
		c=C;
		else
		c=R;
		if(N%2==0)
		{
			if (k>=N)
			{
				printf("Case #%d: %lld\n",i,sum);
				continue;
			}
			a=1;
			for(j=k+1;j<=N;j++)
			{
				if((R>1)&&(C>1))
				{
					if(a<=2)
					sum=sum+2;
					else if(j<(prod-c+2))
					sum=sum+3;
					else
					sum=sum+4;
				}
				else
				{
					if(a==1)
					{
						sum=sum+1;
					}
					else
					sum=sum+2;
				}
			}
		}
		if(N%2==1)
		{
			if ((k+1)>=N)
			{
				printf("Case #%d: %lld\n",i,sum);
				continue;
			}
			if((N-1)==prod)
			{
				sum=(R-1)*C+(C-1)*R-4;
				printf("Case #%d: %lld\n",i,sum);
				continue;
			}
 
			a=1;
			w=(R-2)*(C-2);
			w=w-(w/2+1);
			for(j=k+1;j<=N;j++)
			{
				if(c>1)
				{
					if(j<(prod-w))
					sum=sum+3;
					else
					sum=sum+4;
				}
				else
				{
					sum=sum+2;
				}
			}
		}
		printf("Case #%d: %lld\n",i,sum);
	}
	return 0;
}