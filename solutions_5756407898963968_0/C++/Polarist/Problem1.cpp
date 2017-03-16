#include "Problem1.h"

#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include <list>
#include <set>

using namespace std;


int solveProblem(int r1, int r2, int round1[16], int round2[16]){
	list<int> possibleAnswers;
	list<int> answers;

	for (int i = 0; i < 4; i++){
		possibleAnswers.push_back(round1[4 * (r1 - 1) + i]);
	}

	for (int i = 0; i < 4; i++){
		for (auto iter = possibleAnswers.begin(); iter != possibleAnswers.end(); iter++){
			if (*iter == round2[4 * (r2-1) + i]){
				answers.push_back(*iter);
			}
		}
	}
	
	if (answers.size() == 0){
		return 0;
	}
	if (answers.size() > 1){
		return -1;
	}
	return answers.front();

}


int main(int argc, char ** argv){
	ifstream in("problem1.in");
	ofstream out("problem1.out");
	int count = 0;
	in >> count;
	cout << count;
	int r1, r2, round1[16], round2[16];

	for (int i = 0; i < count; i++){
		// Get inputs
		in >> r1;
		for (int j = 0; j < 16; j++){
			in >> round1[j];
		}
		in >> r2;
		for (int j = 0; j < 16; j++){
			in >> round2[j];
		}

		int answer = solveProblem(r1, r2, round1, round2);

		out << "Case #" << i+1 << ": ";
		if (answer == -1) out << "Bad magician!";
		else if (answer == 0) out << "Volunteer cheated!";
		else {
			assert(answer >= 1 && answer <= 16);
			out << answer;
		}
		out << endl;
	}


	return 0;
}