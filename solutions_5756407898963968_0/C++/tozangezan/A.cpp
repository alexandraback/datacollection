#include<stdio.h>
int b[17];
int d[17];
int main(){
	int T;scanf("%d",&T);
	for(int t=0;t<T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				int x;
				scanf("%d",&x);
				b[x]=i+1;
			}
		int c;scanf("%d",&c);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				int x;scanf("%d",&x);
				d[x]=i+1;
			}
		int v=0;
		int w=0;
		for(int i=0;i<17;i++)if(a==b[i]&&c==d[i]){v++;w=i;}
		printf("Case #%d: ",t+1);
		if(v==1)printf("%d\n",w);
		if(v==0)printf("Volunteer cheated!\n");
		if(v>1)printf("Bad magician!\n");
	}
}