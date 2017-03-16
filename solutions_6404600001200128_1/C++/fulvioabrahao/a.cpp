#include <bits/stdc++.h>

using namespace std;


int main(){

	int t,ca = 1;
	cin>>t;
	while(t--){
		printf("Case #%d: ",ca++);
		int n;
		cin>>n;
		long long r1 = 0, r2 = 0;
		long long v[n];
		for(int i = 0;i<n;i++)
			cin>>v[i];
		long long maior = 0;
		for(int i = 1;i<n;i++){
			if(v[i]<v[i-1])
				r1+=(v[i-1]-v[i]);
			maior = max(v[i-1]-v[i],maior);
		}
		for(int i = 0;i<n-1;i++){
			r2+=min(maior,v[i]);
		}
		printf("%lld %lld\n",r1,r2 );
	}
	return 0;
}