#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); ++(i))
typedef pair<int, int> ii;
#define x first
#define y second
typedef long long int ll;

#define OK printf("In %s\n", __func__);

int DD;
int num[105][105], flip[105][105];
char arr[105][105], tmp[105][105];



int main() {
  int TTT;
  scanf("%d", &TTT);
  int N;
  REP(iii, TTT) {
    printf("Case #%d: ", iii + 1);
    scanf("%d", &N);
    REP(i, N) {
      scanf("%s", arr[i]);
      strcpy(tmp[i], arr[i]);
    }
    REP(i, N) {
      char *d = unique(tmp[i], tmp[i] + strlen(tmp[i]));
      *d = '\0';
    }
    bool bad = false;
    REP(i, N-1) {
      if (strcmp(tmp[i], tmp[i+1])) {
        printf("Fegla Won\n");
        bad = true;
        break;
      }
    }
    if (bad) continue;
    DD = strlen(tmp[0]);
    REP(i, N) {
      int pnt = 0;
      REP(j, DD) {
        num[i][j] = 0;
        char ee = arr[i][pnt];
        while(ee == arr[i][pnt]) {
          ++num[i][j];
          ++pnt;
        }
      }
    }
    /*
    REP(i, N) {
      REP(j, DD) printf("%d ", num[i][j]);
      printf("\n");
    }
    */
    REP(i, N) REP(j, DD)
      flip[j][i] = num[i][j];
    int sum = 0;
    REP(i, DD) {
      sort(flip[i], flip[i] + N);
      REP(j, N)
        sum += abs(flip[i][N/2] - flip[i][j]);
    }
    printf("%d\n", sum);
  }
}
