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


void solve(int t)
{
	int n, a[N], mx;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	res[t].a = 0;
	for (int i = 0; i < n; ++i){
		if (i > 0 && a[i - 1] > a[i]){
			res[t].a += a[i - 1] - a[i];
		}
	}

	res[t].b = -1;
	for (int speed = 0; speed <= mx + 1; ++speed){
		int sum = 0; bool bOk = true;

		for (int i = 0; i < n; ++i)if (i > 0)
		{
			if (a[i] < a[i - 1]){
				int del = a[i - 1] - a[i];
				if (del <= speed){
					if (a[i] == 0)sum += del;
					else sum += min(a[i - 1], speed);
				}
				else{
					bOk = false;
					break;
				}
			}
			else{
				sum += min(a[i - 1], speed);
			}
		}
		if (bOk && res[t].b == -1 || res[t].b > sum){
			res[t].b = sum;
		}
	}
	OK();
}

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	
	cin >> T;
	for (int t = 0; t < T; ++t){
		thread * ñThread = new thread(std::bind(&solve, t));
	}
	
	for (; nmtx < T;){ this_thread::sleep_for(std::chrono::milliseconds(50)); }

	for (int t = 0; t < T; ++t){
		cout << "Case #" << t + 1 << ": " <<res[t].a <<" "<<res[t].b;
		cout << endl;
	}
	re 0;
}