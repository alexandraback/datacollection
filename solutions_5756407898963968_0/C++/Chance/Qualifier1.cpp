#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(const vector<vector<int> >& cp1, const vector<vector<int> >& cp2, int row1, int row2, int caseNum) {
	bool found = false;
	bool badMagician = false;
	int foundNum;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (cp1[row1][i] == cp2[row2][j]) {
				if (found) {
					badMagician = true;
				}
				else {
					found = true;
					foundNum = cp1[row1][i];
				}
			}
		}
	}
	cout << "Case #" << caseNum << ": ";
	if (!found) {
		cout << "Volunteer cheated!" << endl;
	}
	else if (badMagician) {
		cout << "Bad magician!" << endl;
	}
	else {
		cout << foundNum << endl;
	}
	return;
}

int main(void){
	int numCases;
	cin >> numCases;
	for (int ii = 0; ii < numCases; ++ii) {
		vector<vector<int >> card_placement1(4);
		vector<vector<int >> card_placement2(4);
		int guess1;
		cin >> guess1;
		for (int i = 0; i < card_placement1.size(); ++i) {
			card_placement1[i].resize(4);
			for (int j = 0; j < 4; ++j) {
				cin >> card_placement1[i][j];
			}
		}
		
		int guess2;
		cin >> guess2;
		for (int i = 0; i < card_placement2.size(); ++i) {
			card_placement2[i].resize(4);
			for (int j = 0; j < 4; ++j) {
				cin >> card_placement2[i][j];
			}
		}
		
		solve(card_placement1, card_placement2, guess1-1, guess2-1, ii+1);
	}
	return 0;
}