#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *f = fopen((argc > 1 ? argv[1] : "in.txt"), "r");
	FILE *g = fopen("out.txt", "w");
	int t;
	char lines[100][110];
	char a[100];
	int a_size;
	char a_counts[100][100];

	fscanf(f, "%d\n", &t);
	for (int test = 0; test < t; test++) {
		bool possible = true;
		int n;
		fscanf(f, "%d\n", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 100; j++)
				lines[i][j] = 0;
			fgets(lines[i], 105, f);
			int j = 0;
			int a_ind = 0;
			while (lines[i][j] >= 'a' && lines[i][j] <= 'z') {
				int j_start = j;
				while (lines[i][j] == lines[i][j_start])
					j++;
				if (i == 0) {
					a[a_ind] = lines[i][j_start];
					a_counts[a_ind][i] = j - j_start;
				} else {
					if (a_ind >= a_size || a[a_ind] != lines[i][j_start])
						possible = false;
					else
						a_counts[a_ind][i] = j - j_start;
				}
				a_ind++;
			}
			if (i > 0 && a_ind < a_size)
				possible = false;
			if (i == 0)
				a_size = a_ind;
		}
		if (!possible) {
			fprintf(g, "Case #%d: Fegla Won\n", test + 1);
			continue;
		}
		int moves = 0;
		for (int a_ind = 0; a_ind < a_size; a_ind++) {
			int c_min = 101;
			int c_max = 0;
			for (int i = 0; i < n; i++) {
				if (a_counts[a_ind][i] < c_min)
					c_min = a_counts[a_ind][i];
				if (a_counts[a_ind][i] > c_max)
					c_max = a_counts[a_ind][i];
			}
			int m_min = 10001;
			for (int c = c_min; c <= c_max; c++) {
				int m_cur = 0;
				for (int i = 0; i < n; i++) {
					if (a_counts[a_ind][i] > c)
						m_cur += a_counts[a_ind][i] - c;
					else
						m_cur += c - a_counts[a_ind][i];
				}
				if (m_cur < m_min)
					m_min = m_cur;
			}
			moves += m_min;
		}
		fprintf(g, "Case #%d: %d\n", test + 1, moves);
	}
	fclose(f);
	fclose(g);
	return 0;
}

