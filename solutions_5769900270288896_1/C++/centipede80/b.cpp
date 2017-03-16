#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int DEBUG=0;

int doit2(int R, int C, int N) {
  int mem[R][C];
  int tot=R*C;
  int mn=1<<30;
  for(int i=0;i<(1<<tot);i++) {
    int ct=0;
    for(int j=0;j<tot;j++) {
      int y=j/C;
      int x=j%C;
      mem[y][x]=((1<<j)&i)>0;
      ct+=mem[y][x];
    }
    if(ct!=N) continue;
//    cout<<i<<endl;
    int ret=0;
    for(int y=0;y<R;y++) for(int x=0;x<C;x++) if(mem[y][x]) {
      if(y&&mem[y-1][x]) ret++;
      if(x&&mem[y][x-1]) ret++;
      if(y+1<R&&mem[y+1][x]) ret++;
      if(x+1<C&&mem[y][x+1]) ret++;
    }
//    cout<<ret<<endl;
//    if(DEBUG && ret==26) { for(int y=0;y<R;y++) { for(int x=0;x<C;x++) cout<<mem[y][x]; cout<<endl; } cout<<endl; }
    if(ret<mn) mn=ret;
  }
  return mn/2;
}

int doit3(int R, int C, int N) {
  int z=0;
  for(int i=0;i<R;i++) for(int j=0;j<C;j++) if((i+j)%2==0) z++;
  if(z>=N) return 0;
  N-=R*C;
  map<int,int> cts;
  int ret=0;
  for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
    int val=0;
    if(i) val++;
    if(j) val++;
    if(i+1<R) val++;
    if(j+1<C) val++;
    if((i+j)%2==1) cts[val]++;
    ret+=val;
  }
  ret/=2;
  while(N<0&&cts[4]) { ret-=4; N++; cts[4]--; }
  while(N<0&&cts[3]) { ret-=3; N++; cts[3]--; }
  while(N<0&&cts[2]) { ret-=2; N++; cts[2]--; }
  while(N<0&&cts[1]) { ret-=1; N++; cts[1]--; }
  return ret;
}

int doit(int R, int C, int N) {
  int z=0;
  for(int i=0;i<R;i++) for(int j=0;j<C;j++) if((i+j)%2==0) z++;
  if(z>=N) return 0;
  N-=R*C;
  map<int,int> cts;
  int ret=0;
  for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
    int val=0;
    if(i) val++;
    if(j) val++;
    if(i+1<R) val++;
    if(j+1<C) val++;
    if((i+j)%2==0) cts[val]++;
    ret+=val;
  }
  ret/=2;
  while(N<0&&cts[4]) { ret-=4; N++; cts[4]--; }
  while(N<0&&cts[3]) { ret-=3; N++; cts[3]--; }
  while(N<0&&cts[2]) { ret-=2; N++; cts[2]--; }
  while(N<0&&cts[1]) { ret-=1; N++; cts[1]--; }
  return ret;
}

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {    
    int R,C,N;
    DEBUG=(i==150);
    cin >> R >> C >> N;
    int val=min(doit(R,C,N),doit3(R,C,N));
//    if(val != doit2(R,C,N)) cout << i <<" "<<R << " " << C << " " << N << " " << doit(R,C,N) << " " << val << endl;
    cout << "Case #" << (i+1) << ": " << val << endl;
  }
  return 0;
}
