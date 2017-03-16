#include <stdio.h>

FILE *ifp;
FILE *ofp;

int T;
int N;
int m[10000];
int eat1;
int eat2;

void input();
void process();
void output(int);

int main(void){
	int t;

	ifp=fopen("A-large.in","r");
	ofp=fopen("output.txt","w");

	fscanf(ifp,"%d", &T);

	for(t=1;t<=T;t++){
		input();
		process();
		output(t);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}

void input(){
	int i;

	fscanf(ifp, "%d", &N);
	for(i=0;i<N;i++){
		fscanf(ifp, "%d", &m[i]);
	}
}

void process(){
	int i;
	int max=0;

	eat1=0;
	eat2=0;
	for(i=0;i<N-1;i++){
		if(m[i]>m[i+1]){
			eat1+=m[i]-m[i+1];
			if(max<m[i]-m[i+1]){
				max=m[i]-m[i+1];
			}
		}
	}

	for(i=0;i<N-1;i++){
		eat2 += (max>=m[i])?m[i]:max;
	}
}

void output(int t){
	fprintf(ofp, "Case #%d: %d %d\n", t, eat1, eat2);
}