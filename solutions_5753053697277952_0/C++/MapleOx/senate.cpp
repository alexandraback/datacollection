#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printcase(int i) {
	cout << "Case #" << i+1 << ": ";
}

char intToChar(int i) {
	return 'A' + i;
}

// find maximum value of array and puts index into k
int findMax1(int A[], int N, int *k) {
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (A[i] >= max) {
			max = A[i];
			*k = i;
		}
	}
	return max;
}

int findMax2(int A[], int N, int *k) {
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (A[i] > max) {
			max = A[i];
			*k = i;
		}
	}
	return max;
}

bool findThird (int A[], int N, int k, int l, int *j) {
	int max = A[k];
	for (int i = 0; i < N; ++i) {
		if (A[i] == max && i != k && i != l) {
			*j = i;
			return true;
		}
	}
	return false;
}

bool oneStep(int A[], int N) {
	int k = -1, l = -1, j = -1;
	int max1 = findMax1(A, N, &k);
 	int max2 = findMax2(A, N, &l);
 	//cout << k << " " << l << endl;
 	if (max1 == 0) return false;
 	if (k == l) {
 		A[k] -= 1;
 		cout << intToChar(k) << " ";
 	} else {
 		if (findThird(A, N, k, l, &j)) {
 			A[k] -= 1;
 			cout << intToChar(k) << " ";
 		} else {
	 		A[k] -= 1;
	 		A[l] -= 1;
	 		cout << intToChar(k) << intToChar(l) << " ";
	 	}
 	}
 	return true;
}

int main() {
	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		int A[N];
		// A[j] is the number of senators belonging to party j
		for (int j = 0; j < N; ++j) {
			cin >> A[j];
		}
		printcase(i);
		while (oneStep(A, N)) {
			;
		}
		cout << endl;
	}

	return 0;
}