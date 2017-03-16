#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, N;
	vector<string> v;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		v.clear();
		cin >> N;
		string s;
		for(int i = 0; i < N; ++i){
			cin >> s;
			v.push_back(s);
		}

		vector<string> tmp;
		for(int i = 0; i < N; ++i){
			int ar[26] = {0};
			string st;
			char last = v[i][0];
			st += last;
			for(int j = 1; j < v[i].size(); ++j){
				if(v[i][j] != last){
					last = v[i][j];
					st += last;
				}
			}
			tmp.push_back(st);
		}

		bool flag = true;
		string st = tmp[0];
		for(int i = 1; i < tmp.size(); ++i){
			if(tmp[i] != st) {
				flag = false;
				break;
			}
			st = tmp[i];
		}

		if(!flag){
			cout << "Case #"<< t<<": "<<"Fegla Won"<<endl;
		}
		else {
			//int ans = ( 1 << 29 );
			int ans = 0;
			vector<int> pos(N, 0);
			for(int i = 0; i < tmp[0].size(); ++i){
				char firstChar = tmp[0][i];

				vector<int> t;
				for(int j = 0; j < v.size(); ++j){
					int k = pos[j];
					int cnt = 0;
					while(k < v[j].size() && v[j][k] == firstChar) {
						k++;
						cnt++;
					}
					t.push_back(cnt);
					pos[j] = k;
				}


				sort(t.begin(), t.end());
				int tmpAns = 0;
				int maxx = t[t.size()-1];
				int sz = t.size();
				int median = t[sz/2];
				for(int n = 0; n < t.size(); ++n) {
					ans += abs(t[n] - median);
				}
				/*for(int m = 1; m <= maxx; ++m) {
					int tmpAns = 0;
					for(int n = 0; n < t.size(); ++n) {
						tmpAns += (t[n] - m);
					}
					tmpAns = min(tmpAns, 
				}*/
				
			}


			cout << "Case #" << t <<": "<<ans << endl;
		}
	}

	return 0;
}