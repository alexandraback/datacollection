#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001
long long n,b,m[MAX];

int main(){
	int t,u,i,j,k;
	long long tlo=0,thi,tmid,slo,s;
	cin>>t; for (u=0; u<t; u++){
		cin>>b>>n; n--;
		for (i=0; i<b; i++) cin>>m[i];
		tlo=0; thi=1000000000LL*1000000LL+1;
		slo=0;
		while(tlo<thi-1){
			tmid=(tlo+thi)/2; 
			s=0; for (i=0; i<b; i++) s+=(tmid+m[i]-1)/m[i];
			if (s<=n){
				tlo=tmid; slo=s;
			}
			else thi=tmid;
		}
		n-=slo;
		for (i=0; i<b; i++) if (tlo%m[i]==0) if (n--==0) break;
		cout<<"Case #"<<(u+1)<<": "<<(i+1)<<endl;
	}
	return 0;
}
