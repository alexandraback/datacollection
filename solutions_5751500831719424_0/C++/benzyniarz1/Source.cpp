#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define getchar_custom _fgetc_nolock

int get_min(int* arr, int n) {
	int curr_min = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (*(arr + i) < curr_min) {
			curr_min = *(arr + i);
		}
	}

	return curr_min;
}


int cmpfunc(const void * a, const void * b)
{
	if (*(int*) a < *(int*) b) {
		return -1;
	}
	
	if (*(int*) a == *(int*) b) {
		return 0;
	}

	return 1;
}

int get_median(int* arr, int n) {
	qsort(arr, n, sizeof(int), cmpfunc);

	return arr[n / 2];
}

int main() {
	std::ios_base::sync_with_stdio(0);

	int casesNo;
	std::cin >> casesNo;
	for (int caseNo = 1; caseNo <= casesNo; caseNo++) {

		std::vector<char> strings[100];
		for (int i = 0; i < 100; i++) {
			std::vector<char> emptyVector;
			strings[i] = emptyVector;
		}


		int stringsToProcess;
		std::cin >> stringsToProcess;
		getchar_custom(stdin);

		for (int i = 0; i < stringsToProcess; i++) {
			char c = getchar_custom(stdin);
			while (c >= 'a' && c <= 'z') {
				strings[i].push_back(c);
				c = getchar_custom(stdin);
			}
		}

		int* positions = new int[100];
		memset(positions, 0, 100 * sizeof(int));

		long totalMoves = 0;
		char currentProcessedChar = '\0';
		bool isEnd = false;
		bool feglaWon = false;

		while (!isEnd) {

			int* currentCharCounts = new int[100];
			memset(currentCharCounts, 0, 100 * sizeof(int));

			for (int i = 0; i < stringsToProcess; i++) {

				if (i == 0) {
					currentProcessedChar = strings[i][*(positions + i)];
				}

				while (
					*(positions + i) < strings[i].size()
					&& strings[i][*(positions + i)] == currentProcessedChar) {
					currentCharCounts[i] += 1;
					positions[i] += 1;
				}
			}

			int countMin = get_min(currentCharCounts, stringsToProcess);
			if (countMin == 0) {
				feglaWon = true;
				break;
			}

			bool shouldEnd = false;
			int median = get_median(currentCharCounts, stringsToProcess);
			for (int i = 0; i < stringsToProcess; i++) {
				totalMoves += abs(currentCharCounts[i] - median);

				if (positions[i] == strings[i].size()) {
					shouldEnd = true;
				}
			}

			if (shouldEnd) {
				isEnd = true;
				for (int i = 0; i < stringsToProcess; i++) {
					if (positions[i] < strings[i].size()) {
						feglaWon = true;
					}
				}
			}

			delete [] currentCharCounts;
		}

		if (feglaWon) 
		{
			std::cout << "Case #" << caseNo << ": Fegla Won" << std::endl;
		}
		else
		{
			std::cout << "Case #" << caseNo << ": " << totalMoves << std::endl;
		}
	}

}