#include <stdio.h>
#define INF 2147483647

int a[1001];

int first(int n){
   int ans = 0;
   for(int i=1; i<n; ++i){
      if(a[i] < a[i-1]) ans += (a[i-1] - a[i]);
   }
   return ans;
}
int second(int n){
   int ans = INF, tmp;
   for(int k=0; k<=10000; ++k){
      tmp = 0;
      for(int i=1; i<n; ++i){
         if(a[i-1]-k < 0) tmp += a[i-1];
         else tmp += k;
         if(a[i-1]-k > a[i]){
            tmp = INF;
            break;
         }
      }
      if(tmp < ans) ans = tmp;
   }
   return ans;
}

int main(){
   int T, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%d", &n);
      for(int i=0; i<n; ++i) scanf("%d", &a[i]);
      printf("Case #%d: %d %d\n", t, first(n), second(n));
   }

   return 0;
}
