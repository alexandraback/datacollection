#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define	mp						make_pair
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))

typedef	long long				LL;

int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}

int solve()
{
	int B, N;

	cin >> B >> N;

	vector<int> Mk(B);
	rep(i, B)
		cin >> Mk[i];

	if(N <= B)
		return N;

	vector<int> bb;
	int lcm = Mk[0];
	For(i, 1, B)
		lcm = lcm / gcd(lcm, Mk[i]) * Mk[i];
	rep(i, B)
		bb.push_back(i + 1);

	pair<LL, int> next[1050];
	rep(i, B)
		next[i] = mp(Mk[i], i);
	make_heap(next, next + B, greater<pair<LL,int>>());

	do {
		pop_heap(next, next + B, greater<pair<LL,int>>());
		if(next[B-1].first == lcm && next[B-1].second == 0)
			break;
		bb.push_back(next[B-1].second + 1);
		next[B-1].first += Mk[next[B-1].second];
		push_heap(next, next + B, greater<pair<LL,int>>());
	} while(true);

	return bb[(N-1)%bb.size()];
}

int main()
{
	int T;
	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
