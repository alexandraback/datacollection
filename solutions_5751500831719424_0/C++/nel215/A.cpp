#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int main(){
	int T;
	cin >> T;
	REP(testCase, T){
		int N;
		cin >> N;
		vector<string> strs(N);
		vector<vector<pair<char,int> > > charCounters(N,vector<pair<char,int> >());
		REP(i, N)cin >> strs[i];
		REP(i, N){
			char prev = '!';
			REP(j, strs[i].size()){
				if (strs[i][j] != prev){
					charCounters[i].push_back(make_pair(strs[i][j], 1));
					prev = strs[i][j];
				}
				else{
					pair<char, int> &p = charCounters[i].back();
					p.second++;
				}
			}
		}
		//REP(i, N){
		//	REP(j, charCounters[i].size()){
		//		cerr << charCounters[i][j].second << " ";
		//	}
		//	cerr << endl;
		//}
		bool hasAnswer = true;
		int res = 0;
		REP(i, N - 1){
			if (charCounters[i].size() != charCounters[i + 1].size())hasAnswer = false;
			else{
				REP(j, charCounters[i].size()){
					if (charCounters[i][j].first != charCounters[i + 1][j].first){
						hasAnswer = false;
					}
				}
			}
		}
		if (!hasAnswer){
			cout << "Case #" << testCase + 1 << ": Fegla Won" << endl;
		}
		else{
			int minCost = 0;
			REP(i, charCounters[0].size()){
				int pMinCost = 1 << 30;
				for (int len = 1 ; len <= 300; len++){
					int tmp = 0;
					REP(j, N){
						tmp += abs(len - charCounters[j][i].second);
					}
					//cerr << len << " " << tmp << endl;
					pMinCost = min(pMinCost, tmp);
				}
				//cerr << charCounters[0][i].first << " " << pMinCost << endl;
				minCost += pMinCost;
			}
			cout << "Case #" << testCase + 1 << ": " << minCost << endl;
		}
	}
	return 0;
}
