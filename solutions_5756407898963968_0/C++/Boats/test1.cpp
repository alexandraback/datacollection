#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input("A-small-attempt1.in");
	ofstream output("ans.out");
	int t, a, b, result, resultnum;
	int card[4][4], team[4];
	input >> t;
	for (int i=0; i<t; i++) {
		result = 0;
		input >> a;
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				input >> card[j][k];
				if (j+1==a) {
					team[k] = card[j][k];
				}
			}
		}
		//for (int j=0; j<4; j++) output << team[j] << endl;
		input >> b;
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				input >> card[j][k];
				if (j+1==b) {
					for (int l=0; l<4; l++)
						if (team[l]==card[j][k]) {
							result++;
							resultnum = team[l];
							break;
						}
				}
			}
		}
		output << "Case #" << i+1 << ": ";
		if (result == 0) output << "Volunteer cheated!\n";
		else if (result > 1) output << "Bad magician!\n";
		else output << resultnum << endl;
	}
}