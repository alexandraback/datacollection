#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int test,i[102],j,k,tc=1,ans,n,temp,now[102],high,temp2;
	char in[102][103],huruf;
	
	for( scanf("%d",&test) ; test-- ;){
		memset(in,0,sizeof(in));
		memset(i,0,sizeof(i));
		
		scanf("%d",&n);
		for( j=0 ; j<n; j++ ){
			scanf("%s",in[j]);
		}
		
		for( ans=0 ; ; ){
			for( j=0 ; j<n ; j++ ) if( in[j][i[j]]!=0 ) goto cont;	
			break;
			cont:
				
			huruf = in[0][i[0]];
			high=1;
			
			for( j=0 ; j<n ; j++ ){
				if( in[j][i[j]]!=huruf ){
					ans=-1;
					goto fail;
				}
				
				for( temp=1 ; in[j][i[j]]==in[j][i[j]+1] ; temp++ ) i[j]++;
				now[j]=temp;
				if( temp>high ) high=temp;
				
				i[j]++;
			}
			
			temp=1000000000;
			for( k=1 ; k<=high ; k++ ){
				temp2=0;
				for( j=0 ; j<n ; j++ ){
					temp2+=abs(now[j]-k);
				}
				if( temp2<temp ) temp=temp2;
			}
			ans+=temp;
		}
		
		fail:
		
		printf("Case #%d: ",tc++);
		
		if( ans==-1 ) printf("Fegla Won\n");
		else printf("%d\n",ans);
		
	}
	
	return 0;
}

