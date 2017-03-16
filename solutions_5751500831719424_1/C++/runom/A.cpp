#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		
		int cnt[101][101] = {};
		string str[101];
		int N;
		cin >> N;
		
		for(int i = 0; i < N; ++i) {
			cin >> str[i];
		}
		
		string p = str[0];
		p.erase(unique(p.begin(), p.end()), p.end());
		
		bool flag = false;
		for(int i = 1; i < N; ++i) {
			string q = str[i];
			q.erase(unique(q.begin(), q.end()), q.end());
			if(p != q) {
				flag = true;
				break;
			}
		}
		
		if(flag) {
			cout << "Fegla Won" << endl;
			continue;
		}
		
		for(int i = 0; i < N; ++i) {
			char c = str[i][0];
			int index = 0;
			int ren = 1;
			for(int j = 1; j < (int)str[i].size(); ++j) {
				if(str[i][j] != c) {
					cnt[i][index++] = ren;
					ren = 1;
					c = str[i][j];
				} else {
					ren++;
				}
			}
			cnt[i][index] = ren;
		}
		
		int ans = 0;
		
		
		for(int i = 0; i < (int)p.size(); ++i) {
			int m = 1 << 20;
			for(int j = 0; j < N; ++j) {
				int d = 0;
				for(int k = 0; k < N; ++k) {
					d += abs(cnt[j][i] - cnt[k][i]);
				}
				m = min(m, d);
			}
			
			ans += m; 
		}
		
		cout << ans << endl;
	}
	return 0;
}