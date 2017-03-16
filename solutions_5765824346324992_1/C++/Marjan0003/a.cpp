#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include <queue>
#include <math.h>    

using namespace std;


int main(){
	ifstream in("in");
	int casenum=0;
	in>>casenum;
	for (int c=0;c<casenum;c++){
		int b,n;
		in>>b>>n;
		int wlist[1010];
		int mwait=0;
		double nerkh=0;
		for(int i=1;i<=b;i++){
			int m;
			in>>m;
			wlist[i]=m;
			nerkh+=(double)1/m;
			if(m>mwait)
				mwait=m;
		}
		long long int at=ceil((n-1)/nerkh);
		//cout<<"a:"<<at<<endl;
		int ans=-1;
		for(long long int a=at-mwait;a<at+mwait;a++){
			if(a<0)
				continue;
			if(ans!=-1)
				break;
			int nmin=0;
			for(int i=1;i<=b;i++){
				if((a)%wlist[i]==0){
					nmin++;
				}
			}
			int nsofar=0;
			for(int i=1;i<=b;i++){
				nsofar+=ceil((double)a/wlist[i]);
			}
			//cout<<a<<":"<<nsofar<<endl;
			if(!(nsofar+nmin>=n && nsofar<n) )
				continue;
			for(int i=1;i<=b;i++){
				if(a%wlist[i]==0){
					nsofar++;
					
					if(nsofar==n){
						//cout<<"real a:"<<a<<endl;
						ans=i;
						break;
					}
				}
			}
		}
		cout<<"Case #"<<c+1<<": "<<ans<<endl;
		/*if(ans!=-1)
			cout<<ans<<endl;*/
	}
	
	return 0;
	
}
