#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int i,j,TC,cases,t1,t2,t3,t4,a1[4],a2[4],ans1,ans2,ans,no;

int main(){
	//freopen("in2","r",stdin);freopen("out.txt","w",stdout);
	
	scanf("%d",&TC);
	for (cases = 1 ;cases <= TC;cases ++){
		scanf("%d",&ans1);
		for (i=1;i<ans1;i++) scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		for (i=0;i<4;i++) scanf("%d",&a1[i]);
		for (i=ans1+1;i<=4;i++) scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		
		scanf("%d",&ans2);
		for (i=1;i<ans2;i++) scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		for (i=0;i<4;i++) scanf("%d",&a2[i]);
		for (i=ans2+1;i<=4;i++) scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		
		no = 0;
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
				if (a1[i] == a2[j]){
					no++;
					ans = a1[i];	
				}
		if (no==0) printf("Case #%d: Volunteer cheated!\n",cases);
		else if (no==1) printf("Case #%d: %d\n",cases,ans);
		else printf("Case #%d: Bad magician!\n",cases);
	}
	
}
