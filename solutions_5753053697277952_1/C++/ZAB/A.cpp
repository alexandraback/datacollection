#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

int N;
vector<int> P;

inline void assert(bool v)
{
	if(!v) 
		throw "ERROR";
}

void readCase()
{
	cin >> N;
	P.clear();
	for(int i = 0; i < N; i++) {
		int p;
		cin >> p;
		P.push_back(p);
	}
}


void solve()
{
	vector< pair<int, char> > parts;
	for(int i = 0; i < N; i++) {
		parts.push_back(make_pair(P[i], 'A' + i));
	}
	sort(parts.begin(), parts.end());
	reverse(parts.begin(), parts.end());
	assert(parts.size() >= 2);
	string spacer = "";
	int diff = parts[0].first - parts[1].first;
	while(diff) {
		cout << spacer, spacer = " ";
		if(diff) cout << parts[0].second, diff--;
		if(diff) cout << parts[0].second, diff--;
	}
	parts[0].first = parts[1].first;
	for(int i = 2; i < N; i++) {
		int cur = parts[i].first;
		while(cur) {
			cout << spacer, spacer = " ";
			if(cur) cout << parts[i].second, cur--;
			if(cur) cout << parts[i].second, cur--;
		}
	}
	int cur = parts[0].first;
	while(cur) {
		cout << spacer, spacer = " ";
		if(cur) cout << parts[0].second << parts[1].second, cur--;
	}
}

int main()
{
	//string fname = "./test/A-example.in";
	//string fname = "./test/A-small-attempt0.in";
	string fname = "./test/A-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

