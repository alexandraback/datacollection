//I hate this town, bacause it's too filled with memories I'd rather forget.
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

//Two becomes one,and it through all eternity.
#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
int TestCase; cin >> TestCase;
for (int ti = 1; ti <= TestCase; ti++){
	printf("Case #%d: ", ti);
	int R, C, n;
	cin >> R >> C >> n;
	if (R > C) swap(R, C);
	if (R == 1 && C == 1){
		cout << 0 << endl;
		continue;
	}
	if (R == 1){
		if (C & 1){
		if (n <= (C + 1) / 2){
			cout << 0 << endl;
			continue;
		}
		n -= C / 2;
		if (n <= 2){
			cout << n << endl;
			continue;
		}
		cout << (n - 2) * 2 + 2 << endl;
		continue;
		}
		if (n <= C / 2){
			cout << 0 << endl;
			continue;
		}
		n -= C / 2;
		if (n <= 1){
			cout << n << endl;
			continue;
		}
		cout << (n - 1) * 2 + 1 << endl;
		continue;
	}
	if ((R & 1) && (C & 1)){
		if (n <= (R * C + 1) / 2){
			cout << 0 << endl;
			continue;
		}
		if (n == (R * C + 2) / 2 + 1){
			cout << 3 << endl;
			continue;
		}
		n -= R * C / 2;
		if (n <= 4){
			cout << n * 2 << endl;
			continue;
		}
		n -= 4;
		int t = (R / 2 - 1 + C / 2 - 1) * 2;
		if (n <= t){
			cout << n * 3 + 8 << endl;
			continue;
		}	
		n -= t;
		
		cout << n * 4 + 8 + t * 3 << endl;;
		continue;
	}
	if ((R % 2 == 0) && (C % 2 == 0)){
		if (n <= R * C / 2){
			cout << 0 << endl;
			continue;
		}
		n -= R * C / 2;
		if (n <= 2){
			cout << n * 2 << endl;
			continue;
		}
		n -= 2;
		int t = (R / 2 - 1 + C / 2 - 1) * 2;
		if (n <= t){
			cout << 4 + n * 3 << endl;
			continue;
		}
		n -= t;
		cout << 4 + t * 3 + n * 4 << endl;
		continue;
	}
	if (C % 2 == 0) swap(R, C);
		if (n <= R * C / 2){
			cout << 0 << endl;
			continue;
		}
		n -= R * C / 2;
		if (n <= 2){
			cout << n * 2 << endl;
			continue;
		}
		n -= 2;
		int t = (R / 2 - 1 + C / 2 - 1) * 2 + 1;
		if (n <= t){
			cout << 4 + n * 3 << endl;
			continue;
		}
		n -= t;
		cout << 4 + t * 3 + n * 4 << endl;
		continue;
	
}    

}
