#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
struct Node {
  int val, id;
}A[26];

bool cmp(const Node &x, const Node &y)
{
    return x.val > y.val;
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t ++) {
     scanf("%d", &n);
     int sum = 0;
     for (int i = 0; i < n; i++) {
        A[i].id = i;
        scanf("%d", &A[i].val);
        sum+= A[i].val;
     }
     printf("Case #%d:", t);
     while (sum > 0) {
       sort(A, A + n, cmp);
       A[0].val--; A[1].val--; sum -=2;
       bool flag = true;
       for (int i = 0; i < n; i++) if (A[i].val > sum/2) {
          flag = false;
          break;
       }
       if (flag) {
          printf(" %c%c", 'A' + A[0].id, 'A' + A[1].id);
       } else {
          A[1].val ++; sum ++;
          flag = true;
          for (int i = 0; i < n; i++) if (A[i].val > sum/2) {
            flag = false;
            break;
          }
         if (flag) {
            printf(" %c", 'A' + A[0].id);
         } else {
            printf(" Wrong");
         }
       }
     }
     printf("\n");
   }
}
