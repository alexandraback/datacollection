#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long int a[1000006];

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	long long int f,f1,i,n,x,y,m;
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		x=0;
		for(i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			x=x+a[i-1]-a[i];
		}
		
		y=0;m=0;
    	for(i=0;i<n-1;i++)
        {
        	if(a[i]>=a[i+1] && a[i]-a[i+1]>m)
            {
               	m=a[i]-a[i+1];
            }
        }
        for(i=0;i<n-1;i++)
        {
            y=y+min(m,a[i]);
        }
		
		
		printf("Case #%lld: %lld %lld\n",f1,x,y);
	}
	return 0;
}
