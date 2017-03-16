#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int io(){
	int R=0;
	for(int i=0;i<4;i++){
		int x; scanf("%d",&x);
		R|=(1<<x);
	}
	return R;
}
int main(){
	int t,no=0; scanf("%d",&t);
	while(t--){
		int a,b;
		int R[5],C[5];
		scanf("%d",&a);
		for(int i=1;i<=4;i++)
			R[i]=io();
		scanf("%d",&b);
		for(int i=1;i<=4;i++)
			C[i]=io();
			
		int res=R[a] & C[b];
		
		printf("Case #%d: ",++no);
		if(res==0)puts("Volunteer cheated!");
		else if(__builtin_popcount(res)>1)puts("Bad magician!");
		else printf("%.0lf\n",log2((double)res));
	}
}
