#include <cstdio>
#include <vector>
//#include <fstream>
using namespace std;
int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		int count[17] = {0};

		int r;
		int val;
		scanf("%d", &r);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				scanf("%d", &val);
				if (i + 1 == r)
					count[val]++;
			}

		scanf("%d", &r);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				scanf("%d", &val);
				if (i + 1 == r)
					count[val]++;
			}

		vector<int> res;
		for (int it = 1; it <= 16; it++) {
			if (count[it] == 2)
				res.push_back(it);
		}

		printf("Case #%d: ", t);
		if (res.size() > 1)
			printf("Bad magician!\n");
		else if (res.size() == 0)
			printf("Volunteer cheated!\n");
		else
			printf("%d\n", res[0]);
	}
}