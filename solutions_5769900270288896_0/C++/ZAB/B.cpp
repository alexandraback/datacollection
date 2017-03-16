#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
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
int R;
int C;
vector<int> src;

int __popcnt(int a)
{
	int cnt = 0;
	while(a) a &= a - 1, cnt++;
	return cnt;
}

void readCase()
{
	cin >> R >> C >> N;
	/*src.clear();
	for(int i = 0; i < N; i++) {
		int s;
		cin >> s;
		src.push_back(s);
	}
	/**/
}

int getm(int i, int j) 
{
	return 1 << ((i * C) + j);
}

int stupidsolve()
{
	int best = INT_MAX;
	
	for(int m = 0; m < (1 << (R * C)); m++) {
		if(__popcnt(m) != N) continue;
		int cur = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(i < R - 1 && m & getm(i, j) && m & getm(i+1, j)) cur++;
				if(j < C - 1 && m & getm(i, j) && m & getm(i, j+1)) cur++;
			}
		}
		best = min(best, cur);
		
	}

	return best;
}

int complexsolve()
{
	return 0;
}

void solve()
{
	int ss = stupidsolve();
	//int cs = complexsolve();

	//if(ss != cs) 
	//	cout << "err!!!";

	cout << ss;// << " " << cs;
}

int main()
{
	//string fname = "./test/B-example.in";
	string fname = "./test/B-small-attempt0.in";
	//string fname = "./test/B-small-attempt1.in";
	//string fname = "./test/B-small-attempt2.in";
	//string fname = "./test/B-small-practice.in";
	//string fname = "./test/B-large-practice.in";
	//string fname = "./test/B-large.in";
	
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

