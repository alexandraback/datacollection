#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001
int n,a[MAX];

int main(){
	int t,i,j,k,b,u;
	long long s,m;
	cin>>t; for (u=0; u<t; u++){
		cin>>n; for (i=0; i<n; i++) cin>>a[i];
		b=0; s=m=0;
		for (i=1; i<n; i++) s+=max(0,a[i-1]-a[i]);
		for (i=1; i<n; i++) b=max(b,a[i-1]-a[i]);
		for (i=0; i<n-1; i++) m+=min(b,a[i]);
		cout<<"Case #"<<(u+1)<<": "<<s<<" "<<m<<endl;
	}
	return 0;
}
