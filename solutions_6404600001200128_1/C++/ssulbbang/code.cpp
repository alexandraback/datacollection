#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int n;

	fin >> n;
	for(int i = 1; i <= n; i++) {
		int m;
		fin >> m;
		vector<int> pancakes;
		pancakes.resize(m);
		for(int j = 0; j < m; j++) {
			fin >> pancakes[j];
		}


		int method1 = 0;
		int method2 = 0;
		int rate = 0;
		for(int j = 1; j < m; j++) {
			if(pancakes[j] < pancakes[j - 1]) {
				method1 += pancakes[j - 1] - pancakes[j];

				if(rate < pancakes[j - 1] - pancakes[j]) {
					rate = pancakes[j - 1] - pancakes[j];
				}
			}
		}

		for(int j = 0; j < m - 1; j++) {
			if(pancakes[j] >= rate) {
				method2 += rate;
			}
			else {
				method2 += pancakes[j];
			}
		}


		cout << "Case #" << i << ": " << method1 << " " << method2 << endl;
	}
	fin.close();
}