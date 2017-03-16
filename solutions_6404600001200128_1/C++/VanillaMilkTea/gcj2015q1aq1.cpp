#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int N,sum1,sum2,r,max;
	int arr[100000];
	int *p;

	FILE *fin,*fout;

	fin=fopen("A-large.in","rt");
	fout=fopen("A-large.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d",&N);

		r=0;
		for(i=0;i<N;i++){
			fscanf(fin,"%d",&(arr[i]));
			
		}

		for(i=1;i<N;i++){
			if(arr[i]<arr[i-1]){
				if((arr[i-1]-arr[i])>r) r=arr[i-1]-arr[i];
			}
		}
		//if((arr[N-2]-arr[N-1])>max) max=(arr[N-2]-arr[N-1]);

		//printf("max = %d\n",max);

		sum1=0;sum2=0;

		for(i=1;i<N;i++){
			if(arr[i-1]>arr[i])
				sum1+=(arr[i-1]-arr[i]);
		}
		for(i=0;i<N-1;i++){
			if(arr[i]>=r)
				sum2+=r;
			else
				sum2+=arr[i];
		}
//		sum2+=(arr[N-2]-arr[N-1]);


		//p=lower_bound(arr,arr+N,4);
		//printf("index = %d\n",p-arr);
			

		fprintf(fout,"Case #%d: %d %d\n",caseno,sum1,sum2);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}