//Google Code Jam 2014
//Round 1B
//A

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int count = 1; count <= T; count++) {
		int n;
		bool solvable = true;
		cin >> n;
		vector<string> v(n);
		vector<vector<int> > dist(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		string pattern;
		for(int i = 0; i < n && solvable; i++) {
			string p;
			for(int j = 0; j < v[i].size(); j++) {
				p += v[i][j];
				dist[i].push_back(1);
				while(j < v[i].size()-1 && v[i][j] == v[i][j+1]) { dist[i].back()++; j++; }
			}
			if(i == 0) pattern = p;
			else if(p != pattern) solvable = false;
		}
		cout << "Case #" << count << ": ";
		if(!solvable) {
			cout << "Fegla Won" << endl;
			continue;
		}
		int solution = 0;
		for(int i = 0; i < pattern.size(); i++) {
			int mini = INT_MAX, maxi = 0;
			for(int j = 0; j < n; j++) {
				mini = min(mini, dist[j][i]);
				maxi = max(maxi, dist[j][i]);
			}
			int prop = INT_MAX;
			for(int j = mini; j <= maxi; j++) {
				int p = 0;
				for(int k = 0; k < n; k++) p += abs(j - dist[k][i]);
				prop = min(p, prop);
			}
			solution += prop;
		}
		cout << solution << endl;
	}
	return 0;
}
