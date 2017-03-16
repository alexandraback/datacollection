#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define maxN 20
#define INF 0X7F7F7F7F

int R,C,N;
int minPoint;
char hasMan[maxN][maxN];

bool IsIn(int x,int y) {
  if(x >= 0 && x < R && y >= 0 && y < C)
    return 1;
  return 0;
}

int DFS(int r,int c,int n,int point) {
  if(n == 0) {
    minPoint = min(minPoint, point);
    return 1;
  }
  if(c == C) {
    DFS(r+1,0,n,point);
    return 0;
  }
  if (r == R)
    return 0;
  if(C-c+(R-r-1)*C < n) {
    return 0;
  }
  if(point >= minPoint) {
    return 1;
  }
  hasMan[r][c] = 1;
  int tmpPoint = point;
  if(IsIn(r-1,c) && hasMan[r-1][c]) {
    tmpPoint++;
  }
  if(IsIn(r,c-1) && hasMan[r][c-1]) {
    tmpPoint++;
  }
//  if(c == C-1 && r+1 < R) {
//    DFS(r+1, 0, n-1, tmpPoint);
//  }
//  else if(c != C-1){
//    DFS(r, c+1, n-1, tmpPoint);
//  }
  DFS(r, c+1, n-1,tmpPoint);
  hasMan[r][c] = 0;
//  if(c == C-1&& r+1 < R) {
//    DFS(r+1, 0, n, point);
//  }
//  else if(c != C-1){
//    DFS(r, c+1, n, point);
//  }
  DFS(r, c+1,n,point);
  return 0;
}

int solve() {
  minPoint = INF;
  memset(hasMan,0,sizeof(hasMan));
  DFS(0,0,N,0);
  cout<<minPoint<<endl;
  return 0;
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++) {
        cout<<"Case #"<<t<<": ";
        cin>>R>>C>>N;
        solve();
    }
    return 0;
}


