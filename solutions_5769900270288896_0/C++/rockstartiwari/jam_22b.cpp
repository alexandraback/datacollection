#include<stdio.h>
#include<string.h>
int check(int val,int r,int c,int nk)
{
	int i,j;
	int nn=1;
	int ct=0;
	int mat[r][c];
	memset(mat,0,sizeof(mat));
	int kk=0;
	while(nn<=val)
	{
		if((nn&val)>0)
		{
			mat[ct/c][ct%c]=1;
			kk++;
		}
		ct++;
		nn=nn*2;
	}
	if(kk<nk)
		return -1;
	int ans=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]==0)
				continue;
			if(i-1>=0)
			{
				if(mat[i-1][j])
					ans++;
			}
			if(j-1>=0&&mat[i][j-1])
				ans++;
		}
	}
	return ans;
}
int main()
{
	int t;
	freopen("C:\\Users\\Gaurav\\Desktop\\bl.in","r",stdin);
    freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
	int ca=0;
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		int r,c,nk;
		scanf("%d%d%d",&r,&c,&nk);
		int n=r*c;
		int i;
		int r1=1;
		for(i=0;i<n;i++)
			r1=r1*2;
		int min=100000;
		for(i=0;i<=r1;i++)
		{
			int ans=check(i,r,c,nk);
			//printf("%d %d\n",i,ans);
			if(ans!=-1&&ans<min)
				min=ans;
		}
		printf("Case #%d: %d\n",ca,min);
	}
	return 0;
}