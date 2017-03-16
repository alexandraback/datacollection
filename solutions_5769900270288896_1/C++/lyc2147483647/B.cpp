#include<cstdio>
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
int T;
int jizz(int r,int c,int n)
{
		if(r==1)
		{
				r=c;
				c=1;
		}
		if(r%2==0)
		{
				int d=r/2;
				int cost=n-d;
				if(cost==1) return 1;
				cost-=1;
				return 1+cost*2;
		}
		else
		{
				int d=(r+1)/2;
				int cost=n-d;
				return 2*cost;
		}
}
int solve(int r,int _c,int n)
{
		if(2*n<=r*_c) return 0;
		if(r==1||_c==1) return jizz(r,_c,n);
		int d=(r*_c+1)/2;
		int cost = n-d;
		int ans=0;
		if(r*_c%2==1) 
		{
				int ans1=0;
				int s=r+_c-2;
				int c=min(cost,s);
				ans1+=3*c;
				cost-=c;
				ans1+=4*cost;
				
				int ans2=0;
				cost=n-d+1;
				s=4;
				c=min(cost,s);
				ans2+=2*c;
				cost-=c;
				s = r+_c-6;
				c=min(cost,s);
				ans2+=3*c;
				cost-=c;
				ans2+=4*cost;
				return min(ans1,ans2);
		}
		else
		{
				int s,c;
				s = 2;
				c=min(cost,s);
				ans+=2*c;
				cost-=c;
				if(cost==0) return ans;
				s = r+_c-4;
				c=min(cost,s);
				ans+=3*c;
				cost-=c;
				if(cost==0) return ans;
				else return ans+4*cost;
		}
}
int main()
{
		FILE *in = fopen("in.txt","r");
		FILE *out = fopen("out.txt","w");
		int t=0,n,r,c;
		fscanf(in,"%d",&T);
		while(T--)
		{
			t++;
			fscanf(in,"%d%d%d",&r,&c,&n);
			fprintf(out,"Case #%d: %d\n",t,solve(r,c,n));
		}
}
