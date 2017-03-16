#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T; cin >> T;

	for(int t=0; t<T; t++){
		cout << "Case #" << t+1 << ": ";
		int first_row; cin >> first_row;
		int first_arrangement[4][4]; 
		for(int row=0; row<4; row++){
			for(int column=0; column<4; column++){
				cin >> first_arrangement[row][column];
			}
		}

		int second_row; cin >> second_row;
		int second_arrangement[4][4]; 
		for(int row=0; row<4; row++){
			for(int column=0; column<4; column++){
				cin >> second_arrangement[row][column];
			}
		}

		vector<int> candidates;

		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
					int a = first_arrangement[first_row-1][i];
					int b = second_arrangement[second_row-1][j];

					if(a == b){
						candidates.push_back(a);
					}
			}
		}

		if(candidates.size() > 1){
			cout << "Bad magician!" << endl;
		} else if(candidates.size() == 0){
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << candidates[0] << endl;
		}
	}

	return 0;
}
