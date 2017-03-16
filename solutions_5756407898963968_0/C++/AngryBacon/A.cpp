#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 10;

int s, t;
int a[N][N];
int b[N][N];

int check(int x)
{
	for(int i = 0; i < 4; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			if (a[i][j] == x) {
				if (s - 1 != i) return false;
			}
			if (b[i][j] == x) {
				if (t - 1 != i) return false;
			}
		}
	}
	return true;
}

void solve(int test)
{
	printf("Case #%d: ", test);
	cin >> s;
	for(int i = 0; i < 4; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			cin >> a[i][j];
		}
	}
	cin >> t;
	for(int i = 0; i < 4; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			cin >> b[i][j];
		}
	}
	int cnt = 0, ret;
	for(int i = 1; i <= 16; ++ i) {
		if (check(i)) {
			++ cnt;
			ret = i;
		}
	}
	if (cnt == 0) {
		cout << "Volunteer cheated!" << endl;
	} else if (cnt > 1) {
		cout << "Bad magician!" << endl;
	} else {
		cout << ret << endl;
	}
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
