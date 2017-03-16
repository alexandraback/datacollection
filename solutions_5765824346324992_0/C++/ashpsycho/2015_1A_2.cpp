#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,n,i,j,k,b,bs[1001];
	cin>>t;
	for(te=1;te<=t;te++){
		cin>>b>>n;
		for(i=0;i<b;i++)cin>>bs[i];
		for(i=0,j=1;i<b;i++){
			j=(j*bs[i])/(__gcd(j,bs[i]));
		}
		for(i=k=0;i<b;i++)k+=(j/bs[i]);
		n=k+n%k;
		long long arr[1000];
		for(i=0;i<b;i++)arr[i]=0;
		for(i=0;i<n;i++){
			for(j=0,k=27000000000;j<b;j++)k=min(k,arr[j]);
			for(j=0;j<b;j++)if(arr[j]==k)break;
			arr[j]+=bs[j];
		}
		cout<<"Case #"<<te<<": "<<j+1<<"\n";
	}
	return 0;
}
