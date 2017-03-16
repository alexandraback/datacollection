#include<bits/stdc++.h>

using namespace std;

int arr[50][50];

int solve(int x,int y)
{
    int result=0;
    if(arr[x-1][y]==1) 
	result++;
    if(arr[x][y-1]==1) 
	result++;
    return result;
}
 
int main()
{
 
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    int r,c,n;
    int t;
    scanf("%d",&t);
    for (int z=1;z<=t;z++)
    {
        scanf("%d %d %d",&r,&c,&n);
        int res=1e9;
        int temp=r*c;
        
        for (int i=1;i<(1<<temp);i++)
        {
        	int denominator=0;
            memset(arr,0,sizeof(arr));
            
            
            for(int j=0;j<temp;j++)
                if((i>>j)&1) 
				denominator++;
            if(denominator==n)
            {
                for(int j=0;j<temp;j++)
                if((i>>j)&1)
                {
        
                    int val=j+1;
                    int fuckit=(val/c)+(val%c!=0);
                    int bc=val-(fuckit-1)*c;
                    arr[fuckit][bc]=1;
                }
                
                int result=0;
                for(int lol=1;lol<=r;lol++)
                for(int tt=1;tt<=c;tt++)
                     if(arr[lol][tt]==1)
                         result+=solve(lol,tt);
                res=min(res,result);
            }
        }
        if(n==0) 
		res=0;
		printf("Case #%d: %d\n",z,res);
    }
    return 0;
}

