#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 100010 * 2;


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		int A[5][5], B[5][5], x, y;
		cin >> x;
		for (int i = 1; i <= 4; ++ i)	
			for (int j = 1; j <= 4; ++ j)
				cin >> A[i][j];
		cin >> y;
		for (int i = 1; i <= 4; ++ i)
			for (int j = 1; j <= 4; ++ j)
				cin >> B[i][j];
		int cnt = 0;
		int val = -1;
		for (int i = 1; i <= 4; ++ i)
			for (int j = 1; j <= 4; ++ j)
				if (A[x][i] == B[y][j])
					val = A[x][i], ++ cnt;
		
		printf ("Case #%d: ", cas);
		if (cnt == 0)	puts ("Volunteer cheated!");
		else if (cnt > 1)	puts ("Bad magician!");
		else	cout << val << endl;
	}
	
	
	
	return 0;	
}
