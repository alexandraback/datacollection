#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<queue>
#include<list>
#include<vector>
#define LL long long
#define INF 0x7fffffff
#define For(i,a,b) for(int i=a; i<b; ++i)
using namespace std;
typedef pair<int,int> ii;

int T, R, C, N;
int cal1(){
    int Z = (R * C + 1) / 2;
    int TWO = 0;
    if(R%2==0 || C%2 ==0){
      TWO = 2;
    }
    int TR = 0;
    TR = R+C-2 -TWO;
    int FR = R * C - Z - TWO - TR;
    //printf("%d %d %d %d\n", Z, TWO, TR, FR);
    int ans = 0;
    if(N<=Z){
      ans = 0;
    }
    else if(N <= Z + TWO) {
      ans = 2 * (N-Z);
    }
    else if(N <= Z + TWO + TR){
      ans = 2* TWO + (N-Z-TWO) * 3;
    }
    else if(N <= Z + TWO + TR + FR) {
      ans = 2* TWO + 3 * TR + (N-Z-TWO-TR) * 4;
    }
    return ans;
}
int cal2(){
    int Z = (R * C) / 2;
    int TWO = 4;
    int TR = R+C-2 -TWO;
    int FR = R * C - Z - TWO - TR;
    //printf("%d %d %d %d\n", Z, TWO, TR, FR);
    int ans = 0;
    if(N<=Z){
      ans = 0;
    }
    else if(N <= Z + TWO) {
      ans = 2 * (N-Z);
    }
    else if(N <= Z + TWO + TR){
      ans = 2* TWO + (N-Z-TWO) * 3;
    }
    else if(N <= Z + TWO + TR + FR) {
      ans = 2* TWO + 3 * TR + (N-Z-TWO-TR) * 4;
    }
    return ans;
}
int main(){
  cin>>T;
  for(int cas = 1; cas <= T; ++cas) {
    cin>>R>>C>>N;
    int ans = 0;
    if(R==1 || C ==1){
      if(N<=(R+C)/2){
        ans = 0;
      }
      else{
        ans = (N-(R+C)/2) * 2;
        if((R+C)%2==1) ans -= 1;
      }
    }
    else{
      ans = cal1();
      if(R%2==1 && C%2==1) ans = min(ans, cal2());
    }
    printf("Case #%d: %d\n", cas, ans);
  }
	return 0;
}
