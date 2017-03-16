#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

int main(){

	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int a[4][4]; set<int> b, c;
		int x, y;
		cin >> x;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				cin >> a[i][j];
			}
		}
		x--;
		for (int i = 0; i < 4; i++){
			b.insert(a[x][i]);
		}
		cin >> y;
		y--;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 4; i++){
			c.insert(a[y][i]);
		}
		vector<int> ans;
		for (set<int>::iterator it = b.begin(); it != b.end(); ++it){
			if (c.find(*it) != c.end()) ans.pb(*it);
		}
		if (ans.size() == 0) cout << "Volunteer cheated!\n"; else
		if (ans.size() > 1) cout << "Bad magician!\n"; else
		cout << ans[0] << "\n";
	}

	return 0;
	
}