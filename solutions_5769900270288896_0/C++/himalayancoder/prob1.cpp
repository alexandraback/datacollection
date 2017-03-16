// Rohit Bhardwaj

#include<bits/stdc++.h>
#define md 1000003
#define ll long long
#define gc getchar_unlocked
using namespace std;
int mat[100][100];

int main()
{
	
    	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
	   freopen("out.txt","w",stdout);		
		#endif
		int test;
		int r,c,n;
		scanf("%d",&test);
		for(int tst=1;tst<=test;tst++){
			printf("Case #%d: ",tst);
			scanf("%d%d%d",&r,&c,&n);
			for(int i=1;i<=r;i++)
				for(int j=1;j<=c;j++)
					mat[i][j]=4;
			for(int i=1;i<=r;i++)
			{	mat[i][1]=3;mat[i][c]=3;}
			for(int i=1;i<=c;i++)
			{mat[1][i]=3;mat[1][r]=3;}
		mat[1][1]=mat[1][c]=mat[r][1]=mat[r][c]=2;
			int no=r*(c-1)+c*(r-1);
			int x=r*c;
			int r1=0,c1=0,mx=0;
			while(x>n){
				for(int i=1;i<=r;i++)
					for(int j=1;j<=c;j++)
					{
						if(mat[i][j]>mx){
							mx=mat[i][j];
							r1=i;
							c1=j;
						}
					}
					x--;
					no-=mx;
					mat[r1][c1]=0;
					mat[r1-1][c1]--;
					mat[r1+1][c1]--;
					mat[r1][c1-1]--;
					mat[r1][c1+1]--;
			}
			no=max(no,0);
			printf("%d\n",no);
			
			
			
		}
    return 0;
}
