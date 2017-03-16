#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input;
	ofstream output;
	input.open("./Downloads/A-large.in");
	output.open("result2016c1l");

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t ++) {
		unsigned N;
		unsigned tot = 0;
		input >> N;
		vector<unsigned> arr(N);
		for (unsigned i = 0; i < N; i ++) {
			input >> arr[i];
			tot += arr[i];
		}
		string result = "";
		
		while (tot > 0) {
			result = result + ' ';
			unsigned mx = 0;
			for (unsigned i = 0; i < N; i ++) {
				if (arr[mx] < arr[i]) {
					mx = i;
				}
			}
			arr[mx] --;
			tot --;
			result = result + (char)('A' + mx);
			for (unsigned i = 0; i < N; i ++) {
				if (arr[mx] < arr[i]) {
					mx = i;
				}
			}
			if (arr[mx] > (tot / 2)) {
				arr[mx] --;
				tot --;
				result = result + (char)('A' + mx);
			} 
		}

		output << "Case #" << t + 1 << ":" << result << endl;
	}
	return 0;
}
