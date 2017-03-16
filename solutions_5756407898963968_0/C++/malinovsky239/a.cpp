#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 20;

int cnt[N];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < 2; j++) {
			int ch;
			cin >> ch;
			for (int k = 0; k < 4; k++) {
				for (int t = 0; t < 4; t++) {
					int card;
					cin >> card;
					if (k == ch - 1)
						cnt[card]++;
				}
			}			
		}
		vector<int> correct;
		for (int j = 1; j <= 16; j++) {
			if (cnt[j] == 2) {
				correct.pb(j);
			}
		}
		printf("Case #%d: ", i + 1);
		if (sz(correct) == 1)
			printf("%d\n", correct[0]);
		if (sz(correct) == 0) 
			printf("Volunteer cheated!\n");			
		if (sz(correct) > 1)
			printf("Bad magician!\n");
	}
	return 0;
}
