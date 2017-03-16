#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N_MAX = 26;

int dane[N_MAX];
int n;

pair<int, int> znajdz_maks() {
	pair<int, int> result = make_pair(-1, -1);
	for (int i = 0; i < n; ++i) {
		if (dane[i] > result.second) {
			result.first = i;
			result.second = dane[i];
		}
	}
	return result;
}

void wypisz(int x, int y, int sum) {
	char x1 = x + 65;
	if (y != -1) {
		char y1 = y + 65;
		printf("%c%c", x1, y1);
	} else {
		printf("%c", x1);
	}
	if (sum > 0) printf(" ");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &dane[i]);
			sum += dane[i];
		}
		printf("Case #%d: ", t);
		while(sum > 0) {
			pair<int, int> x = make_pair(-1, -1), y = make_pair(-1, -1);
			x = znajdz_maks();
			--sum;
			--dane[x.first];
			if (sum != 2)  {
				y = znajdz_maks();
				--sum;
				--dane[y.first];
			}
			wypisz(x.first, y.first, sum);
		}
		printf("\n");
	}
	return 0;
}