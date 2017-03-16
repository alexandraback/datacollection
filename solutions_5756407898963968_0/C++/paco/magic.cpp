#include<iostream>

using namespace std;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		int row1,row2;
		int grid1[4][4],grid2[4][4];
		cin>>row1;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				cin>>grid1[i][j];
		cin>>row2;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				cin>>grid2[i][j];
				
		cout<<"Case #"<<n+1<<": ";
		
		int found=0;
		int number=-1;
		row1--;row2--;
		for(int i=0; i<4; i++) {
			for(int j=0;j<4;j++) {
				if(grid1[row1][i] == grid2[row2][j]) {
					number=grid1[row1][i];
					found++;
				}
			}
		}
		if(found==0) 
			cout<<"Volunteer cheated!"<<endl;
		else if(found>1) 
			cout<<"Bad magician!"<<endl;
		else
			cout<<number<<endl;
		
	}

	return 0;
}
