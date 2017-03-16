#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string basePath = "../data/2014_QR";
	string baseName = "A-small-attempt0";
	string inFile = basePath + "/" + baseName + ".in";
	string outFile = basePath + "/" + baseName + "-out.txt";
	ifstream ifs(inFile.c_str(), ifstream::in);
	ofstream ofs(outFile.c_str(), ofstream::out);

	int numTest(0), idxTest(1);
	ifs >> numTest;
	cout << numTest << endl;

	while(idxTest <= numTest) {
		int rowIdx1, rowIdx2, numMatch(0), idxMatch(0);
		int card1[4][4];
		int card2[4][4];
		
		ifs >> rowIdx1;		
		for (int i = 0; i < 4; ++i) 
			for (int j = 0; j < 4; ++j)
				ifs >> card1[i][j];
		
		ifs >> rowIdx2;
		for (int i = 0; i < 4; ++i) 
			for (int j = 0; j < 4; ++j)
				ifs >> card2[i][j];
		
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; ++j)
				if (card1[rowIdx1-1][i] == card2[rowIdx2-1][j]) {
					numMatch++;
					idxMatch = i;
				}

		if (0 == numMatch)
			ofs << "Case #" << idxTest << ": " << "Volunteer cheated!" << endl;
		else if (1 == numMatch)
			ofs << "Case #" << idxTest << ": " << card1[rowIdx1-1][idxMatch] << endl;
		else
			ofs << "Case #" << idxTest << ": " << "Bad magician!" << endl;
		
		++idxTest;
	}

	ifs.close();
	ofs.close();
	getchar();
	return 0;
}