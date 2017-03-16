#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <stdint.h>

using namespace std;

typedef uint32_t uint;
typedef int32_t sint;
typedef uint64_t ulong;
typedef int64_t slong;
typedef uint8_t byte;

#define FOR(var,start,end)		for (sint (var) = (sint)(start); (var) <= (sint)(end); (var)++)
#define SORT(arr, N)			std::sort((arr), &(arr)[(N)])

#define MAX_N	1000


uint solve1(uint N, uint *m) {
	uint o = 0;
	FOR(i, 0, N - 2) {
		sint d = m[i] - m[i + 1];
		if (d > 0) {
			o += d;
		}
	}
	return o;
}

uint solve2(uint N, uint *m) {
	uint speed = 0;
	FOR(i, 0, N - 2) {
		sint d = m[i] - m[i + 1];
		if (d > 0 && d > speed) {
			speed = d;
		}
	}

	uint o = 0;
	FOR(i, 0, N - 2) {
		o += m[i] >= speed ? speed : m[i];
	}

	return o;
}


void main() {
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	uint T;
	input >> T;

	FOR(i, 1, T) {
		cout << "Case #" << i << " out of #" << T;
		chrono::milliseconds timeStart = chrono::duration_cast< chrono::milliseconds >(chrono::high_resolution_clock::now().time_since_epoch());



		uint N;
		input >> N;

		uint m[MAX_N];
		FOR(k, 0, N - 1) {
			input >> m[k];
		}


		output << "Case #" << i << ": " << solve1(N, m) << " " << solve2(N, m) << endl;



		chrono::milliseconds timeEnd = chrono::duration_cast< chrono::milliseconds >(chrono::high_resolution_clock::now().time_since_epoch());
		cout << ", took " << (timeEnd - timeStart).count() << "ms" << endl;
	}

	input.close();
	output.close();

	cout << "DONE!" << endl;
	system("pause");
}

