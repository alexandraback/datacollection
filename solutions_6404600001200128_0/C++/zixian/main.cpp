#include <cstdio>
#include <algorithm>
using namespace std;

int N, arr[1000];

int computeAns1();
int computeAns2();

int main(){
  int numTC, TC = 1, ans1, ans2;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    ans1 = computeAns1(); ans2 = computeAns2();
    printf("Case #%d: %d %d\n", TC++, ans1, ans2);
  }
  return 0;
}

int computeAns1(){
  int ans = 0;
  for(int i=0; i<N-1; i++)
    if(arr[i+1]<arr[i]) ans+=arr[i]-arr[i+1];
  return ans;
}

int computeAns2(){
  int ans = 0, diff = 0;
  for(int i=0; i<N-1; i++){
    if(arr[i]>=arr[i+1]) diff = max(diff, arr[i]-arr[i+1]);
  }
  for(int i=0; i<N-1; i++) ans+=min(arr[i], diff);
  return ans;
}
