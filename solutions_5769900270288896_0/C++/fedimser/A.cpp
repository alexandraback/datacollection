#include <bits/stdc++.h>
using namespace std;


char mx[16][16];
int c,r,n,ans;

int getv(int x, int y)
{
	if(x<0 || x>=r || y<0 || y>=c)return 0;
	return mx[x][y];
}

void rec(int z,int g)	
{
	int x,y;
	
	if(z==r*c)
	{
		if(g!=n)return;
		int ct=0;
		for(x=0;x<r;x++)
			for(y=0;y<c;y++)
			{
				if(mx[x][y]==1)
				ct+=getv(x-1,y)+getv(x,y-1)+getv(x,y+1)+getv(x+1,y);
				
			}
		//cout<<"U "<<ct/2<<"\n";
		ans=min(ans, ct/2);
		return;
	}
	
	x = z%r;
	y = z/r; 
	mx[x][y]=0;
	rec(z+1,g);
	 
	mx[x][y]=1;
	rec(z+1,g+1);
	 
}
 
int solve( )
{
	
	int ans=10*r*c;
	
	
	
	return ans;
}
  
int main()
{ 
	int  i,t;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	  
	cin>>t;
	 
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&r,&c,&n);
		ans=16000;
		rec(0,0);
		printf("Case #%d: %d\n",i,ans);
	}



}
