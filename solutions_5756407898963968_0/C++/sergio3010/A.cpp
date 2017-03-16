#include <bits/stdc++.h>




using namespace std;







#define fr(i,a,b) for(int i=a;i<b;++i)

int mat[10][10];

int getms(){
	int r;
	scanf("%d",&r);
	r--;
	int ret = 0;
	fr(i,0,4){
		fr(j,0,4){ 
			scanf("%d",&mat[i][j]);
			if(i == r) ret |= 1<<(mat[i][j]-1);
		}
	}
	return ret;
}

int t;


int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		int x = getms();
		x &= getms();
		printf("Case #%d: ",cas);
		if(x == 0) printf("Volunteer cheated!\n");
		else if(__builtin_popcount(x) > 1) printf("Bad magician!\n");
		else printf("%d\n",__builtin_ctz(x)+1);
	}
	return 0;
}