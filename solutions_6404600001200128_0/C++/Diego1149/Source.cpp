#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 1000

int arr[maxN];

int main() {
	int T, caso = 1, N, first, second, big;
	cin >> T;
	while (T--) {
		cin >> N;
		second = big = first = 0;
		FOR(i, 0, N) {
			cin >> arr[i];
			if (i) {
				if (arr[i] < arr[i - 1]) first += arr[i-1] - arr[i];
				big = max(big, arr[i-1] - arr[i]);
			}
		}
		FOR(i, 0, N-1) {
			second += min(big, arr[i]);
		}
		cout << "Case #" << caso++ << ": " << first << " " << second << endl;
	}
	return 0;
}
