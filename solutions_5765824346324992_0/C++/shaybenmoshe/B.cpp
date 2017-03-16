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


#define MAX_B	1000


ulong gcd(ulong a, ulong b) {
	while (true) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

ulong lcm(ulong a, ulong b) {
	ulong temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

ulong howMany(uint B, uint *M, ulong t) {
	ulong H = 0;
	FOR(i, 0, B - 1) {
		H += (t + M[i] - 1) / M[i];
	}
	return H;
}

uint solve(uint B, ulong N, uint *M) {
	ulong MLcm = 1;
	FOR(i, 0, B - 1) {
		MLcm = lcm(MLcm, M[i]);
	}

	ulong NAtLcm = howMany(B, M, MLcm);
	N = N % NAtLcm;
	if (N == 0) {
		N += NAtLcm;
	}

	ulong tL = 1, tH = MLcm, tM;
	ulong H;
	while (tH - tL > 2) {
		tM = (tL + tH) / 2;
		H = howMany(B, M, tM);
		if (H < N) {
			tL = tM;
		}
		else {
			tH = tM;
		}
	}

	ulong t = tL;
	H = howMany(B, M, t);
	if (H >= N) {
		t--;
		H = howMany(B, M, t);
	}
	N -= H;

	while (true) {
		FOR(i, 0, B - 1) {
			if (t % M[i] == 0) {
				N--;
				if (N == 0) {
					return i + 1;
				}
			}
		}
		t++;
	}

	return 1;
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



		uint B;
		ulong N;
		input >> B;
		input >> N;

		uint M[MAX_B];
		FOR(k, 0, B - 1) {
			input >> M[k];
		}


		output << "Case #" << i << ": " << solve(B, N, M) << endl;



		chrono::milliseconds timeEnd = chrono::duration_cast< chrono::milliseconds >(chrono::high_resolution_clock::now().time_since_epoch());
		cout << ", took " << (timeEnd - timeStart).count() << "ms" << endl;
	}

	input.close();
	output.close();

	cout << "DONE!" << endl;
	system("pause");
}

