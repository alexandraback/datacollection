#include <iostream>

#define MAX 4

using namespace std;

int choice[MAX];

bool inChoice(int val) {
	for(int i = 0; i < MAX; i++) if(choice[i] == val) return true;
	return false;
}

int main() {
	int testCases;
	int choice1, choice2, buff;
	
	cin >> testCases;
	for(int tcase = 1; tcase <= testCases; tcase++) {
		cin >> choice1;
		for(int i = 1; i <= MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				if(i != choice1) cin >> buff;
				else			 cin >> choice[j];
			}
		}
		
		cin >> choice2;
		
		int possChoice = 0;
		for(int i = 1; i <= MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				cin >> buff;
				if(possChoice >= 0 && i == choice2 && inChoice(buff)) {
					if(possChoice == 0) possChoice = buff;
					else				possChoice = -1;
				}
			}
		}
		
		cout << "Case #" << tcase << ": ";

		if(possChoice == -1)	  cout << "Bad magician!";
		else if(possChoice == 0)  cout << "Volunteer cheated!";
		else					  cout << possChoice;

		cout << endl;
	}
	
	return 0;
}

