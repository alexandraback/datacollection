#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 26;

int t;
int n;
int P[Maxn], sum;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &P[i]); sum += P[i];
		}
		printf("Case #%d:", tc);
		while (sum > 0) {
			vector <int> seq; seq.push_back(0);
			for (int i = 1; i < n; i++) {
				if (P[i] > P[seq.back()]) seq.clear();
				if (seq.empty() || P[i] == P[seq.back()]) seq.push_back(i);
			}
			if (seq.size() == 1 || seq.size() > 2) { printf(" %c", seq[0] + 'A'); P[seq[0]]--; sum--; }
			else { printf(" %c%c", seq[0] + 'A', seq[1] + 'A'); P[seq[0]]--; P[seq[1]]--; sum -= 2;  }
		}
		printf("\n");
	}
	return 0;
}
