#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("E:\\A-small-attempt0.in");
	// ifstream fin("E:\\temp.txt");
	ofstream fout("E:\\A-small.out");
	int T;
	fin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		int mushroom[1000];
		fin >> N;
		for (int j = 0; j < N; j++) {
			fin >> mushroom[j];
		}
		int sum1 = 0;
		int min_rate = 0;
		for (int j = 1; j < N; j++) {
			if (mushroom[j] < mushroom[j - 1]) {
				if (min_rate < mushroom[j - 1] - mushroom[j]) {
					min_rate = mushroom[j - 1] - mushroom[j];
				}
				sum1 = sum1 + mushroom[j - 1] - mushroom[j];
			}
		}
		int sum2 = 0;
		int progress = mushroom[0];
		for (int j = 1; j < N; j++) {
			if (progress - min_rate < 0) {
				sum2 = sum2 + progress;
			}
			else {
				sum2 = sum2 + min_rate;
			}
			progress = mushroom[j];
		}

		fout << "Case #" << i << ": " << sum1 << " " << sum2 << endl;
	}
	return 0;
}
