#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

string A[128];
int sz[128], st[128], cn[128];

void do_case(int case_no) {
	int N;
	cin >> N;
	FOR(i,0,N) {
		cin >> A[i];
		sz[i] = A[i].size();
		st[i] = 0;
	}
	int res = 0;
	int done = 0;
	while(!done) {
		FOR(i,1,N) if(A[0][st[0]] != A[i][st[i]]) {
			goto FEGLA_WON;
		}
		FOR(i,0,N) {
			cn[i] = 1;
			FOR(j,st[i]+1,sz[i]) {
				if(A[i][j] == A[i][j-1]) {
					cn[i]++;
				} else break;
			}
			st[i] += cn[i];
		}
		int be = 1000000;
		FOR(t,1,101) {
			int r = 0;
			FOR(i,0,N) r += abs(t-cn[i]);
			be = min(be,r);
		}
		res += be;
		done = 1;
		FOR(i,0,N) if (st[i] != sz[i]) done = 0;
		if (!done) {
			FOR(i,0,N) if (st[i] == sz[i]) {
				goto FEGLA_WON;
			}
		}
	}
	cout << "Case #" << case_no << ": " << res << endl;
	return;
FEGLA_WON:
	cout << "Case #" << case_no << ": Fegla Won" << endl;
}

int main() {
	int T;
	cin >> T;
	for(int te=1;te<=T;te++) {
		do_case(te);
	}
	return 0;
}