#include <stdio.h>
#include <string.h>

int main(){

	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	int test,i,j,tc=1,ans,a,b,c,d,ans2;
	bool flag[17];
	
	for( scanf("%d",&test) ; test-- ;){
		memset(flag,0,sizeof(flag));
		
		scanf("%d",&j);
		for( i=1 ; i<=4 ; i++ ){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if( i==j ) flag[a]=flag[b]=flag[c]=flag[d]=true;
		}
		
		scanf("%d",&j);
		for( i=1 ; i<=4 ; i++ ){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if( i==j ){
				ans=flag[a]+flag[b]+flag[c]+flag[d];
				ans2=flag[a]?a:flag[b]?b:flag[c]?c:d;
			}
		}
		
		printf("Case #%d: ",tc++);
		
		if( ans==0 ) printf("Volunteer cheated!\n");
		else if( ans>1 ) printf("Bad magician!\n");
		else printf("%d\n",ans2);
		
	}
	
	return 0;
}

