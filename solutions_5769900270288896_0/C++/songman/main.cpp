#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <map>

#define UREP(i,n) for(unsigned int i=0;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FRVR for(;;)

typedef unsigned long long int ULINT;
typedef long long int LINT;

const double EPS = 1e-6;

using namespace std;

void process(int caseNum) {
    int r,c;
    cin >> r >> c;

    int ** grid = new int*[r];
    REP(i, r) {
        grid[i] = new int[c];
        REP(j, c) {
            grid[i][j] = 0;
        }
    }

    int n;
    cin >> n;

    int tmp = n;

    while(tmp>0) {
        int maxval = 5;
        int maxr, maxc;

        REP(i, r) {
            REP(j, c) {
                if(grid[i][j]==1) continue;
                int val = 0;
                if(i>0) val+=grid[i-1][j];
                if(j>0) val+=grid[i][j-1];
                if(i<r-1) val+=grid[i+1][j];
                if(j<c-1) val+=grid[i][j+1];
                if(val < maxval) {
                    maxval = val;
                    maxr = i;
                    maxc = j;
                }
            }
        }

        grid[maxr][maxc] = 1;
        tmp--;
    }

    int unhappy1 = 0;
    REP(i, r) {
        REP(j, c) {
            if(grid[i][j] == 1) {
                if(i<r-1 && grid[i+1][j]==1) unhappy1++;
                if(j<c-1 && grid[i][j+1]==1) unhappy1++;
            }
        }
    }

    REP(i, r) {
        REP(j, c) {
            grid[i][j] = 0;
        }
    }

    int unhappy2;
    if(n>=1 && c>=2) {
        int tmp2 = n -1;
        grid[0][1] = 1;
        while(tmp2>0) {
            int maxval = 5;
            int maxr, maxc;

            REP(i, r) {
                REP(j, c) {
                    if(grid[i][j]==1) continue;
                    int val = 0;
                    if(i>0) val+=grid[i-1][j];
                    if(j>0) val+=grid[i][j-1];
                    if(i<r-1) val+=grid[i+1][j];
                    if(j<c-1) val+=grid[i][j+1];
                    if(val < maxval) {
                        maxval = val;
                        maxr = i;
                        maxc = j;
                    }
                }
            }

            grid[maxr][maxc] = 1;
            tmp2--;
        }

        unhappy2 = 0;
        REP(i, r) {
            REP(j, c) {
                if(grid[i][j] == 1) {
                    if(i<r-1 && grid[i+1][j]==1) unhappy2++;
                    if(j<c-1 && grid[i][j+1]==1) unhappy2++;
                }
            }
        }
    }


    cout << "Case #" << caseNum << ": " << min(unhappy1, unhappy2) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    REP(i, t) {
        process(i+1);
    }

    return 0;
}
