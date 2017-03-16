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

int N = 0;

vector<string> src;

void readCase()
{
	cin >> N;

	src.clear();

	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		src.push_back(s);
	}
}

void solve()
{
	const string impossible = "Fegla Won";

	int sum = 0;
	
	vector<int> pos;
	pos.assign(N, 0);

	for(int i = 0; i < src[0].size();) {
		char c = src[0][i];
		while(i < src[0].size() && src[0][i] == c) i++;
		vector<int> counts;
		for(int j = 0; j < N; j++) {
			int cnt = 0;
			while(src[j][pos[j]] == c && pos[j] < src[j].size() ) pos[j]++, cnt++;
			if(cnt == 0) {
				cout << impossible;
				return;
			}
			counts.push_back(cnt);
		}		
		int bestc = INT_MAX;
		for(int j = 0; j < N; j++) {
			int sum = 0;
			for(int k = 0; k < N; k++) {
				sum += abs(counts[j] - counts[k]);
			}	   
			bestc = min(bestc, sum);
		}

		sum += bestc;
	}

	for(int i = 0; i < N; i++) {
		if(pos[i] != src[i].size()) {
			cout << impossible;
			return;
		}
	}

	cout << sum;
}

int main()
{
	//string fname = "./test/A-example.in";
	string fname = "./test/A-small-attempt0.in";
	//string fname = "./test/A-large.in";
	
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

