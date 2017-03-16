#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ncas=0,t,ord1,ord2;
	cin>>n;
	while(n--){
		cin>>ord1;
		vector<int> pos1,pos2;
		for(int i=1;i<=4;i++){
			for(int j=0;j<4;j++){
				cin>>t;
				if(i==ord1)pos1.push_back(t);
			}
		}
		cin>>ord2;
		for(int i=1;i<=4;i++){
			for(int j=0;j<4;j++){
				cin>>t;
				if(i==ord2)pos2.push_back(t);
			}
		}
		int can = 0,p=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(pos1[i]==pos2[j]){
					can = pos1[i];p++;break;
				}
			}
		}
		cout<<"Case #"<<++ncas<<": ";
		if(!p){
			cout<<"Volunteer cheated!"<<endl;
		}else if(p==1){
			cout<<can<<endl;
		}else if(p>1){
			cout<<"Bad magician!"<<endl;
		}
		
	}
}
