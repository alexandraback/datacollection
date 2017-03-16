#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,k,n,m,tests,now,v[21],ans,cot;
int main(){
	scanf("%d",&tests);
	for (now=1;now<=tests;now++){
		printf("Case #%d: ",now);
		scanf("%d",&n);memset(v,0,sizeof(v));
		for (i=1;i<=4;i++)
		 for (j=1;j<=4;j++){
		 	scanf("%d",&k);
		 	if (n==i) v[k]++;
		 }
		scanf("%d",&m);
		for (i=1;i<=4;i++)
		 for (j=1;j<=4;j++){
		 	scanf("%d",&k);
		 	if (m==i) v[k]++;
		 }
		for (ans=cot=0,i=1;i<=16;i++)
		 if (v[i]==2){
		 	cot++;ans=i;
		 }
		if (!cot) puts("Volunteer cheated!");
		if (cot>1) puts("Bad magician!");
		if (cot==1) printf("%d\n",ans);
	}
	return 0;
}
