#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 

int main() {
	int t, r, num;

	cin >> t;

	REP(tc,t) {
		set <int> cards, res;
		cin >> r;
		REP(i,16) {
			cin >> num;
			if (i/4 == r-1) cards.insert(num);
		}
		cin >> r;
		REP(i,16) {
			cin >> num;
			if (i/4 == r-1 && cards.count(num)>0) res.insert(num);
		}

		cout << "Case #" << tc+1 << ": ";
		if (res.size() == 0) cout << "Volunteer cheated!" << endl;
		else if (res.size() > 1) cout << "Bad magician!" << endl;
		else cout << *res.begin() << endl;
	}

	return 0;
} 