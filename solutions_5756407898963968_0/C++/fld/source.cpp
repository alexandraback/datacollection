/*
   Google Code Jam
   Author: FLD 
   Date: 2014/04/12
*/

#include <iostream>
#include <stdio.h>

using namespace std;


#define BAD_MAGICIAN "Bad magician!"
#define VOLUNTEER_CHEATED "Volunteer cheated!" 

#define FOR(loop,first,end) for(int loop=(int)(first);loop<(int)(end);loop++)
#define REP(loop,times) FOR(loop,0,times)



int main(int argc, char const *argv[])
{
	int T, A1, A2, V, unused;
	int R1[4], R2[4];

	// adjust stding and stdout
	#ifdef DEFAULT
	freopen("stdin.txt","rt",stdin);
	#endif
	#ifdef SMALL
	freopen("stdin_small.txt","rt",stdin);
	freopen("stdout_small.txt","wt",stdout);
	#endif

	cin >> T;
	REP(t,T) {
		printf("Case #%d: ", t+1);
		cin >> A1;
		A1--;
		REP(r, 4) {
			if (r == A1) {
				REP(v,4) {
					cin >> R1[v];
				}
			} else {
				REP(v,4) {
					cin >> unused;
				}
			}
		}
		cin >> A2;
		A2--;
		REP(r, 4) {
			if (r == A2) {
				REP(v,4) {
					cin >> R2[v];
				}
			} else {
				REP(v,4) {
					cin >> unused;
				}
			}
		}

		V = 0;
		REP(r1,4) {
			REP(r2, 4) {
				if (R1[r1] == R2[r2]) {
					if (V == 0) {
						V = R1[r1];
					} else {
						printf("%s\n", BAD_MAGICIAN);
						goto ENDTEST;
					}
				}
			}
		}
		if (V == 0) {
			printf("%s\n", VOLUNTEER_CHEATED);
		} else {
			printf("%d\n", V);
		}
		ENDTEST:;
	}
	
	return 0;
}