#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
using namespace std;
typedef struct party{
  int n;
  int pop;
}party;
struct large_than{
  inline bool operator() (const party& x, const party& y){
    return (x.pop > y.pop);
  }
};
int main(){
  int T, N;
  scanf("%d", &T);
  int sum = 0;
  for(int i=1; i<=T; i++){
    scanf("%d", &N);
    vector<party> parties(N);
    party x;
    for(int j=0; j<N; j++){
      x.n = j;
      scanf("%d", &x.pop);
      sum += x.pop;
      parties[j] = x;
    }
    sort(parties.begin(), parties.end(), large_than());
    printf("Case #%d: ", i);
    if(sum % 2 != 0){
      parties[0].pop -= 1;
      sum -= 1;
      printf("%c ", (char)(parties[0].n + 65));
      int cnt = 0;
      while(parties[cnt].pop < parties[cnt+1].pop){
        party temp = parties[cnt];
        parties[cnt] = parties[cnt+1];
        parties[cnt+1] = temp;
        cnt++;
      }
    }
    for(; sum > 0; sum -= 2){
      for(int j=0; j<2; j++){
        parties[0].pop -= 1;
        printf("%c", (char)(parties[0].n + 65));
        int cnt = 0;
        while(parties[cnt].pop < parties[cnt+1].pop){
          party temp = parties[cnt];
          parties[cnt] = parties[cnt+1];
          parties[cnt+1] = temp;
          cnt++;
        }
      }
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
