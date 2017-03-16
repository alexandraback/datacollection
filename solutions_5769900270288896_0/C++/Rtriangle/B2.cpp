#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool used[19][19];
int N;

int scan(int R, int C) {
	int count = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j) {
			if(used[i+1][j] && used[i][j] && i+1 < R)
				count++;
			if(used[i][j+1] && used[i][j] && j+1 < C)
				count++;
		}
	bool flag = true;
	int el = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(used[i][j])
				el++;
	if(el == N)
		return count;
	return 1000;
}

void clear() {
	for(int i = 0; i <= 18; ++i)
		for(int j = 0; j <= 18; ++j)
			used[i][j] = false;
}

int main() {
	freopen("B-small-attempt0111.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int R, C;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> R >> C >> N;
		int bestres = 1000;
		for(int t = 1; t < 65536; ++t) {
			int tt = t;
			int N1 = 0;
			int numb = 0;
			while(tt > 0) {
				if(tt % 2 == 1) {
					used[N1 / C][N1 % C] = true;
					N1++;
					tt = tt/2;	
					numb++;
				}
				else {
					N1++;
					tt = tt/2;
				}
			}
			if(numb == N) {
				bestres = min(bestres, scan(R, C));
				clear();
			}
			else
				clear();
		}
		if(N == 0)
			cout << "Case #" << i << ": 0\n";
		else
			cout << "Case #" << i << ": " << bestres << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}