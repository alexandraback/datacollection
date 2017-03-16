#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

int T;

int main(){
	fin>>T;
	for(int z=1;z<=T;z++){
	
	bool num[17]={0};
	
	int row;
	
	fin>>row;
	
	for(int i=1;i<=4;i++){
		int temp[5];
		for(int j=1;j<=4;j++)fin>>temp[j];
		if(i==row)for(int j=1;j<=4;j++)num[temp[j]]=1;
	}
	
	fin>>row;
	
	int ans=0,counter=0;
	for(int i=1;i<=4;i++){
		int temp[5];
		for(int j=1;j<=4;j++)fin>>temp[j];
		
		if(i==row){
			for(int j=1;j<=4;j++)if(num[temp[j]]==1){
				if(counter==0)ans=temp[j];
				counter++;
			}
		}
	}	
	
	fout<<"Case #"<<z<<": ";
	
	if(counter==0){
		fout<<"Volunteer cheated!"<<endl;
	}
	else if(counter==1){
		fout<<ans<<endl;
	}
	else{
		fout<<"Bad magician!"<<endl;
	}
	
	
	}
	return 0;
}
