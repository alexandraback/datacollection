
#include<iostream>
#include<string>
#include<map>
using namespace std;



int members[26];
char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main()
{
	std::ios_base::sync_with_stdio(true);


	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {

		int n;
		cin >> n;

		for (int l = 0; l < n; l++) {
			cin >> members[l];
		}


		cout << "Case #" << k << ": ";


		while (1) {

			int max = 0;
			int amount_of_highest = 0;
			for (int l = 0; l < n; l++) {
				if (max < members[l]) {
					max = members[l];
					amount_of_highest = 1;
				}
				else if (max == members[l]) {
					amount_of_highest++;
				}
			}

			if (max == 0) {
				cout << endl;
				break;
			}


			if (amount_of_highest == 1 || (max==1 && amount_of_highest == 3)) {
				//TAKE ONE
				for (int l = 0; l < n; l++) {
					if (members[l] == max) {
						cout << alphabet[l] << " ";
						members[l]--;
						break;
					}
				}
			} else {
				//TAKE TWO
				int taken = 0;
				for (int l = 0; l < n; l++) {
					if (members[l] == max && taken < 2) {

						taken++;
						cout << alphabet[l];
						members[l]--;
					}
				}
				cout << " ";
			}

		}

	}
	return 0;
}

