#include <iostream>
#include <vector>
#include <set>
#include <strings.h>

using namespace std;

int board[4][4];
int ans;

void read(){
	cin >> ans;
	ans--;
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 4; k++){
			cin >> board[j][k];
		}
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int possibilities[16];
		bzero(possibilities, sizeof(possibilities));
		for (int attempt = 0; attempt < 2; attempt++){
			read();
			for (int j = 0; j < 4; j++){
				possibilities[board[ans][j]-1]++;
			}
		}
		set<int> solutions;
		for (int j = 0; j < 16; j++){
			if (possibilities[j] == 2){
				solutions.insert(j+1);
			}
		}
		if (solutions.size() == 1){
			cout << "Case #" << (i + 1) << ": " << *solutions.begin() << endl; 
		} else if (solutions.size() == 0){
			cout << "Case #" << (i + 1) << ": Volunteer cheated!" << endl; 
		} else {
			cout << "Case #" << (i + 1) << ": Bad magician!" << endl; 
		}
	}
}
