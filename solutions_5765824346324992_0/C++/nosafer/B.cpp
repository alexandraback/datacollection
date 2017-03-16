#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
#define MAXNNUM 10000000
int mapn[MAXNNUM]={0};
int gcdnum(int a,int b){
	if(a%b==0)return b;
	return gcdnum(b,a%b);
}
int main(int argc,char **argv)
{
	int cnt,n,m;
	ifstream in(argv[0]);
	in >> cnt;
	for(int i=1;i<=cnt;i++){
		int brr[10],sum=1;
		int ncnt[10]={0};
		scanf("%d %d",&n,&m);
		for(int j=0;j<n;j++){
			scanf("%d",&brr[j]);
			sum*=brr[j];
		}
		int rmod=gcdnum(brr[0],brr[1]);int nmod=rmod;
		for(int j=2;j<n;j++){
			rmod=gcdnum(brr[j],nmod);
			nmod=rmod;
		}
		sum=sum/rmod;int nsum=0;
		for(int j=0;j<n;j++){
			nsum+=(sum/brr[j]);
		}
		for(int j=1;j<=nsum;j++){
			int maxnum=-1,res_val=-1;
			for(int k=0;k<n;k++){
				int nvalnum=(ncnt[k])*brr[k];
				if(maxnum==-1){
					res_val=nvalnum;
					maxnum=k+1;
				}
				else if(res_val>nvalnum){
					res_val=nvalnum;
					maxnum=k+1;
				} 
			}
			ncnt[maxnum-1]+=1;
			mapn[j]=maxnum;
		}
		int result = m%nsum;
		if (result==0){result=nsum;}
		cout<<"Case #"<<i<<": "<<mapn[result]<<endl;
	}
} 
