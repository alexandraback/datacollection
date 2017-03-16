#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MXN = 128;
const int MXL = 128;

char text[MXN][MXL];
int tl[MXN][MXL];
int n;
char need[MXL];
int cnt[MXL];
int solve()
{
  int w=0;
  need[w++] = text[0][0];
  for (int i=1; text[0][i]; i++) {
    if (text[0][i] != text[0][i-1]) {
      need[w++] = text[0][i];
    }
  }
  int needl = w;
  need[needl] = 0;
  for (int j=1; j<n; j++) {
    if (text[j][0] != need[0])return -1;
    int p=1;
    for (int i=1; text[j][i]; i++) {
      if (text[j][i] != text[j][i-1]) {
        if (text[j][i] != need[p++])return -1; 
      }
    }
    if (p != needl)return -1;
  }
  for (int i=0; i<n; i++) {
    int p=0;
    tl[i][0] = 1;
    for (int j=1; text[i][j]; j++) {
      if (text[i][j] == text[i][j-1]){
        tl[i][p]++;
      }else {
        tl[i][++p] = 1;
      }
    }
  }
  int ans=0;
  for (int i=0; i<needl; i++)
  {
    memset(cnt, 0, sizeof(cnt));
    int tans=0;
    for (int j=0; j<n; j++){
      //printf("%d[%d]=%d\n", i, j, tl[j][i]);
      cnt[tl[j][i]]++;
      tans += tl[j][i];
    }
    int cles=0;
    int cmore=n;
    int tbest = tans;
    //printf("tans:I:%d ta[0]:%d\n", i, tans);
    for (int k=1; k<MXL; k++) {

      cles+=cnt[k-1];
      tans += cles;
      tans -= cmore;
      cmore -= cnt[k];
      if (tans < tbest)tbest = tans;
      //printf("tans:I:%d ta[%d]:%d\n", i, k, tans);
    }
    ans += tbest;
  }
  if (ans == 0 && strcmp(text[0], text[1]) != 0){
    printf("!!!!!!!!!\n");
    printf("%s\n%s\n", text[0], text[1]);
  }
  return ans; 
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int tn=1; tn<=t; tn++) {
    scanf("%d", &n);
    for (int i=0; i<n; i++)scanf("%s", text[i]);
    int ans = solve();
    printf("Case #%d: ", tn);
    if (ans == -1)puts("Fegla Won");
    else printf("%d\n", ans);
      
  }
  return 0;
}
