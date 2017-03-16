// -------------------------------------
// Gherman Alin
// Google code jam 2014
// https://code.google.com/codejam/contest/2974486/dashboard
//
// IDE: VC++ 2010
// OS Windows 7
// -------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

template<typename T> void swap( T& a, T& b ) { T temp = a; a = b; b = temp; }

int cmpIntsAsc(const void * a, const void * b) { return ( *(int*)a - *(int*)b ); }
int cmpIntsDesc(const void * a, const void * b) { return ( *(int*)b - *(int*)a ); }

inline void qsortIntsAsc(int* values, size_t n) { qsort(values, n, sizeof(int), cmpIntsAsc); }
inline void qsortIntsDesc(int* values, size_t n) { qsort(values, n, sizeof(int), cmpIntsDesc); }

void solve();

int main(int argc, char** argv) {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	solve();

	return 0;
}

#define N 4

void solve() {
	const char * bad = "Bad magician!";
	const char * cheated = "Volunteer cheated!";

	int problemCount;

	int pickedCard;
	int r1, r2;
	int mat1[N][N];
	int mat2[N][N];

	int oneCnt, twoCnt;
	int cards[N * N + 2];

	scanf("%d", &problemCount);
	for(int problemIdx = 1; problemIdx <= problemCount; problemIdx++) {
		// Read row 1
		scanf("%d", &r1);
		// Read the matrix 1
		for(size_t i=0; i<N; i++) {
			for(size_t j=0; j<N; j++) {
				scanf("%d", mat1[i] +j);
			}
		}
		// Read row 2
		scanf("%d", &r2);
		// Read the matrix 1
		for(size_t i=0; i<N; i++) {
			for(size_t j=0; j<N; j++) {
				scanf("%d", mat2[i] +j);
			}
		}

		// Reinit the helper structures with default values
		oneCnt = 0;
		twoCnt = 0;
		for(size_t i=0; i< (N*N + 1); i++) {
			cards[i] = 0;
		}

		r1--;
		r2--;
		// actual solving
		for(size_t j=0; j<N; j++) {
			cards[mat1[r1][j]]++;
			cards[mat2[r2][j]]++;
		}

		for(size_t i=0; i< (N*N + 1); i++) {
			if(cards[i] == 1) {
				oneCnt ++;
			}
			else if(cards[i] == 2) {
				twoCnt ++;
				pickedCard = i;
			}
		}

		// print the results
		if(twoCnt > 1) {
			printf("Case #%d: %s\n", problemIdx, bad);
		}
		else if(twoCnt == 1) {
			printf("Case #%d: %d\n", problemIdx, pickedCard);
		}
		else {
			printf("Case #%d: %s\n", problemIdx, cheated);
		}
	}
}