#include <stdio.h>
#include <vector>

int occupy(int t, int bits) {
	
	if (bits & (1 << t))
		return 1;
	return 0;
}
int calUnhappiness(int cell_state, int R, int C)
{
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			if (i > 0) {
				int s = i*C+j;
				int t = (i-1)*C+j;

				if (occupy(s, cell_state) && occupy(t, cell_state))
					sum ++;
			}
			
			if (j > 0) {
				int s = i*C+j;
				int t = i*C+j-1;

				if (occupy(s, cell_state) && occupy(t, cell_state))
					sum ++;
			}
		}
	}
	return sum;
}


int bitCnt(int bits) 
{
	int res = 0;

	while (bits > 0) {
		res ++;
		bits -= bits & -bits;
	}
	return res;
}

int main()
{	
	FILE* fp = fopen("B-small-attempt0.in", "r");
	FILE* fp_w= fopen("B_out.txt", "w");

	int T;
	fscanf(fp, "%d", &T);

	for (int i = 1; i <= T; i++) {
		int R, C, n;
		fscanf(fp, "%d%d%d", &R, &C, &n);

		std::vector<int> states(R*C);
	
		int res = 1e10;
		for (int j = 0; j < (1 << (R*C)); j++) {
			if (bitCnt(j) != n) 
				continue;

			res = std::min(res, calUnhappiness(j, R, C));
		}

		fprintf(fp_w, "Case #%d: %d\n", i, res);
			 
	}
	
	fclose(fp);
	fclose(fp_w);
	return 0;
}