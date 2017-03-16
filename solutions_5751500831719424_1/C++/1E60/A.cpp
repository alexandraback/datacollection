#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char c[100];
	int count[100];
}S;

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		int n,N;
		int i;
		scanf("%d\n",&N);
		S ss[101];
		memset(ss,0,sizeof(ss));
		for (n=0;n<N;n++){
			char str[100];
			scanf("%s\n",str);
			char *s=str;
			i=-1;
			char last=0;
			while (*s){
				char cc=*s;
				if (last!=cc){
					i++;
					ss[n].c[i]=*s;
					ss[n].count[i]=1;
				}
				else{
					ss[n].count[i]++;
				}
				last=cc;
				s++;
			}
/*			for (i=0;i<100;i++){
				if (ss[n].c[i]==0)break;
ss_rep:;
				if (ss[n].c[i]==ss[n].c[i+1]){
					ss[n].count[i]+=ss[n].count[i+1];
					int j;
					for (j=i+1;j<100;j++){
						ss[n].c[j]=ss[n].c[j+1];
						ss[n].count[j]=ss[n].count[j+1];
					}
					goto ss_rep;
				}
			}*/
			/*for (i=0;i<100;i++){
				if (ss[n].c[i]==0)break;
				printf("%c%d",ss[n].c[i],ss[n].count[i]);
			}
			printf("\n");*/
		}
		//fprintf(stderr,"B\n");
		// Detect possibility
		int total_cost=0;
		for (i=0;i<100;i++){
			char c;
			c=ss[0].c[i];
			for (n=0;n<N;n++){
				if (ss[n].c[i]!=c){
					total_cost=-1;
					goto case_end;
				}
			}
			if (c==0)break;
			int cand,step_cost=100*100*100,cmin=101,cmax=0;
			for (n=0;n<N;n++){
				if (ss[n].count[i]<cmin)cmin=ss[n].count[i];
				if (ss[n].count[i]>cmax)cmax=ss[n].count[i];
			}
			//fprintf(stderr,"cmin=%d,cmax=%d\n",cmin,cmax);
			for (cand=cmin;cand<=cmax;cand++){
				int thiscost=0;
				for (n=0;n<N;n++){
					int d=cand-ss[n].count[i];
					if (d<0)d*=-1;
					thiscost+=d;
				}
				if (step_cost>thiscost)step_cost=thiscost;
			}
			total_cost+=step_cost;
		}
case_end:;
		if (total_cost>=0){
			printf("Case #%d: %d\n",t,total_cost);
		}
		else{
			printf("Case #%d: Fegla Won\n",t);
		}
	}
	return 0;
}
