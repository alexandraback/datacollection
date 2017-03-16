#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void){
	int T, c;
	int good1[4], good2[4], ti;
	char buf[256];

	ifstream fin("1.txt");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T){
		fout << "Case #" << t+1 << ": ";
		fin >> c;
		c--;
		REP(i, 4){
			if(i==c){
				REP(i,4) fin >> good1[i];			
			} else {
				REP(i,4) fin >> ti;
			}
		}
		fin >> c;
		c--;
		REP(i, 4){
			if(i==c){
				REP(i,4) fin >> good2[i];			
			} else {
				REP(i,4) fin >> ti;
			}
		}

		int sovp, num;
		sovp = 0;
		REP(i, 4){
			REP(j, 4){
				if(good1[i] == good2[j]){
					sovp++;
					num = good1[i];
				}
			}
		}
		if(sovp == 1) fout << num << endl;
		if(sovp > 1) fout << "Bad magician!\n";
		if(sovp == 0) fout << "Volunteer cheated!\n";
	}
	return 0;
}
