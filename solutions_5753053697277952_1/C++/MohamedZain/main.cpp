#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

int T, n, arr[30], sum = 0;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &T);
  for(int t=1; t<=T; t++){
    sum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    priority_queue<ii> pq;
    for(int i=0; i<n; i++){
      pq.push(mp(arr[i], i));
      sum += arr[i];
    }
    printf("Case #%d:", t);
    while(!pq.empty()){
      printf(" %c", (char)(pq.top().second + 'A'));
      sum--;
      auto x = pq.top();
      pq.pop();
      x.first--;
      if(x.first > 0) pq.push(x);
      x = pq.top();
      if(sum > 0 && (sum == 1 || x.first * 2 > sum)){
        printf("%c", (char)(x.second + 'A'));
        pq.pop();
        x.first--;
        if(x.first) pq.push(x);
        sum--;
      }
    }
    puts("");
  }
  return 0;
}
