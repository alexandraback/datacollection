#include<iostream>
#include<string>
#include<algorithm>
#include<assert.h>
using namespace std;
	
int main(){
	int TT;
	cin>>TT;
	long long int ans=0;
	long long int b;
	long long int n;
	long long int a[2000];
	


	for(int T=1;T<=TT;++T){
		
		cin>>b>>n;
		for(int i=0;i<b;++i){
			cin>>a[i];
		}
		long long int upper=1000000000000000; //TODO 
		long long int lower=0;
		if(n<=b){
			ans=n;
			cout<<"Case #"<<T<<": "<<ans<<"\n";
			continue;
		}
		while(lower<upper-1){
			long long int mi=(upper+lower)/2;
			long long int sum=0;
			for(int i=0;i<b;++i){
				sum+=mi/a[i]+1;
			}
			if(sum>=n){
				upper=mi;
			}
			else{
				lower=mi;
			}
		}

		if(upper-lower!=1){
			cerr<<"!!!!!!"<<endl;
		}
		assert(upper-lower==1);
		long long int sum=0;
		for(int i=0;i<b;++i){
			sum+=lower/a[i]+1;
		}
		long long int rk = n-sum;
		for(int i=0;i<b;++i){
			if(upper%a[i]==0){
				--rk;
				if(rk==0){
					ans=i+1;
					break;
				}
			}
		}
		//cout<<upper<<endl;
		cout<<"Case #"<<T<<": "<<ans<<"\n";


	}
	return 0;
}
