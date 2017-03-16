#include<stdio.h>
char bad_mage[]={"Bad magician!"};
char volun_cheat[]={"Volunteer cheated!"};
int main(){
	int T,t=0;
	int n;
	int possible[4];
	int dummy;
	int ans;
	scanf("%d",&T); 
	while(++t<=T){
		scanf("%d",&n);
		for(int i=1 ; i<=4 ; i++){
			if(i!=n)
				scanf("%d%d%d%d",&dummy,&dummy,&dummy,&dummy);
			else
				scanf("%d%d%d%d",possible,possible+1,possible+2,possible+3);
		}
		scanf("%d",&n);
		ans=0;
		for(int i=1 ; i<=4 ; i++){
			if(i!=n)
				scanf("%d%d%d%d",&dummy,&dummy,&dummy,&dummy);
			else{
				for(int i=1 ; i<=4 ; i++){
					scanf("%d",&dummy);
					for(int j=0 ; j<4 && ans!=-1 ; j++){
						if(dummy==possible[j]){
							if(ans!=0){
								ans=-1;
							}
							else{
								ans=dummy;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: ",t);
		switch(ans){
		case 0:
			printf("%s\n",volun_cheat);
			break;
		case -1:
			printf("%s\n",bad_mage);
			break;
		default:
			printf("%d\n",ans);
		}
	}
return 0;
}
