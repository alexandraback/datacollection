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
typedef struct{ LL a, b; }tres;

tres res[TT];

#define N 1008
typedef struct{ int n, a[N],mx; }tinp;
tinp inp[TT];
void solve(int t)
{
	res[t].a = 0;
	for (int i = 0; i < inp[t].n; ++i){
		if (i > 0 && inp[t].a[i - 1] > inp[t].a[i]){
			res[t].a += inp[t].a[i - 1] - inp[t].a[i];
		}
	}

	res[t].b = -1;
	for (int speed = 0; speed <= inp[t].mx + 1; ++speed){
		LL sum = 0; bool bOk = true;

		for (int i = 0; i < inp[t].n; ++i)if (i > 0)
		{
			if (inp[t].a[i] < inp[t].a[i - 1]){
				int del = inp[t].a[i - 1] - inp[t].a[i];
				if (del <= speed){
					if (inp[t].a[i] == 0)sum += del;
					else sum += min(inp[t].a[i - 1], speed);
				}
				else{
					bOk = false;
					break;
				}
			}
			else{
				sum += min(inp[t].a[i - 1], speed);
			}
		}
		if (bOk && res[t].b == -1 || res[t].b > sum){
			res[t].b = sum;
		}
	}
	OK();
}

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	
	cin >> T;
	for (int t = 0; t < T; ++t){
		cin >> inp[t].n;
		for (int i = 0; i < inp[t].n; ++i){
			cin >> inp[t].a[i];
			inp[t].mx = max(inp[t].mx, inp[t].a[i]);
		}
		
		thread * ÒThread = new thread(std::bind(&solve, t));
	}
	
	for (; nmtx < T;){ this_thread::sleep_for(std::chrono::milliseconds(50)); }

	for (int t = 0; t < T; ++t){
		cout << "Case #" << t + 1 << ": " <<res[t].a <<" "<<res[t].b;
		cout << endl;
	}
	re 0;
}