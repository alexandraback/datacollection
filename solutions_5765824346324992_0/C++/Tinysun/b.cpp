
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

uint64_t B;
uint64_t N;
uint64_t m[1010];

// calculate P(t)
uint64_t P(uint64_t t)
{
	uint64_t P = 0;
	for (int k = 1; k <= B; k++)
	{
		P += (t / m[k]) + 1;
	}
	return P;
}

uint64_t Solve(void)
{
	uint64_t t_a = 0;
	uint64_t t_b = N * 100000;

	if (P(0) >= N)
		return N;

	while (true)
	{
		uint64_t new_t = (t_b + t_a) / 2;
		if (new_t == t_a)
			break;
		if (P(new_t) < N)
		{
			t_a = new_t;
		}
		else
		{
			t_b = new_t;
		}
	}

	uint64_t  find_k = N - P(t_a);
	for (int k = 1; k <= B; k++)
	{
		if (t_b % m[k] == 0)
			find_k--;
		if (find_k == 0)
			return k;
	}

	return 0;
}

int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		scanf("%llu %llu", &B, &N);
		for (int i = 1; i <= B; i++)
			scanf("%llu", &m[i]);

// 		printf("%llu %llu\n", B, N);
// 		for (int i = 1; i <= B; i++)
// 			printf("%llu ", m[i]);
// 		printf("\n");

		uint64_t ans = Solve();

		printf("Case #%d: %llu", tcase, ans);
		printf("\n");
	}
}

