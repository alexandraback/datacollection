#include <bits/stdc++.h>
using namespace std;
int main(){
	long long  t,te,i,j,k,n,m,arr[1000],ans1,ans2;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>n;
		ans1=ans2=0;
		for(i=0;i<n;i++)cin>>arr[i];
		for(i=0;i<(n-1);i++)ans1+=max(0LL,arr[i]-arr[i+1]);
		for(i=m=0;i<(n-1);i++)m=max(m,arr[i]-arr[i+1]);
		for(i=0;i<(n-1);i++){
			if(arr[i]<m)ans2+=arr[i];
			else ans2+=m;
		}
		cout<<"Case #"<<(te+1)<<": "<<ans1<<" "<<ans2<<"\n";
	}
}