#include <bits/stdc++.h>

using namespace std;
int ff[16]={0,0,0,0,0,0,0,0,2,4,7,10,13,16,20,24};
int ti[15]={0,0,0,0,0,0,0,0,33,6,9,12,15,18,22};
int tf[12]={0,0,0,0,0,0,2,4,7,10,13,17};
int tt[9]={0,0,0,0,0,3,6,8,12};
int main(){
	int tc;cin>>tc;
	int i=0;
	while(tc-->0){
		i++;
		cout<<"Case #"<<i<<": ";
		int n,m,k;cin>>n>>m>>k;
		if(n>m)swap(n,m);
		if(n==4&&m==4){
			cout<<ff[k-1]<<endl;
		}else if(n==3&&k==5){
			cout<<ti[k-1]<<endl;
		}else if(n==3&&k==4){
			cout<<tf[k-1]<<endl;
		}else if(n==3&&k==3){
			cout<<tt[k-1]<<endl;
		}else if(n==2){
			if(k<=m)cout<<0<<endl;
			else if(k==m+1)cout<<2<<endl;
			else if(k==m+2)cout<<4<<endl;
			else cout<<(k-m-2)*3+4<<endl;
		}else{
			if(m%2==1){
				if(k<=(m+1)/2)cout<<0<<endl;
				else cout<<(k-(m+1)/2)*2<<endl;
			}else{
				if(k<=m/2)cout<<0<<endl;
				else if(k==m/2+1)cout<<1<<endl;
				else cout<<(k-m/2-1)*2+1<<endl;
			}
		}
	}
	return 0;
}
