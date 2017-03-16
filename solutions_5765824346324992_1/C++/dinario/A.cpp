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
#define TT 200
std::mutex mtx;
int T, nmtx = 0;
#define OK(); for(;;){mtx.lock();nmtx++;mtx.unlock();break;}
typedef struct{ LL a; }tres;
tres res[TT];
#define N 1008
typedef struct{ LL n, a[N], b, mx; }tinp;
tinp inp[TT];


bool check(int t, int i, LL c, bool str = false){
	LL sum = 0;

	for (int j = 0; j < inp[t].b; ++j){
		LL cnt = c / inp[t].a[j];
		LL time = cnt * inp[t].a[j];

		//if (j == i && time != c && str)re false;

		if (time < c && (j != i))
		{
			cnt += 1;
		}

		if (time == c)
		{
			if ((j < i) || (!str&&i!=j))
				cnt += 1;
		}

		sum += cnt;
	}
	if ((sum >= inp[t].n - 1 && !str) || (sum == inp[t].n - 1)){
		re true;
	}
	re false;
}

void solve(int t)
{
	res[t].a = 0;
	
	LL l = 0, r = 1 + inp[t].mx * inp[t].n;
	for (; r - l > 1;)
	{
		LL c = (l + r) / 2;
		bool bOK = false;
		for (int i = 0; i < inp[t].b; ++i){
			if (check(t, i, c)){
				bOK = true;
				break;
			}
		}
		if(bOK)r = c;
		else l = c;
	}
	for (int i = 0; i < inp[t].b; ++i){
		if (check(t, i, l, true)){
			res[t].a = i + 1;
			OK();
			re;
		}
	}
	for (int i = 0; i < inp[t].b; ++i){
		if (check(t, i, r, true)){
			res[t].a = i + 1;
			OK();
			re;
		}
	}
	//res[t].a = k + 1;

	OK();
}

int main() {
	freopen("B-large.in", "rt", stdin);
	//freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	
	cin >> T;
	for (int t = 0; t < T; ++t){
		cin >> inp[t].b >>inp[t].n;
		for (int i = 0; i < inp[t].b; ++i){
			cin >> inp[t].a[i];
			inp[t].mx = max(inp[t].mx, inp[t].a[i]);
		}
		
		thread * ÒThread = new thread(std::bind(&solve, t));
	}
	
	for (; nmtx < T;){ this_thread::sleep_for(std::chrono::milliseconds(50)); }

	for (int t = 0; t < T; ++t){
		cout << "Case #" << t + 1 << ": " << res[t].a;
		cout << endl;
	}
	re 0;
}