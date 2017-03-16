#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;

int R, C, N;

int a[100][100];
int best = 0;

void
search(int n, int noise, int I, int J)
{
    if (n == 0) {
       best = std::min(best, noise);
       return;
    }

    for (int i = I; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (i== I and j < J)
               continue;

            if (a[i][j] == 0) {
               a[i][j] = 1;
               int extra = 0;
               if (i > 0 && a[i-1][j] == 1) extra++;
               if (i <R - 1 && a[i+1][j] == 1) extra++;
               if (j >0 && a[i][j-1] == 1) extra++;
               if (j < C- 1 && a[i][j+1] == 1) extra++;

               if (noise + extra < best) {
                  int ii = i;
                  int jj = j + 1;
                  if (jj >= C) {
                     ii++;
                     jj = 0;
                  }

                  search(n - 1, noise + extra, ii, jj);
               }

               a[i][j] = 0;
            }
         }
     }
}

int main()
{
	std::ifstream ifile("infile");
	std::ofstream ofile("outfile");


	int T = 0;
	ifile >> T;

	for (int icase = 1; icase <= T; ++icase) {
        ifile >> R >> C >> N;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; ++j) {
                a[i][j] = 0;
            }
        }

        int M = (R * C + 1) / 2;

        best = std::max(N - M, 0) * 4;
        search(N, 0, 0, 0);

		ofile << "Case #" << icase << ": " << best << std::endl;
	}
}
