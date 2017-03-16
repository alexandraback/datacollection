#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t,j,n,max,i;
	cin>>t;
	
	for(j=1;j<=t;++j){
		cin>>n;
		
		int a[n];
		
		for(i=0;i<n;++i) {
			cin>>a[i];
		}
		cout<<"Case #"<<j<<": ";
		
		if(n==2){
			if(a[0]==a[1]) {
				for(i=0;i<a[1];++i)	cout<<"AB ";
				cout<<"\n";
				continue;
			}
			
		}
		
		while(1){
			int flag=1,pos;
			for(i=0;i<n;++i){
				if(flag&&a[i]>1){
					max=a[i];
					pos=i;
					flag=0;
				}else if(a[i]>max) {
					max=a[i];pos=i;
				}
			}
			
			if(flag){
				int count=0;
				for(i=0;i<n;++i) {
					if(a[i]==1) count++;
				}
				int k=0;
				for(i=0;i<n;i++){
					if(k<=count-3&&a[i]==1){
						cout<<char(i+'A')<<" ";
						k++;
					}else if(a[i]==1){
						cout<<char(i+'A');
					} 
				}
				
				break;
			}else{
				a[pos]--;
				cout<<char(pos+'A')<<" ";
			}
			
		}
		cout<<"\n";
	}
	
	return 0;
}
