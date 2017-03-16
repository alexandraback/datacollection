#include <iostream>
#include <fstream>
using namespace std;

int maximum(int [], int);
int repeat(int [], int, int);
bool checkAllZero(int [], int);

int main() {
	ofstream myfile("A-small-attempt0.txt");
	ifstream target("A-small-attempt0.in");
	int T;
	target >> T;
	char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for (int i = 1; i <= T; i++) {
		int N;
		target >> N;
		int parties[N];
		for (int j = 0; j < N; j++) {
			target >> parties[j];
		}
		string result = "";
		bool finish = false;
		while(!finish) {
			int max = maximum(parties, N);
			int repea = repeat(parties, N, max);
			int minus;
			if (repea == 1 || repea == 3)
				minus = 1;
			else
				minus = 2;
			for (int j = 0; j < N; j++) {
				if (parties[j] == max) {
					parties[j] -= 1;
					minus -= 1;
					result = result + alphabets[j];
				}
				if (minus == 0) {
					result = result + ' ';
					break;
				}
			}
			finish = checkAllZero(parties, N);
		}
		myfile << "Case #" << i << ": " << result << endl;
	}
	return 0;
}

int maximum(int parties[], int N) {
	int maximum = 0;
	for (int i = 0; i < N; i++) {
		if (parties[i] > maximum)
			maximum = parties[i];
	}
	return maximum;
}

int repeat(int parties[], int N, int maximum) {
	int repeat = 0;
	for (int i = 0; i < N; i++) {
		if (parties[i] == maximum) {
			repeat++;
		}
	}
	return repeat;
}

bool checkAllZero(int parties[], int N) {
	for (int i = 0; i < N; i++) {
		if (parties[i] != 0)
			return false;
	}
	return true;
}
