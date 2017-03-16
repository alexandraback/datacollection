#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int T[23];

int main(){
	int zz; scanf("%d", &zz);
	FWD(z,1,zz+1){
		FWD(i,1,17) T[i] = 0;
		int a;
		scanf("%d", &a);
		FWD(i,0,4)
			FWD(j,0,4){
				int x;
				scanf("%d", &x);
				if(a-1 == i)
					++T[x];
			}
		scanf("%d", &a);
		FWD(i,0,4)
			FWD(j,0,4){
				int x;
				scanf("%d", &x);
				if(a-1 == i)
					++T[x];
			}
		int c = 0;
		FWD(i,1,17) if(T[i] == 2) ++c, a = i;
		printf("Case #%d: ", z);
		if(c == 0)
			printf("Volunteer cheated!");
		else if(c == 1)
			printf("%d", a);
		else
			printf("Bad magician!");
		printf("\n");
	}
	return 0;
}
