#include <stdio.h>
#include <string.h>

int main(){

	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int test,i,j,tc=1,ans,n;
	char in[102][103];
	
	for( scanf("%d",&test) ; test-- ;){
		memset(in,0,sizeof(in));
		
		scanf("%d",&n);
		for( i=0 ; i<n; i++ ){
			scanf("%s",in[i]);
		}
		
		for( i=j=ans=0 ; ; ){
			if( in[0][i]==0 && in[1][j]==0 ) break;
			if( in[0][i] == in[1][j] ){
				i++;j++;
				continue;
			}
			
			if( i==0 || j==0 ){
				ans=-1;
				break;
			}
			
			while( in[0][i]==in[0][i-1] ){
				ans++;
				i++;
			}
			while( in[1][j]==in[1][j-1] ){
				ans++;
				j++;	
			}
			if( in[0][i]!=in[1][j] ){
				ans=-1;
				break;
			}
		}
		
		
		printf("Case #%d: ",tc++);
		
		if( ans==-1 ) printf("Fegla Won\n");
		else printf("%d\n",ans);
		
	}
	
	return 0;
}

