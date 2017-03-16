// In the Name of Allah
// AD13

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
typedef vector <int> VI;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/


/*_____________________________________________________________________________________*/
int main() {
	//*
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	//*/
	int T;
	cin >> T;
	For1 (tc, T) {
		cerr << "--> " << tc << " / " << T << endl;
		int b, n;
		cin >> b >> n;
		int m[1010];
		For (i, b) cin >> m[i];

		int kmm = 1, bmm = m[0], ans = 0;
		For (i, b) bmm = gcd (bmm, m[i]);
		For (i, b) kmm = kmm * m[i];
		//kmm /= bmm;
		For (i, b-1) kmm /= bmm;

		int kmmCnt = 0;
		For (i, b) kmmCnt += kmm / m[i];
		n--;
		n %= kmmCnt;

		if (n < b) ans = n;
		else {
			ans = -1;
			int rem[1010];
			For (i, b) rem[i] = 0;
			int cur = 0;
			while (ans < 0) { // true // cur < n
				//cout << cur << "/" << n << " -> ";
				//For (i, b) cout << rem[i] << ' '; cout << endl;
				For (i, b) {
					if (rem[i] == 0) {
						rem[i] = m[i];
						cur++;
						if (cur > n) { ans = i; break; }
					}
				}
				int mn = rem[0];
				For (i, b) mn = min (mn, rem[i]);
				For (i, b) rem[i] -= mn;
			}
		}

		cout << "Case #" << tc << ": " << ans + 1 << endl;
	}
	
	return 0;
}
/*

*/