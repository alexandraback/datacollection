										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int r, c, n, k;
vector <int> v[2];

int main(){
	freopen("B-Noisy Neighbors.in", "r", stdin);
	freopen("B-Noisy Neighbors.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> r >> c >> k;
		v[0].clear();
		v[1].clear();
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				int cnt = 0;
				if(i > 0) cnt++;
				if(i < r - 1) cnt++;
				if(j > 0) cnt++;
				if(j < c - 1) cnt++;
				int idx = (i + j) % 2;
				v[idx].push_back(0);
				v[1 - idx].push_back(cnt);
			}
		}
		int sum[2];
		for(int i = 0; i < 2; i++){
			sum[i] = 0;
			sort(v[i].begin(), v[i].end());
			for(int j = 0; j < k; j++)
				sum[i] += v[i][j];
		}
		cout << "Case #" << ++test << ": " << min(sum[0], sum[1]) << endl;
	}
	return 0;
}
