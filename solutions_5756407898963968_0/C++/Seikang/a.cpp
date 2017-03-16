//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

int matA[4][4];
int matB[4][4];
int main()
{
	//freopen ("a.in", "rt", stdin);
	//freopen ("a.out", "wt", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int A, B;

		cin >> A;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> matA[j][k];
			}
		}

		cin >> B;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> matB[j][k];
			}
		}
		A--;
		B--;
		std::map<int, int> dic;
		for (int c = 0; c < 4; ++c)
		{
			dic[matA[A][c]]++;
			dic[matB[B][c]]++;
		}

		set<int> val;
		for (std::map<int, int>::iterator it = dic.begin(); it != dic.end(); it++)
		{
			if(it->second == 2)
				val.insert(it->first);
		}

		cout << "Case #" << i << ": ";
		if(val.size() == 0)
			cout << "Volunteer cheated!" << endl;
		else if(val.size() == 1)
			cout << *val.begin() << endl;
		else 
			cout << "Bad magician!" << endl;
	}
	return 0;
}
