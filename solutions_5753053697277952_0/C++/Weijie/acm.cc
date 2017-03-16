#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>

using namespace std;

int a[30];
int n;

int find_max(int x){
  int ret = -1;
  int maxn = -1;
  for(int i = 0;i < n;++i){
    if(i == x)
      continue;
    if(maxn < a[i]){
      maxn = a[i];
      ret = i;
    }
  }
  return ret;
}

void solve(){
  int sum = 0;
  for(int i = 0;i < n;++i)
    sum += a[i];
  while(sum > 0){
    int maxidx = find_max(-1);
    printf(" %c",maxidx + 'A');
    --a[maxidx];
    --sum;
    for(int i = 0;i < n;++i){
      if(i == maxidx)
        continue;
      if(a[i] * 2 > sum){
        printf("%c",i + 'A');
        --sum;
        --a[i];
        break;
      }
    }
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for(int cas = 1;cas <= T;++cas){
    scanf("%d",&n);
    for(int i = 0;i < n;++i)
      scanf("%d",&a[i]);
    printf("Case #%d:",cas);
    solve();
    printf("\n");
  }
  return 0;
}

