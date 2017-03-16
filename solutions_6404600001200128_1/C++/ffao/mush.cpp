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

int n;
int aa[110000];

int T, teste;

int main() {
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);

		scanf("%d", &n);

		int a1 = 0;
		int m = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &aa[i]);
			
			if (i != 0) {
				a1 += max(0, aa[i-1] - aa[i]);
				m = max(m, (aa[i-1] - aa[i]));
			}
		}

		int a2 = 0;
		for (int i = 1; i < n; i++) {
			a2 += min(aa[i-1], m);
		}

		printf("%d %d\n", a1, a2);
	}
}