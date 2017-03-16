#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
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

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int T, teste;
int B, N;
long long aa[110000];

long long calc(long long t_i) {
	if (t_i < 0) return 0;

	long long ret = 0;
	for (int i = 0; i < B; i++) {
		ret += (t_i / aa[i]) + 1;
	}

	return ret;
}

int main() {
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);
		
		scanf("%d %d", &B, &N);
		for (int i = 0; i < B; i++) scanf("%lld", &aa[i]);
		
		long long st = 0, ed = N * 1ll * 1100000;
		while (st < ed) {
			long long mid = (st+ed)/2;
			if (calc(mid) >= N) {
				ed = mid;
			}
			else st = mid+1;
		}


		long long rem = calc(st-1);
		for (int i = 0; i < B; i++) {
			if (st % aa[i] == 0) {
				rem++;
				if (rem == N) {
					printf("%d\n", i+1);
					break;
				}
			}
		}

	}
}