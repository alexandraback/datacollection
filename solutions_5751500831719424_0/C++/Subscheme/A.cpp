#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define range(i,a,b) for(int i=(a),_n=(b); i<_n; ++i)



int main() {
	int T;
	cin >> T;
	fo(t,T) {
		cout << "Case #" << t + 1 << ": ";
		int n;
		cin >> n;
		vector<string> s(n);
		fo(i,n) cin >> s[i];

		vector<char> buckets;
		buckets.push_back('\0');
		fo(i,s[0].size()) if(s[0][i] != buckets.back()) buckets.push_back(s[0][i]);
		buckets.push_back('\0');

		vector<vector<int> > sizes;
		bool possible = true;
		fo(i,n) {
			vector<int> size;
			int j = 0;
			fo(k, s[i].size()) {
				if(s[i][k] != buckets[j]) {
					if(s[i][k] != buckets[j+1]) {
						possible = false;
						i = n;
						break;
					}
					++j;
					size.push_back(1);
				} else {
					size.back()++;
				}
			}
			sizes.push_back(size);

			if(size.size() != buckets.size() - 2) {
				possible = false;
				break;
			}
		}

		if(!possible) {
			cout << "Fegla Won\n";
		} else {
			int total = 0;
			fo(i, sizes[0].size()) {
				int best = 100000000;
				range(j,1,101) {
					int count = 0;
					fo(k,n) count += abs(sizes[k][i] - j);
					if(count < best) best = count;
				}
				total += best;
			}
			cout << total << '\n';
		}

	}

}