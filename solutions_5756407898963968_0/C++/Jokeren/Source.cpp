#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int M = 110;
static const int N = 4;
static const int LEN = 4;
static const int MAX = 0x7fffffff;
static const int MIN = ~MAX;
static const double EPS = 1e-8;

void solve(int ncase)
{
	std::vector<int> first;
	std::vector<int> second;
	int row;
	scanf("%d", &row);

	int tmp;
	for (int i = 0; i < N; i++) {
		bool input = false;
		if (i == row - 1) {
			input = true;
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (input) {
				first.push_back(tmp);
			}
		}
	}

	scanf("%d", &row);
	for (int i = 0; i < N; i++) {
		bool input = false;
		if (i == row - 1) {
			input = true;
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (input) {
				second.push_back(tmp);
			}
		}
	}

	int hit = 0;
	bool one = false;
	bool two = false;
	for (int i = 0; i < first.size(); i++) {
		int t = first[i];
		for (int j = 0; j < second.size(); j++) {
			if (t == second[j]) {
				if (!one) {
					one = true;
					hit = t;
				}
				else if (!two) {
					two = true;
					break;
				}
			}
		}
	}

	if (two) {
		printf("Case #%d: Bad magician!\n", ncase);
	}
	else if (one) {
		printf("Case #%d: %d\n", ncase, hit);
	}
	else {
		printf("Case #%d: Volunteer cheated!\n", ncase);
	}
}

int main()
{
	FINPUT("in.txt");
	FOUTPUT("out.txt");

	int c, ncase = 1;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		solve(ncase++);
	}
	return 0;
}