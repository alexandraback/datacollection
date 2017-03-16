#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define inp(x) scanf("%d",&x)
#define inpf(x) scanf("%f",&x)

using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;

int cmp (const void* p1, const void* p2) {
	if (*(int*) p1 == *(int*) p2) {
		return 0;
	} else {
		return (*(int*) p1 < *(int*) p2 ? -1 : 1);
	}
}

string compress(char* cStr, int* counts) {
	int j = 0;
	char result[101];

	result[0] = cStr[0];
	counts[0] = 1;
	j++;
	for (int i = 1; cStr[i] != '\0'; i++) {
		if (cStr[i] != cStr[i-1]) {
			result[j] = cStr[i];
			counts[j] = 1;
			j++;
		} else {
			counts[j-1]++;
		}
	}

	result[j] = '\0';

	return result;
}

int main() {
	int T;
	int N,L;
	char* s[100];
	int counts[100][100];
	int countsT[100][100];
	string str;
	bool fegla;
	int ops;

	for (int i = 0; i < 100; i++) {
		s[i] = new char[101];
	}

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> s[i];
		}

		str = compress(s[0],counts[0]);
		L = str.length();
		fegla = false;

		for (int i = 1; i < N; i++) {
			if (str != compress(s[i],counts[i])) {
				fegla = true;
				break;
			}
		}

		if (fegla) {
			cout << "Case #" << t << ": " << "Fegla Won" << endl;
		} else {
			ops = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++) {
					countsT[j][i] = counts[i][j];
				}
			}

			for (int i = 0; i < L; i++) {
				qsort(countsT[i], N, sizeof(int), cmp);
				for (int j = 0; j < N; j++) {
					ops += abs(countsT[i][j] - countsT[i][N/2]);
				}
			}

			cout << "Case #" << t << ": " << ops << endl;
		}
	}

	for (int i = 0; i < 100; i++) {
		delete[] s[i];
	}

	return 0;
}
