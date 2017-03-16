#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		int nstrings;
		cin >> nstrings;
		vector<string> strings;
		for (int j = 0; j < nstrings; j++){
			string str;
			cin >> str;
			strings.push_back(str);
		}
		vector < vector < pair<char, int> > > convertedStrings;
		for (int i = 0; i < strings.size(); i++){
			vector<pair<char, int> > converted;
			for (int j = 0; j < strings[i].size(); j++){
				converted.push_back(make_pair(strings[i][j], 1));
				while(((j + 1) < strings[i].size()) && (strings[i][j+1] == strings[i][j])){
					converted[converted.size()-1].second++;
					j++;
				}
			}
			convertedStrings.push_back(converted);
		}
		bool different = false;
		for (int i = 0; i < convertedStrings.size() - 1; i++){
			if (convertedStrings[i].size() != convertedStrings[i+1].size()){
				different = true;
				break;
			}
			for (int j = 0; j < convertedStrings[i].size(); j++){
				if (convertedStrings[i][j].first != convertedStrings[i+1][j].first){
					different = true;
					break;
				}
			}
		}
		int solution = 0;
		if (!different){
			for (int i = 0; i < convertedStrings[0].size(); i++){
				vector<int> repetitions;
				for (int j = 0; j < convertedStrings.size(); j++){
					repetitions.push_back(convertedStrings[j][i].second);
				}
				sort(repetitions.begin(), repetitions.end());
				int desired = repetitions[repetitions.size() / 2];
				for (int j = 0; j < convertedStrings.size(); j++){
					solution += fabs(desired - convertedStrings[j][i].second);
				}	
			}
		}

		if (different){
			cout << "Case #" << (test+1) << ": Fegla Won" << endl;
		} else {
			cout << "Case #" << (test+1) << ": " << solution << endl;
		}
	}
}
