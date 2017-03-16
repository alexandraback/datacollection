//SMALL

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
string p[300];
char l[300];
int r[300][300];
int N;

int found(char x,int ML){
	for(int i=ML-1;i>=0;--i){
		if(l[i]==x)return i;
	}
	return -1;
}

int diff(int x,int y){
	return (x-y>0)?(x-y):(y-x);
}

int main(){
	int TC,T,input;
	cin>>TC;
	for(T=1;T<=TC;++T){
		printf("Case #%d:",T);
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>p[i];
		}
		int ML=0;bool impossible=false;
		for(int i=0;i<p[0].size();++i){
			int index;
			if((index=found(p[0][i],ML))==-1){l[ML]=p[0][i];++ML;}
			else if(index!=ML-1){l[ML]=p[0][i];++ML;}
		}
		//for(int i=0;i<ML;++i){cout<<l[i]<<" ";}cout<<endl;
		for(int i=0;i<N;++i){for(int j=0;j<ML;++j)r[i][j]=0;}
		for(int i=0;i<N;++i){
			int pointer=0;
			for(int j=0;j<p[i].size();++j){
				/*int index=found(p[i][j],ML);
				if(index==-1){impossible=true;break;}
				++r[i][index];*/
				if(l[pointer]==p[i][j])++r[i][pointer];
				else if(l[pointer]!=p[i][j])
				{
					if(l[++pointer]==p[i][j]){++r[i][pointer];}
					else{impossible=true;break;}
				}
			}
			for(int j=0;j<ML;++j){
				if(r[i][j]==0){impossible=true;break;}
			}
			/*for(int j=0;j<ML;++j){
				if(r[i][j]==0)impossible=true;break;
			}*/
			if(impossible)break;
		}
		if(impossible){printf(" Fegla Won\n");continue;}
		//printf("\n");
		int R[300];for(int z=0;z<ML;++z){R[z]=999999999;}
		for(int i=0;i<ML;++i){
			int min=99999999;int max=-1;
			for(int j=0;j<N;++j){
				if(min>r[j][i])min=r[j][i];
				if(max<r[j][i])max=r[j][i];
			}
			//printf("for %d;min:%d max:%d\n",i,min,max);
			for(int j=min;j<=max;++j){
				int res=0;
				for(int k=0;k<N;++k){
					res+=diff(j,r[k][i]);
					//printf("for j= %d diff: %d",j,diff(j,r[i][]))
				}
				if(R[i]>res)R[i]=res;
			}
		}
		long long Total=0;
		for(int i=0;i<ML;++i){Total+=(long long)R[i];}
		printf(" %lld\n",Total);
		//for(int i=0;i<N;++i){for(int j=0;j<ML;++j)cout<<r[i][j]<<" ";cout<<endl;}
	}
	return 0;
}