#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long int t,i,n,arr[2000],max_diff,res1,res2,j;
	scanf("%lld",&t);
	for(j=1;j<=t;j++){
        scanf("%lld",&n);
        max_diff=0;
        res1=0;
        res2=0;
        for(i=0;i<n;i++)
            scanf("%lld",arr+i);
        for(i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1])
                res1=res1+arr[i-1]-arr[i];
            max_diff=max(max_diff,arr[i-1]-arr[i]);
        }
        for(i=0;i<n-1;i++)
        {
            if(arr[i]<max_diff)
                res2+=arr[i];
            else
                res2+=max_diff;
        }
		printf("Case #%lld: %lld %lld\n",j,res1,res2);
	}
	return 0;
}
