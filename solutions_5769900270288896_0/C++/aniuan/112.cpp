#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[20][20][20],bit[20];
int ans;
int main(){
	int r,c,n,i,j,sum,state,ans,kase,T,s,tmp,p;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for(i=0;i<20;i++) bit[i]=1<<i;
	memset(f,0xff,sizeof(f));
	for(kase=1;kase<=T;kase++){
		scanf("%d%d%d",&r,&c,&n);
		if(f[r][c][n]!=-1) ans=f[r][c][n];
		else{
			ans=1<<30; 
			state=1<<(r*c); p=r*c;
			for(s=0;s<state;s++){
				sum=0;
				for(i=0;i<p;i++)
					if(bit[i]&s) sum++;
				if(sum!=n) continue;
				tmp=0;
				for(i=0;i<r;i++)
					for(j=1;j<c;j++)
						if((bit[i*c+j]&s)&&(bit[i*c+j-1]&s)) tmp++;
				for(i=1;i<r;i++)
					for(j=0;j<c;j++)
						if((bit[i*c+j]&s)&&(bit[i*c-c+j]&s)) tmp++;
				if(tmp<ans) ans=tmp;
			}
			f[r][c][n]=ans;
		}
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
