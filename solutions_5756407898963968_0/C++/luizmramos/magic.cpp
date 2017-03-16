#include <stdio.h>
#include <set>


int main() {
	int t;
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		int a;
		scanf("%d",&a);
		a--;
		std::set<int> S;
		for(int i =0;i<4;i++){
			for(int j=0;j<4;j++){
				int x;
				scanf("%d",&x);
				if(i==a){
					S.insert(x);
				}
			}
		}

		scanf("%d",&a);
		a--;
		int ans;
		int cont=0;
		for(int i =0;i<4;i++){
			for(int j=0;j<4;j++){
				int x;
				scanf("%d",&x);
				if(i==a){
					if(S.count(x)>0){
						cont++;
						ans = x;
					}
				}
			}
		}
		printf("Case #%d: ",xxx+1);
		if(cont==0){
			printf("Volunteer cheated!\n");
		}else if(cont==1){
			printf("%d\n",ans);
		}
		else{
			printf("Bad magician!\n");
		}
	}
}