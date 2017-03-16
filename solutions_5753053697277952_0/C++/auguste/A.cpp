#include <cstdio>
#include <algorithm>
using namespace std;

int nb[26];

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
      int n;
      scanf("%d", &n);
      for(int i=0; i<n; i++)
         scanf("%d", &nb[i]);
      int m = n;
      printf("Case #%d: ",_i);
      while(m > 2) {
         int k = 0, j = 0;
         for(int i=0; i<n; i++)
            if(nb[i] > k) {
               k = nb[i];
               j = i;
            }
         printf("%c ", j+'A');
         nb[j]--;
         if(nb[j] == 0)
            m--;
      }
      char a = ' ', b = ' ';
      for(int i=0; i<n; i++)
         if(nb[i] > 0) {
            if(a == ' ')
               a = i + 'A';
            else
               b = i + 'A';
         }
      for(int i=0; i<nb[a-'A']; i++)
         printf("%c%c ", a, b);
      printf("\n");
   }
   return 0;
}
