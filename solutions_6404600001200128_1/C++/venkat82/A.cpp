#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d",&test);
	int k=0;
	while (test--){
		k++;
		//Case #1:
		cout<<"Case #"<<k<<": "; 
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; i++) cin>>a[i];
		int ans1=0,maxi=0,ans2=0;
		for (int i = 1; i < n; i++) {
			if(a[i]<a[i-1]) {
				ans1+=a[i-1]-a[i];
				maxi=max(maxi,a[i-1]-a[i]);
			}
		}
		for (int i = 0; i < n-1; i++) ans2+=min(maxi,a[i]); 
		cout<<ans1<<" "<<ans2<<endl;
	}	
}