#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x,y,t,te,n,i,j,k,b,bs[1001],arr[1001];
	cin>>t;
	for(te=1;te<=t;te++){
		cin>>b>>n;
		for(i=0;i<b;i++)cin>>bs[i];
		j=0;
		n--;
		k=100001LL*n;
		while(j<k){
			i=(j+k)/2;
			for(x=y=0;x<b;x++)
				y+=(1+(i/bs[x]));
			if(y==n)break;
			if(y<n)j=i+1;
			else k=i;
		}
		for(x=y=0;x<b;x++)
			y+=(1+(i/bs[x]));
		while(y<n){
			i++;
			for(x=y=0;x<b;x++)
				y+=(1+(i/bs[x]));
		}
		while(y>n){
			i--;
			for(x=y=0;x<b;x++)
				y+=(1+(i/bs[x]));
		}
		for(j=0;j<b;j++)
			arr[j]=bs[j]+(i/bs[j])*bs[j];
		for(k=y+1;k<=(n+1);k++){
			for(j=i=0;j<b;j++)if(arr[i]>arr[j])i=j;
			arr[i]+=bs[i];
		}
		if((n+1)<=(b))i=n;
		cout<<"Case #"<<te<<": "<<(i+1)<<"\n";
	}
	return 0;
}

