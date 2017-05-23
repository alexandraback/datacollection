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
int arr[100];

int main(){
	freopen("B-Noisy Neighbors.in", "r", stdin);
	freopen("B-Noisy Neighbors.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> r >> c >> k;
		int n = r * c;
		for(int i = 0; i < n; i++)
			arr[i] = (i < n - k ? 0 : 1);
		int res = 2 * r * c;
		do{
			int cnt = 0;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					if(j + 1 < c && arr[i * c + j] && arr[i * c + j + 1])
						cnt++;
					if(i + 1 < r && arr[i * c + j] && arr[(i + 1) * c + j])
						cnt++;
				}
			}
			res = min(res, cnt);
		}
		while(next_permutation(arr, arr + n));
		cout << "Case #" << ++test << ": " << res << endl;
	}
	return 0;
}
