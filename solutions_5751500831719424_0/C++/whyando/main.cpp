#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <string>

using namespace std;

int main() {
	ofstream fout("repeat.out");
	ifstream fin("repeat.in");

	int t;
	fin >> t;


	for (int caseNo = 1; caseNo <= t; caseNo++){
		bool possible = true;
		vector<string> vec;
		vector<int> iterator;
		int n;
		fin >> n;
		for (int i = 0; i < n; i++){
			string in;
			fin >> in;
			vec.push_back(in);
			iterator.push_back(0);
		}

		string first = vec[0];
		char prev = '0';

		int totalchanges = 0;
		//for each character in string
		for (int i = 0; i < first.length(); i++){
			char current = first[i];
			if (current == prev)
				continue;
			
			vector<int> count;
			for (int j = 0; j < n; j++)
				count.push_back(0);
			//count the number of 'current' in each string			
			for (int j = 0; j < n; j++){
				if (iterator[j] >= vec[j].length() || vec[j][iterator[j]] != current){
					//need to say fegla won
					possible = false;
					//cout << "should have been " << current << " not " << vec[j][iterator[j]] << endl; 
					break;
				}

				while (iterator[j] < vec[j].length() && vec[j][iterator[j]] == current){
					count[j]++;
					iterator[j]++;
				}
			}
			if (possible == false)
				break;

			int totalcount=0;
			for (int j = 0; j < n; j++)
				totalcount += count[j];

			int average = round(totalcount / (double)n);

			int changes = 0;
			for (int j = 0; j < n; j++){
				changes += abs(average-count[j]);
			}

			cout << current << " " << totalcount << " " << changes << endl;

			totalchanges += changes;
			prev = current;		

		}
		//at end need to check if iterator got to the end of every string
		for (int i = 0; i < n; i++){
			if (iterator[i] != vec[i].length()){
				possible = false;
				break;
			}
		}

		if (possible)
			fout << "Case #" << caseNo << ": " << totalchanges << endl;
		else
			fout << "Case #" << caseNo << ": Fegla Won" << endl;
	}
	return 0;
}