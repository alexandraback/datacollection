#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

int a[27];


int main(){
	int t;

	cin>>t;
	int j=1;

	while(t--){
		int sum=0;
		int n;
		cin>>n;
		int i;
		for(i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int m1,m2;
		if(a[1]>a[2]){
			m1=1;
			m2=2;
		}else{
			m1=2;
			m2=1;
		}
		char c='A';

		cout<<"Case #"<<j<<": ";
		for(i=3;i<=n;i++){
			if(a[i]>a[m1]){
				m2=m1;
				m1=i;
			}else if(a[i]>a[m2]){
				m2=i;

			}
		}
		
		/*

		cout<<"///////////"<<endl;
		for(i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}cout<<"///////////////"<<endl;	*/
		while(a[m1]!=0||a[m2]!=0){
			if(a[m1]==1&&a[m2]==0){
				cout<<"error"<<endl;
				break;
			}

		/*cout<<"///////////"<<endl;
		for(i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}cout<<"///////////////"<<endl;	

		*/

			if(a[m1]==a[m2]+1){
				a[m1]-=1;
				sum-=1;
				char x=c+m1-1;
				cout<<x<<" ";
			}else if(a[m1]>=a[m2]+2){
				a[m1]-=2;
				sum-=2;
				char x=c+m1-1;
				cout<<x<<x<<" ";

			}else if(a[m1]==a[m2]&&a[m1]!=1){
				a[m1]-=1;
				a[m2]-=1;
				sum-=2;
				char x=c+m1-1;
				char y=c+m2-1;
				cout<<x<<y<<" ";
			}else if(a[m1]==a[m2]&&a[m1]==1){
				if(sum==2){
					sum-=2;
					a[m1]--;
					a[m2]--;
					char x=c+m1-1;
					char y=c+m2-1;
					cout<<x<<y<<" ";
				}else{
					a[m1]-=1;
					sum-=1;
					char x=c+m1-1;
					cout<<x<<" ";
				}

			}




			if(a[1]>a[2]){
			m1=1;
			m2=2;
			}else{
				m1=2;
				m2=1;
			}
			

			for(i=3;i<=n;i++){
				if(a[i]>a[m1]){
					m2=m1;
					m1=i;
				}else if(a[i]>a[m2]){
					m2=i;

				}
			}


		}cout<<endl;


		j++;
	}




	return 0;
}