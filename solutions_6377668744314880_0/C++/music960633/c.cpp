#include <stdio.h>
#include <algorithm>
#include <vector>

struct Point{ long long x, y; } p[101];
int ans[101];

long long lensqr(Point p){
   return p.x*p.x + p.y*p.y;
}

void process(int n, int s){
   std::vector<Point> vec;
   std::vector<int> idx;
   int cnt = 0;
   for(int i=0; i<n; ++i){
      if((s>>i)&1){
         vec.push_back(p[i]);
         idx.push_back(i);
      }
      else
         cnt++;
   }
   // should not happen
   if(cnt == n) return;

   int st=0, now, next;
   for(int i=1, m=vec.size(); i<m; ++i){
      if(vec[i].x < vec[st].x || (vec[i].x == vec[st].x && vec[i].y < vec[st].y)){
         st = i;
      }
   }
   now = st;
   // printf("s = %d\nidx: ", s);
   // for(int i=0; i<idx.size(); ++i)
   //     printf("%d ", idx[i]);
   // printf("\n");
   // printf("st: %lld %lld\n", vec[st].x, vec[st].y);
   // for(int j=0; j<n; ++j){
   while(1){
      next = (now+1) % (vec.size());
      // printf("%lld %lld\n", vec[now].x, vec[now].y);
      for(int i=0, m=vec.size(); i<m; ++i){
         if(i == now) continue;
         Point v1 = (Point){vec[next].x - vec[now].x, 
                            vec[next].y - vec[now].y};
         Point v2 = (Point){vec[i].x - vec[now].x,
                            vec[i].y - vec[now].y};
         if(v2.x*v1.y - v1.x*v2.y > 0) 
            next = i; 
         else if(v2.x*v1.y - v1.x*v2.y == 0 && lensqr(v2) > lensqr(v1))
            next = i;
      }
      for(int i=0, m=vec.size(); i<m; ++i){
         Point v1 = (Point){vec[next].x - vec[now].x, 
                            vec[next].y - vec[now].y};
         Point v2 = (Point){vec[i].x - vec[now].x,
                            vec[i].y - vec[now].y};
         if(v2.x*v1.y - v1.x*v2.y == 0){ 
            if(cnt < ans[idx[i]]) ans[idx[i]] = cnt;
         }
      }
      now = next;
      if(now == st) break;
   }
}

int main(){
   int T, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%d", &n);
      for(int i=0; i<n; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);
      for(int i=0; i<n; ++i) ans[i] = n-1;
      for(int s=1; s<(1<<n); ++s){
         process(n, s);
      }
      printf("Case #%d:\n", t);
      for(int i=0; i<n; ++i) printf("%d\n", ans[i]);
   }

   return 0;
}
