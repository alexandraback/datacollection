#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int ans[2];
int arr1[4][4], arr2[4][4];


void solve()
{
	scanf("%d", &ans[0]);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d", &ans[1]);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0;	 j < 4; ++j) {
			scanf("%d", &arr2[i][j]);
		}
	}

	map<int, int> m;
	int cnt = 0;
	int pos = -1;
	for (int j = 0; j < 4; ++j) {
		m[arr1[ans[0]-1][j]] = 1;
	}
	for (int j = 0; j < 4; ++j) {
		if (m.find(arr2[ans[1]-1][j]) != m.end()) {
			++cnt;
			pos = arr2[ans[1]-1][j];
		}
	}

	if (cnt == 1) {
		printf("%d", pos);
	} else if (cnt == 0) {
		printf("Volunteer cheated!");
	} else {
		printf("Bad magician!");
	}

    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
