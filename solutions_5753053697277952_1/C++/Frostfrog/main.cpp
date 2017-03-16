#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#define INPUTFILE "A-large.in"
#define OUTPUTFILE "A-large.out"


using namespace std;

void solve_one() {
	int N;
	cin >> N;
	vector<int> s;

	s.reserve(N);

	int total = 0;
	while (N--) {
		int p;

		cin >> p;

		total += p;
		s.push_back(p);
	}



	auto b = s.begin();
	while(1) {
		auto i = max_element(s.begin(), s.end());
		if (*i == 0) {
			break;
		}

		char a = 'A'+ distance(b, i);

		(*i)--;
		--total;

		auto ii = max_element(s.begin(), s.end());

		if (*ii == 0) {
			cout << " " << a;
			break;
		}

		(*ii)--;
		--total;

		auto iii = max_element(s.begin(), s.end());

		if (*iii * 2 > total) {
			cout << " " << a;
			(*ii)++;
			total++;
			continue;
		}

		char bb = 'A' +  distance(b, ii);
		cout << " " << a << bb;
	}


}


int main()
{
	int T, cases = 0;
	string dummy;

	freopen(INPUTFILE,"r",stdin);
	freopen(OUTPUTFILE,"w",stdout);

	cin >> T;

	getline(cin, dummy);

	while (T--) {

		cout << "case #" << ++cases << ":";

		solve_one();

		cout << endl;
	}

	return 0;
}

