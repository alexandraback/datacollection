#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("A-small-attempt0.out");

	int T; fin >> T;

	for(int t = 0; t < T; t++){
		vector<int> first;
		vector<int> second;
		int row1, row2; fin >> row1;

		int card;
		for(int k = 0; k < 16; k++){
			fin >> card;
			if((k/4)+1 == row1) first.push_back(card);
		}

		fin >> row2;
		for(int k = 0; k < 16; k++){
			fin >> card;
			if((k/4)+1 == row2) second.push_back(card);
		}

		sort(first.begin(), first.end());
		sort(second.begin(), second.end());

		vector<int> result (8);
		vector<int>::iterator it = set_intersection(first.begin(), first.end(), second.begin(), second.end(), result.begin());
		result.resize(it-result.begin());

		fout << "Case #" << t+1 << ": ";
		if(result.size() == 1) fout << result.at(0) << endl;
		else if(result.size() > 1) fout << "Bad magician!" << endl;
		else fout << "Volunteer cheated!" << endl;
	}

	return 0;
}