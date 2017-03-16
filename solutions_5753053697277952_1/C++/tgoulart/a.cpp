#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

struct Party {
	int senators;
	char name;
	bool operator <(const Party &other) const {
		if (senators != other.senators) return senators > other.senators;
		return name < other.name;
	}
};

void solveSingleCase() {
	int N;
	cin >> N;

	vector <Party> parties(N);

	for (int i = 0; i < N; ++i) {
		cin >> parties[i].senators;
		parties[i].name = 'A' + i;
	}

#define CHECK() {\
	int total = 0;\
	for (int k = 0; k < (int)parties.size(); ++k) {\
		total += parties[k].senators;\
	}\
	for (int k = 0; k < (int)parties.size(); ++k) {\
		assert(parties[k].senators * 2 <= total);\
	}\
}
	sort(parties.begin(), parties.end());

	while (parties[0].senators > parties[1].senators) {
		cout << " " << parties[0].name;
		--parties[0].senators;
		CHECK();
	}
	for (int i = 2; i < (int)parties.size(); ++i) {
		while (parties[i].senators > 0) {
			cout << " " << parties[i].name;
			--parties[i].senators;
			//CHECK();
		}
	}
	while (parties[0].senators > 0) {
		cout << " " << parties[0].name << parties[1].name;
		--parties[0].senators;
		--parties[1].senators;
		CHECK();
	}

	cout << endl;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ":";
		solveSingleCase();
	}
	
	return 0;
}
