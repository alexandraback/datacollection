#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <string>

using namespace std;

int T, B;
long long N;
long long m[2000];
int cas;

long long check(long long tt)
{
	long long tmp = 0;
	for (int i = 1; i <= B; i++) {
		tmp += tt/m[i];
		if (tt%m[i] != 0)
			tmp++;
	}

	return tmp;
}

void binary_search()
{
	int res;
	long long upper, lower, mid;
	lower = 0;
	upper = 100005LL * N;

	while (lower < upper-1) {
		mid = (lower+upper)/2;
		long long tmp = check(mid);

		if (tmp < N) lower = mid;
		else	upper = mid;
		//printf(" %lld %lld %lld\n", lower, upper, tmp);
	}

	vector< pair<int, int> > ba;
	long long tmp = check(lower);
	for (int i = 1; i <= B; i++) {
		ba.push_back(make_pair(lower%m[i], i));
		//printf("%d %d\n", ba[i-1].first, ba[i-1].second);
	}
	sort(ba.begin(), ba.end());
	res = N-tmp-1;

	printf("Case #%d: %d\n", cas, ba[res].second);
}


int main()
{
	scanf(" %d", &T);

	for (cas = 1; cas <= T; cas++) {
		scanf(" %d %lld", &B, &N);

		for (int i = 1; i <= B; i++)
			scanf(" %lld", &m[i]);

		binary_search();
	}

	return 0;
}