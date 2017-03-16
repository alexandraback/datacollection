
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <limits>
#include <unordered_set>
#include <stack>
#include <map>
#include <functional>
#include <array>
#include <stack>
#include <numeric>
#include <stdint.h>
#include <array>

#include "Windows.h"


using namespace std;




struct Quail {
	int64_t pos;
	int64_t speed;
};

Quail all[500], neg[500], pos[500]; 

double times[500+1][500+1], rtimes[500+1][500+1];

int main() {
	
	Sleep(10*1000);

	int t = 0;
	cin >> t;

	for (auto i = 0; i < t; ++i) {
		
		int y, n;
		cin >> y >> n;

		for (auto i = 0; i < n; ++i) {
			cin >> all[i].pos;
		}
		for (auto i = 0; i < n; ++i) {
			cin >> all[i].speed;
		}
		auto posFilter = [] (const Quail &val) -> bool {
			return val.pos > 0;
		};
		const auto posEnd = copy_if(all, all+n, pos, posFilter);
		const auto negEnd = remove_copy_if(all, all+n, neg, posFilter);

		auto posSize = posEnd - pos;
		auto negSize = negEnd - neg;

		auto makeAbs = [] (Quail &val)  {
			val.pos *= -1;
		};
		for_each(neg, negEnd, makeAbs);

		auto speedComp = [] (const Quail &lhs, const Quail &rhs) -> bool {
			return lhs.speed > rhs.speed;
		};
		sort(pos, pos+posSize, speedComp);
		sort(neg, neg+negSize, speedComp);

		int64_t lastSpeed = 0;
		int index = 0;
		for (auto i = 0; i < posSize; ++i) {
			if (pos[i].speed == lastSpeed) {
				pos[index-1].pos = max(pos[index-1].pos, pos[i].pos);
			} else {
				pos[index].speed = pos[i].speed;
				pos[index].pos = pos[i].pos;
				lastSpeed = pos[i].speed;
				index++;
			}
		}
		posSize = index;

		lastSpeed = 0;
		index = 0;
		for (auto i = 0; i < negSize; ++i) {
			if (neg[i].speed == lastSpeed) {
				neg[index-1].pos = max(neg[index-1].pos, neg[i].pos);
			} else {
				neg[index].speed = neg[i].speed;
				neg[index].pos = neg[i].pos;
				lastSpeed = neg[i].speed;
				index++;
			}
		}
		negSize = index;

		double maxSoFar = 0;
		index = 1;
		for (auto i = 0; i < posSize; ++i) {
			times[0][index] = 2 * ((double)pos[i].pos) / (y - pos[i].speed);
			rtimes[0][index] = ((double)pos[i].pos) / (y - pos[i].speed);
			if (times[0][index] > maxSoFar) {
				maxSoFar = times[0][index];
				pos[index-1].pos = pos[i].pos;
				pos[index-1].speed = pos[i].speed;
				index++;
			} 
		}
		posSize = index-1;

		index = 1;
		maxSoFar = 0;
		for (auto i = 0; i < negSize; ++i) {
			times[index][0] = 2* ((double)neg[i].pos) / (y - neg[i].speed);
			rtimes[index][0] = ((double)neg[i].pos) / (y - neg[i].speed);
			if (times[index][0] > maxSoFar) {
				maxSoFar = times[index][0];
				neg[index-1].pos = neg[i].pos;
				neg[index-1].speed = neg[i].speed;
				index++;
			} 
		}
		negSize = index - 1;

		for (auto i = 0; i < posSize; ++i) {
			for (auto j = 0; j < negSize; ++j) {				
				double firstVal  =  (double)(neg[j].pos + neg[j].speed * times[j][i+1]) / (y-neg[j].speed);
				double secondVal =  (double)(pos[i].pos + pos[i].speed * times[j+1][i]) / (y-pos[i].speed);

				auto firstHalfTime  = firstVal + times[j][i+1];
				auto secondHalfTime = secondVal + times[j+1][i];

				auto firstFullTime = 2 * firstVal + times[j][i+1];
				auto secondFullTime = 2 * secondVal + times[j+1][i];

				times[j+1][i+1] = min(firstFullTime, secondFullTime);
				rtimes[j+1][i+1] = min(firstHalfTime, secondHalfTime);
			}
		}

		cout << "Case #" << i+1 << ": " << setprecision(7) << std::fixed << rtimes[negSize][posSize] << endl;

	}

}
