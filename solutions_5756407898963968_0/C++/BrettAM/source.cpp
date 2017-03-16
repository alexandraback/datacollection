#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int pick[4];

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout<<"Error in Input"<<endl;
		return 0;
	}
	ifstream inFile;
	ofstream outFile;
	inFile.open(argv[1]);
	outFile.open("output.txt", ios::trunc | ios::out);
	if(!(inFile.is_open() && outFile.is_open()) ){
		cout << "can't open files"<<endl;
		return 0;
	}

	int N;
	inFile >> N;
	cout << "Running through " << N << " Iterations" << endl;
	for(int count=0; count<N; count++){
		int row, tmp, winner=0;
		inFile >> row;
		for (int i = 0; i < (row-1)*4; ++i) inFile >> tmp; //burn useless rows
		for (int i = 0; i < 4; ++i) inFile >> pick[i];
		for (int i = 0; i < (4-row)*4; ++i) inFile >> tmp; //burn useless rows

		inFile >> row;
		for (int i = 0; i < (row-1)*4; ++i) inFile >> tmp; //burn useless rows

		for (int i = 0; i < 4; ++i){
			inFile >> tmp;
			for (int i = 0; i < 4; ++i){
				if (tmp == pick[i]){
					if(winner != 0) winner = -1;
					else winner = tmp;
				}
			}
		}

		for (int i = 0; i < (4-row)*4; ++i) inFile >> tmp; //burn useless rows

		outFile << "Case #" << count+1 << ": ";

		if(winner == 0) outFile << "Volunteer cheated!";
		else if(winner == -1) outFile << "Bad magician!";
		else outFile << winner;
		outFile << "\n";

		cout << ".";
	}
	cout << "\n";
	inFile.close();
	outFile.close();
	return 0;
}
