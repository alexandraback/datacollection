#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

int main() {
	ofstream fout("magic.out");
	ifstream fin("magic.in");

	int t;

	fin >> t;

	cout << t << " test cases" << endl;

	
	for (int c = 1; c <= t; c++){
		int rowWanted;//row wanted

		set<int> set;
		for (int i = 1; i <= 16; i++)
			set.insert(i);

		for (int repeat = 1; repeat <= 2; repeat++){
			fin >> rowWanted;
			for (int i = 1; i <= 4; i++){//for each row
				for (int j = 1; j <= 4; j++){//take each element
					int in;
					fin >> in;
					if (i != rowWanted){
						set.erase(in);
					}
				}
			}
		}

		cout << "set #" << c << " contains:";
		for (auto iter = set.begin(); iter != set.end(); iter++){
			cout << " " << *iter;
		}
		cout << endl;
		if (set.size() == 0)
			fout << "Case #" << c << ": Volunteer cheated!" << endl;
		else if (set.size()==1)
			fout << "Case #" << c << ": " << *set.begin() << endl;
		else
			fout << "Case #" << c << ": Bad magician!" << endl;
		
	}

	return 0;
}