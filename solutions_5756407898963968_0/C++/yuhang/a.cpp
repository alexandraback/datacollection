#include<iostream>
using namespace std;


int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int s=0,n;
		cin>>n;
		for(int j=1;j<=4;j++)
			for(int k=0;k<4;k++){
				int t;
				cin>>t;
				if(n==j)
					s|=1<<t;
			}
		int r=0;
		cin>>n;
		for(int j=1;j<=4;j++)
			for(int k=0;k<4;k++){
				int t;
				cin>>t;
				if(n==j&&(s&(1<<t))!=0)
					if(r==0)
						r=t;
					else
						r=-1;
			}
		cout<<"Case #"<<i<<": ";
		if(r==-1)
			cout<<"Bad magician!"<<endl;
		else if(r==0)
			cout<<"Volunteer cheated!"<<endl;
		else
			cout<<r<<endl;
	}	
	return 0;	
}


