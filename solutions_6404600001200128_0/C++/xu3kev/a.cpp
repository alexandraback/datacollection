#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
	
int main(){
	int TT;
	cin>>TT;
	int ans=0;


	int n;
	int a[2000];
	for(int T=1;T<=TT;++T){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		int ans1=0;
		int md=0;
		for(int i=1;i<n;++i){
			if(a[i-1]>a[i]){
				ans1+=a[i-1]-a[i];
				if(a[i-1]-a[i]>md){
					md=a[i-1]-a[i];
				}
			}
		}
		int ans2=0;

		for(int i=1;i<n;++i){
			if(a[i-1]<md)
				ans2+=a[i-1];
			else
				ans2+=md;
		}
		
		cout<<"Case #"<<T<<": "<<ans1<<" "<<ans2<<"\n";


	}
	return 0;
}
