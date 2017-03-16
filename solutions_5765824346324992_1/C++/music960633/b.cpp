#include <stdio.h>

int a[1001];

long long cnt(long long time, int b){
   long long ret = 0;
   for(int i=0; i<b; ++i){
      ret += time/a[i];
      if(time%a[i] != 0) ret++;
   }
   return ret;
}

int solve(int b, int n){
   long long lft=1, rgt=200000000000000LL, mid;
   while(lft < rgt){
      mid = (lft + rgt) / 2;
      if(cnt(mid, b) < n) lft = mid+1;
      else rgt = mid;
   }
   lft--;
   // printf("time = %lld\n", lft);
   long long offset = cnt(lft, b);
   for(int i=0; i<b; ++i){
      if(lft % a[i] == 0) offset++;
      if(offset == n) return i+1;
   }
   return -1;
}

int main(){
   int T, b, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%d%d", &b, &n);
      for(int i=0; i<b; ++i) scanf("%d", &a[i]);
      printf("Case #%d: %d\n", t, solve(b, n));
   }

   return 0;
}
