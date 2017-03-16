#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

int r[2], a[2][5][5];

void solve() {
	cout << "Case #" << ++CASE << ": ";
	
	int cnt[20];
	memset(cnt,0,sizeof(cnt));
	for(int y = 1; y <= 4; y++) {
		cnt[a[0][r[0]][y]]++;
		cnt[a[1][r[1]][y]]++;
	}
	
	int tot[3];
	memset(tot,0,sizeof(tot));
	int id = 0;
	for(int v = 1; v <= 16; v++) {
		tot[cnt[v]]++;
		if(cnt[v]==2) {
			id = v;
		}
	}
	
	if(tot[2]==0) {
		cout << "Volunteer cheated!" << endl;
	} else if(tot[2]>1) {
		cout << "Bad magician!" << endl;
	} else {
		cout << id << endl;
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(int i = 0; i < TESTS; i++) {
		for(int j = 0; j < 2; j++) {
			cin >> r[j];
			for(int x = 1; x <= 4; x++) {
				for(int y = 1; y <= 4; y++) {
					cin >> a[j][x][y];
				}
			}
		}
		solve();
	}
}
