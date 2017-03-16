#include <stdio.h>

char str[128];
char tmp[128];
int  buf[128][100];

int iabs(int x){ return x<0?-x:x; }

int getprocnum(int* b, int n){
	int sum = 0;
	int max=0,ans;
	int i,j;
	int min = 100000;
	for(i=0;i<n;i++){ if(max<b[i]) max=b[i]; }
	//for(i=0;i<n;i++){ sum+=b[i]; }
	//smin = 1<(sum/n)-2?(sum/n)-2:1;
	//sum = 0;
	//printf("max:%d\n", max);
	for(j=1;j<=max;j++){
		sum = 0;
		for(i=0;i<n;i++){ sum+=iabs(j-b[i]);}
		//printf("  j:%d sum:%d\n",j,sum);
		if(min>sum){ min = sum; ans = j;}
	}
	//printf("ans:%d min:%d\n",ans,min);
	return min;
}

int main(){
	int i,j,l,s;
	int index,sum;
	int T,N;
	int exitcode=0;

	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d",&N);
		scanf("%s",str);
		//printf("%s\n",str);
		index = 0;
		for(j=0;j<128;j++) for(l=0;l<N;l++) buf[j][l] = 0;
		for(j=0;str[j]!='\0';j++){
			if(str[index] != str[j]) str[++index] = str[j];
			buf[index][0]++;
		}
		str[++index] = '\0';
		exitcode = 0;
		for(j=1;j<N;j++){
			scanf("%s",tmp);
			//printf("%s\n",tmp);
			if(exitcode == -1) continue;
			s = 0;
			if(str[0] != tmp[0]){ exitcode = -1; continue;}
			for(l=0;tmp[l]!='\0';l++){
				if(str[s] == tmp[l]){buf[s][j]++;}
				else{
					s++;
					if(s >= index){ exitcode = -1; continue;}
					else if(str[s] != tmp[l]){ exitcode = -1; continue;}
					else{ buf[s][j]++;}
				}
			}
			if(s!=index-1){ exitcode = -1; continue;}
		}
		//for(j=0;j<N;j++) {for(l=0;l<index;l++){printf(" %d",buf[l][j]);} printf("\n");}
		if(exitcode == -1){ printf("Case #%d: Fegla Won\n",i); continue;}
		sum = 0;
		for(l=0;l<index;l++){sum += getprocnum(buf[l],N); }
		printf("Case #%d: %d\n",i,sum);
	}
	return 0;
}
