#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;


#define LOGSZ 17


int n, m;
int u[128*128], v[128*128], d[128*128], w[128], inf = 1<<25;

int BellmanFord()
{
	for (int i = 0; i < n; ++i)
		w[i] = -inf;
	w[0] = 0;
	for (int k = 1; k <= n-1; ++k)
		for (int i = 0; i < m; ++i)
			if(w[u[i]] + d[i] > w[v[i]])
				w[v[i]] = w[u[i]] + d[i];

	for (int i = 0; i < m; ++i)
		if(w[u[i]] + d[i] > w[v[i]])
			return -inf;
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret = max(ret, w[i]);
	return ret;
}



int main (int argc, char const* argv[])
{
	// ios::sync_with_stdio(false);
	while(scanf("%d %d", &n, &m) != EOF && !(n == 0 && m == 0)) {
	    for (int i = 0; i < m; ++i) {
		    scanf("%d %d %d", &u[i], &v[i], &d[i]);
		    --u[i], --v[i];
	    }
		int ret = BellmanFord();
		if(ret < 0) {
			printf("Unlimited!\n");
		} else {
			printf("%d\n", ret);
		}
	}
	
	return 0;
}
