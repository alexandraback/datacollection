// Problem A. Senate Evacuation
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n, c, total = 0;;
		vector<pair<int, char> > v;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &c);
			total += c;
			v.push_back(make_pair(c, 'A' + i));
		}
		sort(v.begin(), v.end());

		printf("Case #%d:", ti);

		for (int k = 0; k < total; k) {
			string s;
			s += v.back().second;
			v.back().first--;
			k++;
			sort(v.begin(), v.end());
			if (k < total && (total - k) != 2) {
				s += v.back().second;
				v.back().first--;
				k++;
				sort(v.begin(), v.end());
			}
			printf(" %s", s.c_str());
			// if (total - k > 0)
			// 	printf(" (%.2f)", (double) v.back().first / (total - k));
		}

		printf("\n");
	}

	return 0;
}
