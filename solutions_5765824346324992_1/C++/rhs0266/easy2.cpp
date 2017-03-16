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
T N;
struct LIST{
	int num;
	T x;
	bool operator()(LIST A,LIST B){
		if (A.x!=B.x) return A.x>B.x;
		return A.num<B.num;
	}
}a[NM],b[NM];
int n;
void input(){
	fscanf(in,"%d %lld",&n,&N);
	FOR (i,1,n) fscanf(in,"%lld",&a[i].x),a[i].num=i;
	//std::sort(a+1,a+1+n,LIST());
}
T count(T time){
	T cnt=0;
	FOR (i,1,n){
		cnt+=time/a[i].x;
	}
	return cnt+n;
}
void pro(){
	T left=0,right=200000000000000ll,mid,cnt,min=200000000000000ll;
	while (left<=right){
		mid=(left+right)/2;
		cnt=count(mid);
		if (cnt>=N){
			right=mid-1;
			min=MIN(min,mid);
		}else left=mid+1;
	}
	cnt=count(min);
	T cnt2=0;
	FOR (i,1,n){
		cnt2+=min/a[i].x;
	}

	FOR (i,1,n){
		b[i].x=min%a[i].x;
		b[i].num=i;
	}
	std::sort(b+1,b+1+n,LIST());
	FOR (i,1,n){
		cnt2++;
		if (cnt2==N){
			fprintf(out,"%d\n",b[i].num);
			return;
		}
	}
}
int main(){
	int TT;
	si(TT);
	FOR (t,1,TT){
		fprintf(out,"Case #%d: ",t);
		input();
		pro();
	}
	return 0;
}