#include <bits/stdc++.h>

using namespace std;


int main(){

	int t,ca = 1;
	cin>>t;
	while(t--){
		
		int n,b;
		cin>>b>>n;
		long long v[b];
		for(int i = 0;i<b;i++)
			cin>>v[i];
		long long lo = 1,hi = 1000000000000000;
		while(lo<hi){
			long long mid = (lo + hi)/2;
			long long qtd  = 0;
			
			for(int i = 0;i<b;i++)
				qtd+=(ceil(mid/(double)v[i])  + (mid%v[i] == 0));
			
		//	cout<<mid<<" "<<qtd<<endl;
			if(qtd<n)
				lo = mid+1;
			else
				hi = mid;
		}
		long long qtd = 0;
		for(int i = 0;i<b;i++)
			qtd+=ceil(lo/(double)v[i]);
		if(qtd == n){
			lo--;
			qtd = 0;
			for(int i = 0;i<b;i++)
			qtd+=ceil(lo/(double)v[i]);
		}
		printf("Case #%d: ",ca++);
		for(int i = 0;i<b;i++){
			if(lo%v[i] == 0){
				qtd++;
				if(qtd == n){
					cout<<i+1;
					break;
				}
			}
		}
		//cout<<n<<" "<<qtd<<endl;
		cout<<endl;
	}
	return 0;
}