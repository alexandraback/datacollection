#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		set<int> v[2];
		for(int i = 0; i < 2; i++) {
			int r;
			scanf("%d",&r);
			for(int j = 1; j <= 4; j++) {
				for(int k = 0; k < 4; k++) {
					int val;
					scanf("%d",&val);
					if (j == r) {
						v[i].insert(val);
					}
				}
			}
		}
		vector<int> intersection;
		set_intersection(v[0].begin(), v[0].end(), v[1].begin(), v[1].end(), back_inserter(intersection));
		printf("Case #%d: ", testcase);
		if (intersection.size() == 1) {
			printf("%d\n", intersection[0]);
		} else if (intersection.size() == 0) {
			printf("Volunteer cheated!\n");
		} else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}
