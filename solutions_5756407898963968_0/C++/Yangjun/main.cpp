#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	int count;
	cin >> count;

	for(int i=0; i<count; i++){
		//read data
		int row1, row2;
		cin >> row1;
		int matrix1[4][4];
		for(int r=0;r<4;r++){
			for(int l=0;l<4;l++){
				cin>>matrix1[r][l];
			}
		}
		cin>>row2;
		int matrix2[4][4];
		for(int r=0;r<4;r++){
			for(int l=0;l<4;l++){
				cin>>matrix2[r][l];
			}
		}
		//solve problem
		int sameCount=0; int sameElem=0;
		for(int l1=0;l1<4;l1++){
			for(int l2=0;l2<4;l2++){
				if(matrix1[row1-1][l1]==matrix2[row2-1][l2]){
					sameCount++;
					sameElem=matrix1[row1-1][l1];
				}
			}
		}
		if(sameCount==0){
			cout << "Case #" << i+1 <<": Volunteer cheated!\n";
		}else if(sameCount==1){
			cout << "Case #" << i+1 <<": " << sameElem << "\n";
		}else{
			cout << "Case #" << i+1 <<": Bad magician!\n";
		}
	}
	return 0;
}
