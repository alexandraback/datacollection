#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>

#define gc getchar_unlocked()
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mod 1000000007
#define swap(a,b) ((b)=(a)^(b)^((a)=(b)))
#define INF 100000000000000000LL
#define fill(a,b,c) memset(a,0,sizeof(b)*(c));
#define pb push_back

using namespace std;

typedef long long int LL;

LL power(LL b,LL p)
{	LL a=1;	while(p) { if(p&1) {	a*=b;	a%=mod;	}	b*=b;	b%=mod;	p=p>>1;	}	return a%mod;	}
	

FILE *fin=fopen("in.txt","r");
FILE *fout=fopen("out.txt","w");

LL in()
{
  char c;LL t=0,negative=1;
  c=gc;
  
  while((c<48||c>57)&&c!='-')c=gc;
  if(c=='-')
  {negative=-1;c=gc;}
  while(c>=48&&c<=57)
  {t=(t<<3)+(t<<1)+c-'0';c=gc;}
  return t*negative;
}

int compare(const void *a,const void *b)	//qsort(arr,n,sizeof(LL),compare)
{
  return (*(LL*)a-*(LL*)b);
}

int main()
{
	LL t,a,b,i,j,count=0,cases=0;
	LL matrix1[5][5],matrix2[5][5];
	
	fscanf(fin,"%lld",&t);
	
	while(1)
	{
		cases++;
		
		if(cases>t)
			break;
		
		fscanf(fin,"%lld",&a);
		
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				fscanf(fin,"%lld",&matrix1[i][j]);
		
		fscanf(fin,"%lld",&b);
		
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				fscanf(fin,"%lld",&matrix2[i][j]);
		
		count=0;
		vector <LL> val;
		
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				if(matrix1[a][i]==matrix2[b][j])
				{
					count++;
					val.pb(matrix1[a][i]);
				}
		
		if(count==1)
			fprintf(fout,"Case #%lld: %lld\n",cases,val[0]);
		
		else if(count==0)
			fprintf(fout,"Case #%lld: Volunteer cheated!\n",cases);
		
		else
			fprintf(fout,"Case #%lld: Bad magician!\n",cases);
			
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}