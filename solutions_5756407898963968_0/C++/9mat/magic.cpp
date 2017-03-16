#include <iostream>

using namespace std;

int main(){
	int T;
	int row, a;
	int set1[4], set2[4];
	
	cin>>T;
	
	for(int caseid = 1; caseid <= T; caseid++){
		cin>>row;
		for(int i = 1; i <= 4; i++)
			for(int j = 0; j< 4; j++){
				cin>>a;
				if(i == row) set1[j] = a;
			}
			
		cin>>row;
		for(int i = 1; i <= 4; i++)
			for(int j = 0; j< 4; j++){
				cin>>a;
				if(i == row) set2[j] = a;
			}
					
		int count = 0;
		int card = -1;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(set1[i] == set2[j]){
					card = set1[i];
					count++;
				}
				
		cout<<"Case #"<<caseid<<": ";
		if(count == 1) cout<<card<<endl;
		else if(count > 1) cout<<"Bad magician!"<<endl;
		else cout<<"Volunteer cheated!"<<endl;
	}
	return 0;
}