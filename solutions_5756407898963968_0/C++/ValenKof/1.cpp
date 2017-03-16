#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <map>
#include <ctime>

using namespace std;

#define PATH "C:\\Users\\ValenKof\\Desktop\\"

#define forn(i, n) for(int i = 0; i < n; ++i)
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

#define print(x) cout << x; // cerr << x; //cout << x;

#define all(x) begin(x), end(x)

int main() {
	freopen(PATH"A-small-attempt0.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int nTests;
	cin >> nTests;
	for (int iTest = 0; iTest < nTests; ++iTest) {
		print("Case #" << iTest + 1 << ": ");

		int iRow;
		cin >> iRow;
		iRow--;
		int arr1[4][4];
		forn (i, 4) forn (j, 4) cin >> arr1[i][j];
		
		int iCol;
		cin >> iCol;
		iCol--;
		int arr2[4][4];
		forn (i, 4) forn (j, 4) cin >> arr2[i][j];
		
		int select1[4];
		forn (i, 4) select1[i] = arr1[iRow][i];
		int select2[4];
		forn (i, 4) select2[i] = arr2[iCol][i];
		
		sort(select1, select1 + 4);
		sort(select2, select2 + 4);
		
		int ans[4];
		
		int n = set_intersection(all(select1), all(select2), ans) - ans;
		
		if (n > 1) print("Bad magician!");
		if (n == 1) print(ans[0]);
		if (n < 1) print("Volunteer cheated!");
		print(endl);
	}
	return 0;
}