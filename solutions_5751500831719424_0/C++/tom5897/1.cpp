#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
char input[105],temp,word[105][105];
int cnt[105][105],data[105][105];
int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	int i,j,k,n,m,l,count,cnt2,t,min,sum;
	
	fscanf(fi,"%d",&t);
	for(m=0;m<t;m++){
		fprintf(fo,"Case #%d: ",m+1);
		fscanf(fi,"%d",&n);
		count=0;
		for(i=0;i<n;i++){
			fscanf(fi,"%s",input);
			l = strlen(input);
			word[i][0] = input[0];
			cnt[i][0]=1,count=0;
			for(j=1;j<l+1;j++){
				if(input[j] == word[i][count]){
					cnt[i][count]++;
				}
				else {
					count++;
					word[i][count] = input[j];
					cnt[i][count]=1;
				}
			}
		}
		for(i=1;i<n;i++){
			if(strlen(word[i]) != strlen(word[i-1]) || strcmp(word[i],word[i-1])!=0){
				fprintf(fo,"Fegla Won\n"); break;
			}
		}
		if(i!=n) continue;
		l = strlen(word[0]);
		for(i=0;i<l;i++){
			for(j=0;j<n;j++) data[i][j] = cnt[j][i];
		}
		sum=0;
		for(i=0;i<l;i++){
			std::sort(data[i],data[i]+n);
			for(j=0;j<n;j++){
				sum+= abs(cnt[j][i] - data[i][n/2]);
			}
		}
		fprintf(fo,"%d\n",sum);
 	}
	return 0;
}