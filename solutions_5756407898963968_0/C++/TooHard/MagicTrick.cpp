//
// MagicTrick.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 11 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

int ans1, ans2;
int in1[4][4], in2[4][4];

void solve() {
    scanf("%d", &ans1);
    for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	    scanf("%d", &in1[i][j]);
    scanf("%d", &ans2);
    for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	    scanf("%d", &in2[i][j]);
    int found = 0;
    int x;
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
	    if (in1[ans1 - 1][i] == in2[ans2 - 1][j]) {
		x = in1[ans1 - 1][i];
		found++;
		break;
	    }
	}
    }

    if (found == 1) printf("%d\n", x);
    else if (found > 1) printf("Bad magician!\n");
    else printf("Volunteer cheated!\n");
}

int main() {
    int test;
    scanf("%d", &test);
    for (int tt = 0; tt < test; tt++) {
	printf("Case #%d: ", tt + 1);
	solve();
    }
   
    return 0;
}
