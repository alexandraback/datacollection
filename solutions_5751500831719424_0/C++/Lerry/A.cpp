#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <cstdio>
using namespace std;

bool compare(string a, string b) {
	int j = 0;
	int count = 0;
	for(int i = 0; i < a.size(); i++) {
		if(i > 0 && a[i] == a[i-1]) {
			count++;
			continue;
		}
		while(j < b.size()) {
			if( a[i] != b[j] ) {
				j++;
			}
			else {
				count ++;
				j++;
				break;
			}
		}
	}
	cout << count << endl;
	if(count == a.size()) return true;
	else return false;
}

int main() {
	int T, N;
	scanf("%d", &T);
	int k = 1;
	while(k <= T) {
		scanf("%d", &N);
		vector<string> Q(N);
		vector< vector<pair<int, int> > > Qt(N);
		int slen = -1;
		bool pass = true;
		for(int i = 0; i < N; i++) {
			cin >> Q[i];
			int tail = 0;
			for(int j = 0; j < Q[i].size(); j++) {
				if(j > 0 && Q[i][j] == Q[i][j-1]) {
					Qt[i][tail-1].second += 1;
				}
				else {
					pair<int, int> tp (Q[i][j] - 'a', 1);
					Qt[i].push_back(tp);
					tail++;
				}
			}
			if(slen == -1) slen = tail;
			if(tail != slen) pass = false;
		}
		if(!pass) { 
			printf("Case #%d: Fegla Won\n", k);
			k++;
			continue;
		}
		
		vector<int> St (slen, 0);
		for(int j = 0; j < slen; j++) {
			for(int i = 0; i < N; i++) {
				if(Qt[i][j].first == Qt[0][j].first) {
					St[j] = max(St[j], Qt[i][j].second);
				}
				else {
					pass = false;
					break;
				}
			}
			if(!pass) break;
		}
		
		if(!pass) { 
			printf("Case #%d: Fegla Won\n", k);
			k++;
			continue;
		}
		int ret = 0;
		for(int j = 0; j < slen; j++) {
			int tscore = 0;
			for(int i = 0; i < N; i++) {
				tscore += Qt[i][j].second;
			}
			for(int l = 1; l <= St[j]; l++) {
				int tmp = 0;
				for(int i = 0; i < N; i++) {
					tmp += abs(l-Qt[i][j].second);
				}
				tscore = min(tscore, tmp);
			}
			ret += tscore;
		}
		printf("Case #%d: %d\n", k, ret);
		k++;
	}
	return 0;
}