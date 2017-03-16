#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAX_N 100
#define MAX_LENGTH 100
#define BUFFER_SIZE 100

using namespace std;

vector< pair<int, int> > v[MAX_N];
char str[BUFFER_SIZE + 10];

char *trim_line(char *str)
{
  return strtok(str, "\r\n");
}

bool compare_vectors(const vector< pair<int, int> > &x, const vector< pair<int, int> > &y)
{
	if (x.size() != y.size()) {
		return false;
	}
	for (size_t i = 0; i < x.size(); i++) {
		if (x[i].first != y[i].first) {
			return false;
		}
	}
	return true;
}

int solve_problem(int num_case)
{
	int n;

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	n = atoi(str);

	for (int i = 0; i < n; i++) {
		if (fgets(str, sizeof(str), stdin) == NULL)
			return 1;
		trim_line(str);
		v[i].clear();
		size_t len = strlen(str);
		int last_ch = -1;
		int cnt = 0;
		for (size_t j = 0; j < len; j++) {
			int ch = str[j] - 'a';
			if (ch != last_ch) {
				if (last_ch >= 0) {
					v[i].push_back(make_pair(last_ch, cnt));
				}
				last_ch = ch;
				cnt = 1;
			} else {
				++cnt;
			}
		}
		if (last_ch >= 0) {
			v[i].push_back(make_pair(last_ch, cnt));
		}
	}

	int result = 0;
	for (int i = 1; i < n; i++) {
		if (!compare_vectors(v[0], v[i])) {
			result = -1;
			break;
		}
	}
	if (result >= 0) {
		size_t len = v[0].size();
		for (size_t i = 0; i < len; i++) {
			int s = numeric_limits<int>::max();
			for (int j = 0; j <= MAX_LENGTH; j++) {
				int cand = 0;
				for (int k = 0; k < n; k++) {
					cand += abs(v[k][i].second - j);
				}
				if (cand < s) {
					s = cand;
				}
			}
			result += s;
		}
		printf("Case #%d: %d\n", num_case, result);
	} else {
		printf("Case #%d: %s\n", num_case, "Fegla Won");
	}

	return 0;
}

int main()
{
	int num_tests;

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	num_tests = atoi(str);

	for (int i = 0; i < num_tests; i++)
		solve_problem(i + 1);

	return 0;
}
