
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long double ld;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define Max(a,b) (a)<(b)?(b):(a)
#define Min(a,b) (a)<(b)?(a):(b)

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

char buf[1024];

typedef int ans_t;

ans_t SolveMain(uint64_t N, uint64_t *m);

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint64_t N;
		uint64_t m[1010];
		scanf("%llu", &N);
		for (int i = 0; i < N; i++)
			scanf("%llu", &m[i]);

// 		printf("%llu\n", N);
// 		for (int i = 0; i < N; i++)
// 			printf("%llu ", m[i]);
// 		printf("\n");

//		ans_t ans = SolveMain(N, m);
		uint64_t sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (m[i] > m[i + 1])
				sum += m[i] - m[i + 1];
		}
		int ans1 = sum;

		uint64_t rate = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (m[i] > m[i + 1])
				rate = Max(rate, m[i] - m[i + 1]);
		}
		uint64_t toteat = rate * (N - 1);
		for (int i = 0; i < N - 1; i++)
		{
			if (rate > m[i])
				toteat -= rate - m[i];
		}
		int ans2 = toteat;

		printf("Case #%d: %d %d", tcase, ans1, ans2);
		printf("\n");
	}
}


ans_t SolveMain(uint64_t N, uint64_t *m)
{

	return 0;
}

