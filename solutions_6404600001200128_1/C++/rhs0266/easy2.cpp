#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
typedef long long int T;
typedef double D;
typedef std::vector<int> vi;
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define NM 500005
#define MOD 1000000007
#define INF 0x7fffffff
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) ((x>0)?(x):(-x))
#pragma warning (disable:4996)
//FILE *in=stdin,*out=stdout;
FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
int n,ans;
int a[1005];

void step1(){
	ans=0;
	FOR (i,2,n){
		if (a[i]<a[i-1]) ans+=a[i-1]-a[i];
	}
	fprintf(out,"%d ",ans);
}
void step2(){
	int max=0;
	FOR (i,2,n){
		if (a[i-1]>=a[i]) max=MAX(max,a[i-1]-a[i]);
	}
	ans=0;
	FOR (i,1,n-1){
		ans+=MIN(a[i],max);
	}
	fprintf(out,"%d",ans);
}

int main(){
	int TT;
	si(TT);
	FOR (t,1,TT){
		fprintf(out,"Case #%d: ",t);
		si(n);
		FOR (i,1,n) si(a[i]);
		step1();
		step2();
		fprintf(out,"\n");
	}
	return 0;
}