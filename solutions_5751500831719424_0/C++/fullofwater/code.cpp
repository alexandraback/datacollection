#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int T,Cas=0,N;

char s[110][128], core[128];
int it[110], cnt[110];

int main() {
	scanf("%d",&T);
	while (T--) {
    scanf("%d", &N);
    for (int i=0;i<N;i++)
      scanf("%s", s[i]);
    memset(it,0,sizeof(it));
    bool yes=true;
    int total=0;
    while (true) {
      int base=s[0][it[0]];
      memset(cnt,0,sizeof(cnt));
      for (int i=0;i<N;i++) {
        int old=it[i];
        while (s[i][it[i]]==base)
          ++it[i];
        cnt[i]=it[i]-old;
      }
      sort(cnt,cnt+N);
      if (!cnt[0]) {
        yes=false;
        break;
      }
      if (!base)
        break;
      int center=cnt[N/2];
      for (int i=0;i<N;i++)
        total+=abs(cnt[i]-center);
    }
    printf("Case #%d: ", ++Cas);
    if (yes)
      printf("%d\n", total);
    else
      puts("Fegla Won");
	}
}