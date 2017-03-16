#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	
//freopen("A-small-attempt0.in", "r", stdin);
//freopen("A-small-attempt0.out", "w", stdout);
    int tc;
    scanf("%d",&tc);
    for(int ii=1;ii<=tc;ii++){
            int x,y,i,j,k,ans=0,s=0;
            int a[20],b[20];
            scanf("%d",&x);
            for(i=1;i<=4;i++){
				for(j=1;j<=4;j++){
					scanf("%d",&k);
					a[k]=i;
				}
			}
			scanf("%d",&y);
            for(i=1;i<=4;i++){
				for(j=1;j<=4;j++){
					scanf("%d",&k);
					b[k]=i;
				}
			}
			
			for(i=1;i<=16;i++)if(x==a[i]&&y==b[i])s++,ans=i;
			
			printf("Case #%d: ",ii);
			if(s==0)printf("Volunteer cheated!\n");
			else if (s>1)printf("Bad magician!\n");
			else if(s==1)printf("%d\n",ans);
	}
	
	return 0;
}		
             
			                  
