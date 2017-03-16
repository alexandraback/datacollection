#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <utility>
#include <list>
#include <functional>

#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	all(v)					(v).begin(),(v).end()


string solve()
{
	int N;
	int sum = 0;

	cin >> N;

	vector<pair<int, char>> P(N);

	rep(i, N) {
		cin >> P[i].first;
		P[i].second = 'A' + i;
		sum += P[i].first;
	}

	string result;
	if(sum % 2 == 1) {
		sort(all(P), greater<pair<int,char>>());
		result += ' ';
		result += P[0].second;
		sum--;
		P[0].first--;
	}

	while(sum) {
		sort(all(P),greater<pair<int,char>>());
		char f, s;
		int index = 1;

		f = P[0].second;
		P[0].first--;
		if(!P[index].first)
			index = 0;
		s = P[index].second;
		P[index].first--;
		result += ' ';
		result += f;
		result += s;
		sum -= 2;
	}
	return result;
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ":" << solve() << endl;
}

