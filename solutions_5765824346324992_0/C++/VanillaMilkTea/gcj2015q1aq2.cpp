#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int lcm(int a,int b){
	int c=a*b;
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}

	return (c/a);
}


int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int B,N,num,done,mul,unit,parts;
	int min,minNum;
	int M[2000],t[2000];

	FILE *fin,*fout;

	//printf("lcm = %d",lcm(11,5));
	//return 0;

	fin=fopen("B-small-attempt4.in","rt");
	fout=fopen("B-small-attempt4.out","wt");
	
	
	fscanf(fin,"%d",&T);

	//T=2;
	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d",&B,&N);

		min=1000000;
		mul=1;
		for(i=0;i<B;i++){
			fscanf(fin,"%d",&(M[i]));
			mul=lcm(mul,M[i]);
		}

		for(i=B-1;i>=0;i--){
			if(M[i]<min){
				min=M[i];
				minNum=i+1;
			}
		}
		
		//printf("mul = %d\n",mul);

		if(B>=N){
			fprintf(fout,"Case #%d: %d\n",caseno,N);
			continue;
		}

		unit=0;
		for(i=0;i<B;i++){
			unit+=mul/M[i];
		}

		parts=N/unit;

	
		//printf("unit/part = %d %d\n",unit,parts);

		if(N==unit*parts){
			fprintf(fout,"Case #%d: %d\n",caseno,minNum);
			continue;
		}

		N=N-unit*parts;
		if(B>=N){
			fprintf(fout,"Case #%d: %d\n",caseno,N);
			continue;
		}

		N=N-B;
		for(j=0;j<B;j++) t[j]=0;

		k=1;
		while(k!=0){
			for(j=0;j<B;j++){
				t[j]++;
				if(t[j]==M[j]){
					t[j]=0;
					N--;
					if(N==0){
						num=j+1;
						k=0;
					}
				}
			}
		}

		fprintf(fout,"Case #%d: %d\n",caseno,num);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}