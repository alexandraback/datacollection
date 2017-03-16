#include <iostream> 
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <deque>
#include <numeric>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-10;

int main()
{
	int t;
	int n;
	ifstream fin("A-small-attempt1.in");
	ofstream fout("A-small-attempt1.out");
	//ifstream fin("a.in");
	//ofstream fout("a.out");
	fin >> t;
	for (int ti = 1; ti <= t; ti++) {
		bool isOk = true;
		fin >> n;
	//	string s;
		string cur;
		vector<string> a;
		//vector<string> flow;
		//int dup = 0;
		vector<vector<int > > b;
		string iden = "";
		for (int i=0; i<n; i++) {
			fin >> cur;
			if (cur.length() > 1) {
				a.push_back(cur);
				int cur_dup = 1;
				string id = "";
				vector<int> c;
				for (int j=0; j < cur.length() - 1; j++) {
					if (cur[j] == cur[j+1]) {
						cur_dup++;
					} else {
						id += cur[j];
						c.push_back(cur_dup);
						cur_dup = 1;
					}
				}
				if (cur_dup != 1) {
					c.push_back(cur_dup);
					id += cur[cur.length() -1];
				} else if (id[id.length() - 1] != cur[cur.length() -1]) {
					c.push_back(cur_dup);
					id += cur[cur.length() -1];
				}
				b.push_back(c);
				//dup += cur_dup;
				if (i == 0) {
					iden = id;
				} else if (iden != id) {
					isOk = false;
				
				}
			} else {
				string id = cur;
				vector<int> c;
				c.push_back(1);
				b.push_back(c);
				if (i == 0) {
					iden = id;
				} else if (iden != id) {
					isOk = false;
				
				}
			}
		}
		if (!isOk) {
			fout << "Case #" << ti << ": " << "Fegla Won" <<endl;
				continue;
		}
		long long all = 0;
		for (int i=0; i<iden.length(); i++) {
			int min = 100;
			int max = 1;
			for (int j=0; j < b.size(); j++) {
				if (b[j][i]> max) {
					max = b[j][i];
				}
				if (b[j][i] < min) {
					min = b[j][i];
				}
			}
			int best = 100*100;
			
			for (int k=min; k<=max; k++) {
				int count = 0;
				for (int j=0; j < b.size(); j++) {
					count += abs(b[j][i] - k);
				}
				if (count < best) {
					best = count;
				}
			}
			all += best;
		}

		//if ( min < l + 1) {
			fout << "Case #" << ti <<": " << all <<endl;
		

	}

	fout.close();
	return 0;
}



