#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

// 最大公約数
ll gcd(ll a, ll b)
{
    while(1)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

// 最小公倍数
ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int get_small(vector<int>& Ms)
{
	int idx = -1;
	int mx = 1000000;
	REP(i, SIZE(Ms)) {
		if (Ms[i] < mx) {
			mx = Ms[i];
			idx = i;
		}
	}
	return idx;
}

void subtract(vector<int>& Ms2, vector<int>& Ms, int minutes, int idx)
{
	REP(i, SIZE(Ms2)) {
		Ms2[i] -= minutes;
		if (i == idx) {
			Ms2[i] += Ms[i];
		}
	}
}

ll solve(){
    int B, N;
    cin >> B >> N;
    vector<int> Ms(B);
    ll lcm_num = 1;
    REP(b, B) {
        cin >> Ms[b];
        lcm_num = lcm(lcm_num, Ms[b]);
    }

	ll cst = 0;
	for (auto M : Ms) {
		cst += lcm_num / M;
	}

	N %= cst;
	N += cst;

	// simulation
	vector<int> Ms2(B);
	while (1) {
		int small_idx = get_small(Ms2);
		if (N == 1) return (small_idx + 1);
		subtract(Ms2, Ms, Ms[small_idx], small_idx);
		--N;
	}
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
		cout << "Case #" << (test + 1) << ": " << solve() << endl;
    }

    return 0;
}
