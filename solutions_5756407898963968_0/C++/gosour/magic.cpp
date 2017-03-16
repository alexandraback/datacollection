#include<iostream>

using namespace std;

int main(){
	int T;
	int c = 1,i,j;
	cin>>T;
	while(T--){
		int ans1, cards1[4][4], ans2, cards2[4][4];
		int row1[4], row2[4];
		cin>>ans1;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++){
				cin>>cards1[i][j];
				if(i+1 == ans1)
					row1[j] = cards1[i][j];
			}
		cin>>ans2;	
		for(i=0;i<4;i++)
			for(j=0;j<4;j++){
				cin>>cards2[i][j];
				if(i+1 == ans2)
					row2[j] = cards2[i][j];
			}
	
		int count = 0;
		int val = 0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(row1[i] == row2[j]){
					val = row1[i];
					count++;
				}
		cout<<"Case #"<<c++<<": ";
		if(count == 1) cout<<val<<endl;
		if(count > 1) cout<<"Bad magician!"<<endl;
		if(count == 0) cout<<"Volunteer cheated!"<<endl;
	}
	return 0;
}

