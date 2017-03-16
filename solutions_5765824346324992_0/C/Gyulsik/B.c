#include <stdio.h>

FILE *ifp;
FILE *ofp;

int T;
int B, N;
int M[1000];
int idx;

void input();
void process();
void output(int);
int getlcm(int a, int b){
   int lcm, gcd;
   int z;
   int x = a;
   int y = b;

   while (1){
      z = x % y;
      if (z == 0)
         break;
      x = y;
      y = z;
   }

   gcd = y;
   lcm = a*b / y;
   return lcm;
}

int main(void){
	int t;

	ifp=fopen("B-small-attempt0.in","r");
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

	fscanf(ifp, "%d %d", &B, &N);
	
	for(i=0;i<B;i++){
		fscanf(ifp, "%d", &M[i]);
	}
}

void process(){
	int i;
	int lcm;
	int sum=0;
	int time;

	lcm=M[0];
	for(i=1;i<B;i++){
		lcm = getlcm(lcm, M[i]);
	}
	for(i=0;i<B;i++){
		sum += lcm/M[i];
	}

	N = (N-1)%sum;
	
	if(N<B){
		idx = N;
		return;
	}

	N-=B;
	idx=0;
	time=1;
	while(N>=0){
		for(i=0;i<B;i++){
			if(time%M[i]==0){
				if(N<0)
					break;
				N--;
				idx=i;
			}
		}
		time++;
	}
}

void output(int t){
	fprintf(ofp, "Case #%d: %d\n", t, idx+1);
}