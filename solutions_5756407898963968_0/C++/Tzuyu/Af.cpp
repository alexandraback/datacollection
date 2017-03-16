#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
	
using namespace std;

int main(){
	int i,j,count,flag,l1,l2,T,ti;
	int mmp[5][5],mbp[5][5];
	int bap[17];
	FILE * inf, * outf;
	inf=fopen("A-small-attempt0.in.txt","r");
	outf=fopen("A-small.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		memset(mmp,0,sizeof(mmp));
		memset(mbp,0,sizeof(mbp));
		memset(bap,0,sizeof(bap));
		count=0;
		flag=0;
		fscanf(inf,"%d",&l1);
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++){
				fscanf(inf,"%d",&mmp[i][j]);
				if (i==l1){
					if (!bap[mmp[i][j]]) bap[mmp[i][j]]+=1;
				}
			}
		fscanf(inf,"%d",&l2);
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++){
				fscanf(inf,"%d",&mbp[i][j]);
				if (i==l2) {
					if (bap[mbp[i][j]]) {
						count++;
						flag=mbp[i][j];
					}
				}
			}
		fprintf(outf,"Case #%d: ",ti+1);
		if (count==0){
			fprintf(outf,"Volunteer cheated!\n");
		}
		else if (count>1){
			fprintf(outf,"Bad magician!\n");
		}
		else {
			fprintf(outf,"%d\n",flag);
		}
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
