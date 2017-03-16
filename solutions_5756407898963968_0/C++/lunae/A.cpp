#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1; tc<=T; tc++) {
		int row1;
		scanf("%d",&row1);
		static int bord1[5][5];
		for (int y=1; y<=4; y++) {
			for (int x=1; x<=4; x++) {
				scanf("%d",&bord1[y][x]);
			}
		}
		int row2;
		scanf("%d",&row2);
		static int bord2[5][5];
		for (int y=1; y<=4; y++) {
			for (int x=1; x<=4; x++) {
				scanf("%d",&bord2[y][x]);
			}
		}
		vector<int> solutions;
		for (int x1=1; x1<=4; x1++) {
			for (int x2=1; x2<=4; x2++) {
				if (bord1[row1][x1] == bord2[row2][x2]) {
					solutions.push_back(bord1[row1][x1]);
				}
			}
		}
		printf("Case #%d: ",tc);
		if (solutions.empty()) {
			printf("Volunteer cheated!\n");
		} else
		if ((int)solutions.size() == 1) {
			printf("%d\n",solutions[0]);
		} else {
			printf("Bad magician!\n");
		}
	}
}
