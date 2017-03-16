#include <cstdio>

int T,vl,row;
int ables[18];
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		for(int i=1;i<17;i++) ables[i]=0;
		scanf("%d",&row);
		for(int i=1;i<5;i++) {
			for(int j=0;j<4;j++) {
				scanf("%d",&vl);
				if(i==row) ables[vl]++;
			}
		}
		scanf("%d",&row);
		for(int i=1;i<5;i++) {
			for(int j=0;j<4;j++) {
				scanf("%d",&vl);
				if(i==row) ables[vl]++;
			}
		}
		int count=0;
		int sol_id=0;
		for(int i=1;i<17;i++) if(ables[i]==2) {
			sol_id=i;
			count++;
		}
		printf("Case #%d: ",ts);
		if(count>1) {
			printf("Bad magician!\n");
		} else if(count>0) {
			printf("%d\n",sol_id);
		} else {
			printf("Volunteer cheated!\n");
		}
	}
	return 0;
}
