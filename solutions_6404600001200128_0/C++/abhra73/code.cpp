#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int eval(int n,int l){
	int ret = 1e9,tmp,v,d;
	
	for(int i=0;i<=10000;i++){
		tmp=0; v=i;
		for(int j=1;j<n;j++){
			d=arr[j-1]-arr[j];
			if(d>v){
				tmp = 1e9;
				break;
			} 
			else if(d==v) tmp+=v;
			else tmp+=min(v,arr[j-1]);
		}
		ret=min(ret,tmp);
//		cout<<i<<" "<<ret<<endl;
	}
	return ret;
}
int main() {
	int t,n,a1,a2,cas=0;
	scanf("%d",&t);
	while(t--){
		printf("Case #%d: ",++cas);
		a1=a2=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		
		for(int i=1;i<n;i++){
			if(arr[i] < arr[i-1]) a1 += (arr[i-1]-arr[i]);
		}
		
		a2=eval(n,arr[0]);
		printf("%d %d\n",a1,a2);
	}
	return 0;
}