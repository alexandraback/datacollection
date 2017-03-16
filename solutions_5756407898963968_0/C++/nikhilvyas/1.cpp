#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int g=0;g<t;g++){
		int r;
		cin>>r;
		int a[4];
		int z;
		for(int y=0;y<r-1;y++){
			cin>>z>>z>>z>>z;
		}
		cin>>a[0]>>a[1]>>a[2]>>a[3]; 
		for(int y=0;y<4-r;y++){
			cin>>z>>z>>z>>z;
		}
		cin>>r;
		for(int y=0;y<r-1;y++){
			cin>>z>>z>>z>>z;
		}
		int x=0;
		int y;
		for(int i=0;i<4;i++){
			cin>>z;
			if(z==a[0]){ x++; y=a[0];}
			if(z==a[1]){ x++; y=a[1];}
			if(z==a[2]){ x++; y=a[2];}
			if(z==a[3]){ x++; y=a[3];}
		}
		for(int y=0;y<4-r;y++){
			cin>>z>>z>>z>>z;
		}
		if(x==0) cout<<"Case #"<<g+1<<": "<<"Volunteer cheated!"<<endl;
		if(x==1) cout<<"Case #"<<g+1<<": "<<y<<endl;
		if(x>=2) cout<<"Case #"<<g+1<<": "<<"Bad magician!"<<endl;
	}
}
