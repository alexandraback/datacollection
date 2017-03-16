#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int coun[30];

int main() {
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);

	int T,cases,N;

	scanf("%d ",&T);

	for (cases=1;cases<=T;cases++){
		scanf("%d ", &N);
		int total = 0;
		for (int i=0;i<N;i++) {
			scanf("%d", &coun[i]);
			total += coun[i];
		}
		printf("Case #%d:",cases);

		while (total > 0){
			int maxi = coun[0] > coun[1] ? 0 : 1;
			int sec = coun[0] > coun[1] ? 1 : 0;

			// printf("Total = %d, maxi = %d, sec = %d\n",total, maxi,sec);
			for (int i=2;i<N;i++) {
				if (coun[i] >= coun[maxi]) {
					sec = maxi;
					maxi = i;
				} else if (coun[i] >= coun[sec]) {
					sec = i;
				}
			}
			//found out the second and the maxi;
			printf(" ");
			if ( coun[sec] * 2 <= (total-2) ) {
				//remove two from the maxi;
				char c = 'A' + maxi;
				printf("%c%c",c,c);
				coun[maxi] -= 2;
				total -= 2;
			} else if (coun[maxi] + coun[sec] < total) {
				char c = 'A' + maxi;
				printf("%c",c);
				coun[maxi] -= 1;
				total -= 1;
			} else if (coun[maxi] > coun[sec]){
				char c = 'A' + maxi;
				printf("%c",c);
				coun[maxi] -= 1;
				total -= 1;
			} else {
				char c1 = 'A' + maxi;
				char c2 = 'A' + sec;
				printf("%c%c",c1,c2);
				coun[maxi] --;
				coun[sec] --;
				total -= 2;
			}
		}

		printf("\n");



	}
}
