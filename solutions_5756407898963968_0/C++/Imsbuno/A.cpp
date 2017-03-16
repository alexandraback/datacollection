#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int testCaseNum;
	scanf("%d", &testCaseNum);
	for (int testCase = 1; testCase <= testCaseNum; ++testCase) {
		map<int,int> cnt;
		cnt.clear();
		for (int k = 0, r; k < 2; ++k) {
			scanf("%d", &r);
			for (int i = 1; i <= 4; ++i)
				for (int j = 1, x; j <= 4; ++j) {
					scanf("%d", &x);
					if (i != r) continue;
					if (cnt.find(x) == cnt.end()) cnt[x] = 0;
					cnt[x]++;
				}
		}
		int target = 0;
		for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
			if (it->second == 2)
				target = target * 17 + it->first;
		printf("Case #%d: ", testCase);
		if (target == 0) printf("Volunteer cheated!\n"); else
		if (target < 17) printf("%d\n", target); else
		printf("Bad magician!\n");
	}
	
	return 0;
}