#include<cstdio>
#include<vector>
using namespace std;
int n,B;
int ar[1004];
vector<int> vec;
long long fun(long long x)
{
	
	long long ret=0;
	for(int i=0;i<B;i++)
	{
		long long t=x/ar[i]  + 1;
		ret+=t;
	}

	return ret;
}
long long fun2(long long x)
{
	for(int i=0;i<B;i++)
	{
		if(x%ar[i]==0) 
		{
			vec.push_back(i);
		//	printf("pushing %d\n",i);
		}
	}
	
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%d %d",&B,&n);
		
		for(int i=0;i<B;i++)
		scanf("%d",&ar[i]);
	//	printf("here");
	    long long c=0,x=0;
	  //  printf("here");
	    long long s=0,e=1000000000000000LL;
	while(s<=e)
		{
			long long mid=(s+e)/2;
			if(fun(mid)>=n) e=mid-1;
			else s=mid+1;
		//	printf("in %lld  %lld  %lld %lld\n",s,e,mid,fun(mid));
		}
	c=e;
	
//	printf("out %lld",c);
		int ans;
		int r=fun(c);
		int cc=0;
		fun2(c+1);
	//	printf("here %d %d\n",c,n-fun(c));
		int y=n-fun(c);
		ans=vec[n-fun(c)-1];
	//	printf("chh y= %d %d %d %d %d",y,vec[0],vec[1],vec[2]);
		vec.clear();
		for(int i=0;i<B;i++) ar[i]=0;
		printf("%d\n",ans+1);
	}
}
