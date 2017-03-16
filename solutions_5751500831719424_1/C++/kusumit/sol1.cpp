#include<algorithm>
#include<cmath>
#include<fstream>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;

bool Compare(int a, int b){return a < b;}

int main()
{
	ifstream fin("A-small-attempt.in");
	ofstream fout("A-small-attempt.out");

	int cases, numStrings, moves = 0;
	string subStr;
	bool notPossible = false;
	fin >> cases;

	for(int caseN = 1; caseN <= cases; ++caseN) {
		fout << "Case #" << caseN << ": ";
		vector<string> str;
		vector<vector<string>> substr;
		vector<int> subTemp;
		vector<int> subMedian;
		fin >> numStrings;

		string temp;
		for(int i = 0; i < numStrings; ++i) {
			fin >> temp;
			str.push_back(temp);
		}

		char prevChr;
		for(int i = 0; i < numStrings; ++i) {
			subStr = "";
			substr.push_back(vector<string>());
			for(int c = 0; c < str[i].size(); ++c) {
				if(c != 0 && str[i][c] != prevChr) {
					substr[i].push_back(subStr);
					subStr = "";
				}

				prevChr = str[i][c];
				subStr += str[i][c];
			}
			substr[i].push_back(subStr);
		}

		//		for(int i = 0; i < numStrings; ++i) {
		//			for(int j = 0; j < substr[i].size(); ++j) {
		//				cout << substr[i][j] << ' ';
		//			}
		//
		//			cout << '\n';
		//		}
		//		cout << str1 << ' ' << str2 << '\n';

		for(int i = 0; i < numStrings; ++i) {
			if(substr[i].size() != substr[0].size()) {
				notPossible = true;
				break;
			}
		}

		if(!notPossible) {
			for(int i = 0; i < substr[0].size(); ++i) {
				for(int j = 0; j < str.size(); ++j) {
					if(substr[j][i][0] != substr[0][i][0]) {
						notPossible = true;
						break;
					}
				}
			}
		}

		if(notPossible) {
			fout << "Fegla Won"<< '\n';
		} else {
			for(int i = 0; i < substr[0].size(); ++i) {
				for(int j = 0; j < substr.size(); ++j) {
					subTemp.push_back(substr[j][i].size());
				}
				//				for(int i = 0; i < subTemp.size(); ++i) {
				//					cout << subTemp[i] << ' ';
				//				}
				//				cout << '\n';

				sort(subTemp.begin(), subTemp.end(), Compare);
				subMedian.push_back(subTemp[subTemp.size() / 2]);
				subTemp = {};
			}

			//			for(int i = 0; i < subMedian.size(); ++i) {
			//				cout << subMedian[i] << ' ';
			//			}
			//			cout << '\n';

			for(int i = 0; i < substr[0].size(); ++i) {
				for(int j = 0; j < substr.size(); ++j) {
					//					cout << substr[j][i].size() << ' ' << subMedian[i] << ' ';
					int temp = substr[j][i].size();
					moves += abs(temp - subMedian[i]);
				}

				//				cout << '\n';
			}

			//			cout << '\n' << moves << '\n' << '\n';

			fout << moves << '\n';
		}

		notPossible = false;
		moves = 0;
	}

	return 0;
}
