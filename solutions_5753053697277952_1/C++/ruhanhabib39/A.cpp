#include <bits/stdc++.h>
using namespace std;

int N;
int P[100];
char ss[10];
int sm = 0;

void doWork() {
   memset(ss, 0, sizeof(ss));
   int ii = 0;
   for(int i = 0; i < N; i++) {
      if(P[i] == (sm - P[i])) {
         ss[ii++] = 'A' + i;
         P[i]--;
      }
   }
   if(ii == 0) {
      for(int i = 0; i < N; i++) {
         if(P[i]) {
            ss[0] = 'A' + i;
            P[i]--;
            break;
         }
      }
   }
   printf(" %s", ss);
}

void ff() {
   sm = 0;
   for(int i = 0; i < N; i++) {
      sm += P[i];
   }
   while(sm) {
      doWork();
      sm = 0;
      for(int i = 0; i < N; i++) {
         sm += P[i];
      }
   }
}

int main() {
   freopen("inp.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
   int T; scanf("%d", &T);
   for(int cs = 1; cs <= T; cs++) {
      scanf("%d", &N);
      for(int i = 0; i < N; i++) {
         scanf("%d", P + i);
      }
      printf("Case #%d:", cs);
      ff();
      printf("\n");
   }
}
