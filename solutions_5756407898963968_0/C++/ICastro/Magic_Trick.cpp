#include <iostream>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		int row1;
		cin >> row1;
		row1--;
		int mat1[4][4];
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j){
				cin >> mat1[i][j];
			}
		}
		int row2;
		cin >> row2;
		row2--;
		int mat2[4][4];
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j){
				cin >> mat2[i][j];
			}
		}
		int cont = 0;
		int resp;
		for (int j1 = 0; j1 < 4; ++j1){
			for (int j2 = 0; j2 < 4; ++j2){
				//cout << mat1[row1][j1] << " " << mat2[row2][j2] << endl;
				if (mat1[row1][j1] == mat2[row2][j2]){
					cont += 1;
					resp = mat1[row1][j1];
				}
			}
		}
		if (cont == 0){
			cout << "Case #" << k+1 << ": " << "Volunteer cheated!" << endl;
		} else if (cont > 1){
			cout << "Case #" << k+1 << ": " << "Bad magician!" << endl;
		} else{
			cout << "Case #" << k+1 << ": " << resp << endl;
		}
	}
	return 0;
}
