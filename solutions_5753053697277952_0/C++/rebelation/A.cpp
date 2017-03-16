#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int p[100];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    printf("Case #%d:", o);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> p[i];
      sum += p[i];
    }
    while(sum > 2){
      int mi = 0;
      for(int i = 1; i < n; i++)if(p[mi] < p[i])mi = i;
      p[mi]--;
      printf(" %c", (char)(mi + 'A'));
      sum--;
      for(int i = 0; i < n; i++)
        if(p[i] > sum/2){
          printf("%c", (char)(i + 'A'));
          p[i]--;
          sum--;
          break;
        }
    }
    printf(" ");
    for(int i = 0; i < n; i++)if(p[i] > 0)printf("%c", (char)(i + 'A'));
    printf("\n");
  }

  return 0;
}
