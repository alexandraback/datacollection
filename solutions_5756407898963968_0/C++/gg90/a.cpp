#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define fori(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)

//magic trick
int main(int argc, char** argv) {
	fstream file("qualification/inputA2");
	int testCases;
	file >> testCases;
	set<int> first;
	int second[4];
	int testCase = 1;
	while (testCases--) {
		int firstChoice, secondChoice;
		file >> firstChoice;
		firstChoice--;
		fori(i, 4) {
			int ignored;
			if (i == firstChoice) {
				fori(z, 4){
					file >> ignored;
					first.insert(ignored);
				}
			} else {
				fori(z, 4)
					file >> ignored;
			}
		}
		file >> secondChoice;
		secondChoice--;
		fori(i, 4) {
			int ignored;
			if (i == secondChoice) {
				fori(z, 4)
					file >> second[z];
			} else {
				fori(z, 4)
					file >> ignored;
			}
		}
		bool error = false;
		bool found = false;
		int result;
		fori(i, 4){
			if (first.count(second[i]) && found == false){
				found = true;
				result = second[i];
			} else if (first.count(second[i]) && found){
				error = true;
			}
		}
		cout << "Case #" << testCase << ": ";
		if (found && error == false){
			cout << result;
		} else if (error){
			cout << "Bad magician!";
		} else {
			cout << "Volunteer cheated!";
		}
		first.clear();

		cout << endl;
		testCase++;
	}
	return 0;
}

