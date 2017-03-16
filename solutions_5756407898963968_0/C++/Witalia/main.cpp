#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>

using namespace std;
using namespace std::chrono;

typedef long long ll;

const int N = 16005;
const int K = 605;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;


//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int a[4][4];
		int cnt[16] = {};
		for (int k = 0; k < 2; ++k) {
			int n;
			cin >> n; --n;
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j)
					cin >> a[i][j];
			}
			for (int j = 0; j < 4; ++j)
				cnt[a[n][j] - 1]++;
		}
		int C = 0, x;
		for (int i = 0; i < 16; ++i) {
			if (cnt[i] == 2) {
				x = i + 1;
				C++;
			}
		}
		cout << "Case #" << t + 1 << ": ";
		if (C == 1)
			cout << x << endl;
		else if (C == 0)
			cout << "Volunteer cheated!\n";
		else cout << "Bad magician!\n";
	}
	return 0;
}