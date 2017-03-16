#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int number_of_tests;
int test_number;

int n;
int p[30];

void read() {
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &p[i]);
	}
}

string to_string(int x) {
	string s;
	s += 'A' + x - 1;
	return s;
}

string to_string(int x, int y) {
	string s;
	s += 'A' + x - 1;
	s += 'A' + y - 1;
	return s;
}

void solve() {
	vector <string> ans;
	set <pair<int, int> > s;
	fi(1, n) {
		s.insert(mp(-p[i], i));
	}
	while (s.size() > 0) {
		int x = s.begin()->second;
		s.erase(s.begin());
		int y = s.begin()->second;
		s.erase(s.begin());
		if (p[x] >= p[y] + 2) {
			ans.push_back(to_string(x, x));
			p[x] -= 2;
			if (p[x] != 0) s.insert(mp(-p[x], x));
			s.insert(mp(-p[y], y));
		} else {
			if (s.size() == 1 && p[x] == 1 && p[y] == 1) {
				ans.push_back(to_string(x));
				s.insert(mp(-p[y], y));
			} else {
				ans.push_back(to_string(x, y));
				p[x]--;
				p[y]--;
				if (p[x] != 0) s.insert(mp(-p[x], x));
				if (p[y] != 0) s.insert(mp(-p[y], y));
			}
		}
	}
	fi(0, SIZE(ans) - 1) {
		printf("%s ", ans[i].c_str());
	}
	printf("\n");
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &number_of_tests);
	for (test_number = 1; test_number <= number_of_tests; test_number++) {
		read();
		printf("Case #%d: ", test_number);
		solve();
		fflush(stdout);
	}
	return 0;
}
