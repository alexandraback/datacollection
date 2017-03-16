#include<iostream>
using namespace std;
int main(){
	int TT;
	cin>>TT;
	int a;
	int b;
	int mp[17];
	int c;
	int d;
	for(int T=1;T<=TT;++T){
		for(int i=0;i<17;++i)
			mp[i]=0;
		cin>>a;	
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				cin>>c;
				if(i==a-1)
					mp[c]++;
			}
		}
		cin>>a;	
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				cin>>c;
				if(i==a-1)
					mp[c]++;
			}
		}
		b=0;
		for(int i=1;i<=16;++i){
			if(mp[i]>1){
				++b;
				d=i;
			}
		}
		if(b==1){
		cout<<"Case #"<<T<<": "<<d<<"\n";
		}
		else if(b>1){
		cout<<"Case #"<<T<<": Bad magician!\n";

		}
		else{
		cout<<"Case #"<<T<<": Volunteer cheated!\n";
		}
	}
	return 0;
}
