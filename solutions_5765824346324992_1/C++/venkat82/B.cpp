#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	int uy=0;
	while (test--){
		uy++;
		cout<<"Case #"<<uy<<": "; 
		long long b,n;
		cin>>b>>n;
		long long a[b];
		for (int i = 0; i < b; i++) cin>>a[i];
		if(n<=b){
			cout<<n<<endl;
			continue;
		}
		n-=b;
		long long l=0,r=(long long)1e18;
		while (l<r){
		    long long mid=(l+r)>>1;
		    long long ans=0;
		    for (int i = 0; i < b; i++) ans+=mid/a[i];
		    if(ans<n) l=mid+1;
		    else r=mid; 
		}
		//cout<<l<<endl;
		long long ref=0;
		for (int i = 0; i < b; i++) ref+=(l-1)/a[i];
		long long diff=n-ref,p=0;
		//cout<<diff<<endl;
		for (int i = 0; i < b; i++) {
			if(l%a[i]==0) p++;
			if(p==diff){
				cout<<i+1<<endl;
				break;
			}
		}
		//cout<<"case over\n";
	}	
}