#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){

	int test,tc=1,ans,i,j;
	int r,c,n,temp;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d\n",tc++,ans) ){
		scanf("%d%d%d",&r,&c,&n);
		n=r*c-n;
		ans = (r-1)*c+r*(c-1);
		
		if( r>c ) swap(r,c);
		if( r==1 ){
			ans = max(0,ans-2*n);	
		}
		else if( r==2 ){
			temp=c-2;	// 3 wall room	
			ans -= min(temp*3,n*3);
			n-=temp;
			if( n>=2 ) ans-=4;
			else if( n==1 ) ans-=2;
		}
		else{
			i=ans;
			j=n;
			
			temp=(r-2)*(c-2)/2;	// 4 wall room
			ans -= min(temp*4,n*4);
			n-=temp;
			if( n>0 ){	// still heff room
				temp = r*c/2-temp;	// remaining relevant room
				if( (r&1)&&(c&1) );	// no 2-wall
				else temp-=2;	// hef 2-wall
				
				ans -= min(temp*3,n*3);
				n-=temp;
				
				if( n>0 ){	// might still hef 2-walls
					if( (r&1)&&(c&1) );
					else{
						ans -= min(n*2,4);	
					}
				}
			}
			
			
			if( (r&1)&&(c&1) ){	// other configuration of odd dimension room
				n=j;
				swap(i,ans);
				
				temp=(r-2)*(c-2)/2+1;	// 4 wall room
				ans -= min(temp*4,n*4);
				n-=temp;
				if( n>0 ){
					temp = r*c/2+1-temp-4;	// 3wall room
					ans -= min(temp*3,n*3);	
					n-=temp;
					
					if( n>0 ){
						ans -= min(8,n*2);
					}
				}
				if( i<ans ) ans=i;
			}
			
			
		}
	}

	return 0;
}

