#include <bits/stdc++.h>
using namespace std;
int isok(long long x1,long long y1,long long x2,long long y2,long long x,long long y){
	if(x1==x2){
		if(x>x1) return 1;
		else if(x<x1) return -1;
		else return 0;
	}
	if(y1==y2){
		if(y>y1) return 1;
		else if(y<y1) return -1;
		else return 0;
	}
	if(x*(y2-y1)+y*(x1-x2)+x1*(y1-y2)+y1*(x2-x1)>0) return 1;
	else if(x*(y2-y1)+y*(x1-x2)+x1*(y1-y2)+y1*(x2-x1)<0) return -1;
	else return 0;
}
int main(){
	int test;
	scanf("%d",&test);
	int uy=0;
	while (test--){
		uy++;
		cout<<"Case #"<<uy<<": 	"<<endl; 
		long long n;
		cin>>n;
		pair<long long,long long> a[n];
		for (long long i = 0; i < n; i++) cin>>a[i].first>>a[i].second;
		for (long long i = 0; i < n; i++) {
			long long mini=(long long)1e9;
			for (long long j = 0; j < n; j++) {
				long long x=0,y=0;
				if(i==j) continue;
				for (long long k = 0; k < n; k++) {
					if(k==i || k==j) continue;
					if(isok(a[i].first,a[i].second,a[j].first,a[j].second,a[k].first,a[k].second)==1) x++;
					else if(isok(a[i].first,a[i].second,a[j].first,a[j].second,a[k].first,a[k].second)==-1) y++;
				}
				mini=min(mini,min(x,y));      		
			}
			if(mini==(long long)1e9) cout<<0<<endl;
			else cout<<mini<<endl;      	
		}      
	}   	
}