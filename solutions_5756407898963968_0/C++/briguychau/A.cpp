#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int ra, rb;
	int a1[4];
	int a2[4];
	int a3[4];
	int a4[4];
	int b1[4];
	int b2[4];
	int b3[4];
	int b4[4];
	int total;
	for (int i = 1; i <= t; i++) {
		scanf("%d", &ra);
		scanf("%d %d %d %d", &a1[0], &a1[1], &a1[2], &a1[3]);
		scanf("%d %d %d %d", &a2[0], &a2[1], &a2[2], &a2[3]);
		scanf("%d %d %d %d", &a3[0], &a3[1], &a3[2], &a3[3]);
		scanf("%d %d %d %d", &a4[0], &a4[1], &a4[2], &a4[3]);
		scanf("%d", &rb);
		scanf("%d %d %d %d", &b1[0], &b1[1], &b1[2], &b1[3]);
		scanf("%d %d %d %d", &b2[0], &b2[1], &b2[2], &b2[3]);
		scanf("%d %d %d %d", &b3[0], &b3[1], &b3[2], &b3[3]);
		scanf("%d %d %d %d", &b4[0], &b4[1], &b4[2], &b4[3]);
		vector<int> list;
		total = 0;
		int curr;
		switch (ra) {
			case 1:
				list.push_back(a1[0]);
				list.push_back(a1[1]);
				list.push_back(a1[2]);
				list.push_back(a1[3]);
				break;
			case 2:
				list.push_back(a2[0]);
				list.push_back(a2[1]);
				list.push_back(a2[2]);
				list.push_back(a2[3]);
				break;
			case 3:
				list.push_back(a3[0]);
				list.push_back(a3[1]);
				list.push_back(a3[2]);
				list.push_back(a3[3]);
				break;
			case 4:
				list.push_back(a4[0]);
				list.push_back(a4[1]);
				list.push_back(a4[2]);
				list.push_back(a4[3]);
				break;
		}
		switch (rb) {
			case 1:
				total += find(list.begin(), list.end(), b1[0]) != list.end() ? curr = b1[0], 1 : 0;
				total += find(list.begin(), list.end(), b1[1]) != list.end() ? curr = b1[1], 1 : 0;
				total += find(list.begin(), list.end(), b1[2]) != list.end() ? curr = b1[2], 1 : 0;
				total += find(list.begin(), list.end(), b1[3]) != list.end() ? curr = b1[3], 1 : 0;
				break;
			case 2:
				total += find(list.begin(), list.end(), b2[0]) != list.end() ? curr = b2[0], 1 : 0;
				total += find(list.begin(), list.end(), b2[1]) != list.end() ? curr = b2[1], 1 : 0;
				total += find(list.begin(), list.end(), b2[2]) != list.end() ? curr = b2[2], 1 : 0;
				total += find(list.begin(), list.end(), b2[3]) != list.end() ? curr = b2[3], 1 : 0;
				break;
			case 3:
				total += find(list.begin(), list.end(), b3[0]) != list.end() ? curr = b3[0], 1 : 0;
				total += find(list.begin(), list.end(), b3[1]) != list.end() ? curr = b3[1], 1 : 0;
				total += find(list.begin(), list.end(), b3[2]) != list.end() ? curr = b3[2], 1 : 0;
				total += find(list.begin(), list.end(), b3[3]) != list.end() ? curr = b3[3], 1 : 0;
				break;
			case 4:
				total += find(list.begin(), list.end(), b4[0]) != list.end() ? curr = b4[0], 1 : 0;
				total += find(list.begin(), list.end(), b4[1]) != list.end() ? curr = b4[1], 1 : 0;
				total += find(list.begin(), list.end(), b4[2]) != list.end() ? curr = b4[2], 1 : 0;
				total += find(list.begin(), list.end(), b4[3]) != list.end() ? curr = b4[3], 1 : 0;
				break;
		}
		printf("Case #%d: ", i);
		if (total == 0)
			printf("Volunteer cheated!\n");
		else if (total == 1)
			printf("%d\n", curr);
		else
			printf("Bad magician!\n");
	}
}