#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int numTestCases;
	cin >> numTestCases;
	for (int i=0; i<numTestCases; ++i) {
		int N;
		cin >> N;
		vector<int> history;
		for (int j=0; j<N; ++j) {
			int temp;
			cin >> temp;
			history.push_back(temp);
		}

		int method1 = 0;
		int biggestGap = 0;
		for (int j=1; j<history.size(); ++j) {
			if (history[j] < history[j-1]) {
				method1 += history[j-1] - history[j];
				biggestGap = max(biggestGap, history[j-1] - history[j]);
			}
		}
		int method2 = 0;
		for (int j=0; j<history.size()-1; ++j) {
			method2 += min(biggestGap, history[j]);
		}
		cout << "Case #" << (i+1) << ": " << method1 << " " << method2 << endl; 
	}
}
