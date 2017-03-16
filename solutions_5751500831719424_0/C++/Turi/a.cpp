#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const double epsilon = 1e-7;

int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
		int N;
		string strings[128];
        cin >> N;
        cin >> strings[0];
		string skel = strings[0];
        skel.erase(unique(skel.begin(), skel.end()), skel.end());

		bool solvable = true;

        for (int i = 1; i < N; i++){
			cin >> strings[i];
			string tmp = strings[i];
			tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
			if (tmp != skel)
				solvable = false;
		}
		
		if (!solvable)
			cout << "Case #" << t+1 << ": Fegla Won" << endl;
		else {
			int res = 0;
			for (unsigned int j = 0; j < skel.length(); j++){
				char c = skel.at(j);
				vector<int> reps;
				int rep_min = numeric_limits<int>::max(), rep_max = -1;
				for (int i = 0; i < N; i++){
					int k;
					if (j < skel.length() - 1)
						k = strings[i].find_first_not_of(c);
					else
						k = strings[i].length();
					rep_min = min(rep_min, k);
					rep_max = max(rep_max, k);
					reps.push_back(k);
					strings[i] = strings[i].erase(0, k);
				}
				
				int best = numeric_limits<int>::max();
				for (int target = rep_min; target <= rep_max; target++){
					int repetitions = 0;
					for (unsigned int i = 0; i < reps.size(); i++)
						repetitions += abs(target - reps[i]);
					best = min(best, repetitions);
				}
				res += best;
				
				reps.clear();
			}
			cout << "Case #" << t+1 << ": " << res << endl;
		}
    }
    return 0;
}
