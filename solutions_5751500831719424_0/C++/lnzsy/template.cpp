#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		int N;
		fscanf (fin, "%d", &N);
		vector<string> S;

		bool ans=true;

		REP (j, 0, N) {
			char s[200];
			memset(s, 0, sizeof(s));
			fscanf (fin, "%s", s);
			S.push_back (string(s));
		}

		string canonical(1, S[0][0]);
		REP (j, 1, S[0].size()) {
			if (S[0][j] != S[0][j-1])
				canonical.push_back (S[0][j]);
		}

		REP (j, 1, N) {
			string tmp(1, S[j][0]);
			REP (k, 1, S[j].size()) {
				if (S[j][k] != S[j][k-1])
					tmp.push_back (S[j][k]);
			}
			if (tmp != canonical) {
				ans = false;
				break;
			}
		}
//		cerr << canonical << endl;
		vector<vector<int> > count(N, vector<int>(canonical.size(), 0));

		REP (j, 0, N) {
			int cano_index=0;
			REP (k, 0, S[j].size()) {
				if (cano_index>=canonical.size())
					break;

				if (S[j][k] == canonical[cano_index]) {
					count[j][cano_index]++;
				} else {
					cano_index++;
					k--;
				}
			}
		}

		/*
		REP (j, 0, N) {
			REP (k, 0, count[j].size()) {
				cerr << count[j][k] << " ";
			}
			cerr << endl;
		}
		cerr << endl;
		*/

		int cost=0;

		REP (j, 0, canonical.size()) {
			int sum=0;
//			int mark=count[0][j];
			vector<int> tmp;
			REP (k, 0, N) {
				if (count[k][j] == 0) {
					ans = false;
					break;
				}
				sum += count[k][j];
				tmp.push_back (count[k][j]);
//				cost += abs(count[k][j]-mark);
			}
			if (!ans) {
				break;
			}
			sort (tmp.begin(), tmp.end());
			int mark = tmp[tmp.size()/2];

//			int mark = sum/N;
			int tmp_cost1=0;
			REP (k, 0, N) {
				tmp_cost1 += abs(count[k][j]-mark);
			}
			mark = tmp[tmp.size()/2-1];
			int tmp_cost2=0;
			REP (k, 0, N) {
				tmp_cost2 += abs(count[k][j]-mark);
			}
			cost+= min(tmp_cost1, tmp_cost2);
		}

		if (ans) {
			fprintf (fout, "Case #%d: %d\n", i+1, cost);
		} else {
			fprintf (fout, "Case #%d: Fegla Won\n", i+1);
		}
	}

	fclose(fin);
	fclose(fout);
	return 0;
}






