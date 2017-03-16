#include<stdio.h>
#include<queue>
#include<queue>
using namespace std;
struct P {
  char c;
  int ct;
  P(char c, int ct):c(c),ct(ct){}

  bool operator<(const P& p) const {
    return ct < p.ct;
  }
};
int main() {
  int tt;
  scanf("%d",&tt);
  for(int T=1;T<=tt;T++){
    priority_queue<P> q;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
      int ct;
      scanf("%d",&ct);
      q.push(P('A'+i,ct));
    }
    printf("Case #%d:",T);
    while(!q.empty()){
      putchar(' ');
      int ct=2;
      while(!q.empty() && ct--) {
        P p=q.top();
        q.pop();
        if(--p.ct){
          q.push(p);
        }
        if (ct==0 && q.size() == 1) {
          p.ct++;
          q.push(p);
        } else {
          printf("%c",p.c);
        }
      }
    }
    putchar(10);
  }
  return 0;
}
