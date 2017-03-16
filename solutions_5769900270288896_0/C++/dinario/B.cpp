#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <mutex> 
#include <bitset>
#include <set>
#include <string>
#include <thread>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL long long
#define EPS 0.00000000001
#define MOD 1000000000
#define INF 2000000000
#define TT 1004
std::mutex mtx;
int T, nmtx = 0;
#define OK(); for(;;){mtx.lock();nmtx++;mtx.unlock();break;}
typedef struct{ int a; }tres;
tres res[TT];

#define M 10
#define N 100008


void solve(int t)
{
	int n, r, c, rs = N;
	
	cin >> r >> c >> n;

	int l = 1 << (r * c);

	int r1 = min(r,c), r2 = max(r,c);

	for (int i = 0; i < l; ++i){
		int prv[M], mask = i, sum = 0, num = 0;
		for (int j = 1; j <= r1; ++j){
			int cr = mask & 1; mask >>= 1;
			num += cr;
			prv[j] = cr;
			sum += prv[j] & prv[j - 1];
		}
		for (int k = 0; k < r2 - 1; ++k){
			for (int j = 1; j <= r1; ++j){
				int cr = mask & 1; mask >>= 1;
				num += cr;
				sum += cr & prv[j];
				prv[j] = cr;
				sum += prv[j] & prv[j - 1];
			}
		}
		if (sum < rs && num == n)rs = sum;
	}
	res[t].a = rs;
	OK();
}

int main() {
	//freopen("B.inB-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B.out", "wt", stdout);

	cin >> T;
	for (int t = 0; t < T; ++t){ thread * ñThread = new thread(std::bind(&solve, t)); }
	for (; nmtx < T;){ this_thread::sleep_for(std::chrono::milliseconds(200)); }

	for (int t = 0; t < T; ++t){
		cout << "Case #" << t + 1 << ": " << res[t].a;
		cout << endl;
	}
	re 0;
}