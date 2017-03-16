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

	int sq = r * c;
	
	int summ = (r - 1) * c + (c - 1)*r;

	int four = ((r - 2)*(c - 2) + 1)/2;

	int tree = (r - 2) / 2 + (r - 2) % 2 ? (c - 2) / 2 : (c - 2 + 1) / 2;

	int two = 4, zero = 0;
	if ((r - 2) % 2)two -= 2;

		int del = sq - n;
		
		int k;
		k = min(four, del);
		summ -= 4 * k;
		del -= k;
		
		k = min(tree, del);
		summ -= 3 * k;
		del -= k;

		k = min(two, del);
		summ -= 2 * k;
	
	res[t].a = max(0,summ);
	OK();
}

int main() {
	//freopen("B.inB-small-attempt0.in", "rt", stdin);
	freopen("B-large.in", "rt", stdin);
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