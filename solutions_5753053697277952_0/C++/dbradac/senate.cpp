#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 30;

int br[MAX];
set <P> S;

void Smanji(int x)
{
  S.erase(P(-br[x], x));
  br[x]--;
  S.insert(P(-br[x], x));
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int ind=1; ind<=brt; ind++) {
    printf("Case #%d: ", ind);

    int n;
    scanf("%d", &n);
    S.clear();
    for (int i=0; i<n; i++) {
      scanf("%d", &br[i]);
      S.insert(P(-br[i], i));
    }

    for (;;) {
      auto it = S.begin();
      if (!(it->X))
        break;
      auto it2 = it; it2++;
      auto it3 = it2; it3++;

      if (it->X == it2->X && (it3 == S.end() || !(it3->X))) {
        printf("%c%c ", 'A' + it->Y, 'A' + it2->Y);
        Smanji(it->Y);
        Smanji(it2->Y);
      }
      else {
        printf("%c ", 'A' + it->Y);
        Smanji(it->Y);
      }
    }

    printf("\n");
  }

  return 0;
}

