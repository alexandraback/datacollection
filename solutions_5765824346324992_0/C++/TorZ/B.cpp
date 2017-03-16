#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 10000000
int mapn[MAXN]={0};
int GCD(int a,int b){
	if(a%b==0)return b;
	return GCD(b,a%b);
}
int main(int argc,char **argv)
{
    freopen("A.in", "r", stdin);
	freopen("B1.out", "w", stdout);
	int cnt,n,m;
	cin >> cnt;
	for(int i=1;i<=cnt;i++){
		int brr[10],sum=1;
		
		int ncnt[10]={0};
		scanf("%d %d",&n,&m);
		for(int j=0;j<n;j++){
			scanf("%d",&brr[j]);
			sum*=brr[j];
		}
		int rmod=GCD(brr[0],brr[1]);int nmod=rmod;
		for(int j=2;j<n;j++){
			rmod=GCD(brr[j],nmod);
			nmod=rmod;
		}
		sum=sum/rmod;int nsum=0;
		for(int j=0;j<n;j++){
			nsum+=(sum/brr[j]);
		}
		for(int j=1;j<=nsum;j++){
			int maxn=-1,res_val=-1;
			for(int k=0;k<n;k++){
				int nval=(ncnt[k])*brr[k];
				if(maxn==-1){
					res_val=nval;maxn=k+1;
				}
				else if(res_val>nval){
					res_val=nval;maxn=k+1;
				} 
			}
			ncnt[maxn-1]+=1;mapn[j]=maxn;
		}
		int res_xx=m%nsum;if(res_xx==0){res_xx=nsum;}
		printf("Case #%d: %d\n",i, mapn[res_xx]); 
	}
} 
