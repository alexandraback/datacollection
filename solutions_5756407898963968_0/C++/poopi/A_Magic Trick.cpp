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

int cnt[20];
int mat[4][4];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, r, test = 0;
	for(cin >> T; T--; ){
		memset(cnt, 0, sizeof cnt);
		for(int t = 0; t < 2; t++){
			cin >> r;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					cin >> mat[i][j];
			for(int i = 0; i < 4; i++)
				cnt[mat[r - 1][i]]++;
		}
		int idx = -1, tot = 0;
		for(int i = 0; i < 20; i++){
			if(cnt[i] == 2){
				tot++;
				idx = i;
			}
		}
		cout << "Case #" << ++test << ": ";
		if(tot == 0)
			cout << "Volunteer cheated!" << endl;
		else if(tot == 1)
			cout << idx << endl;
		else cout << "Bad magician!" << endl;
	}
	return 0;
}
