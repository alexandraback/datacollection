#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("my.in");
ofstream fout("my.out");

struct Point
{
   long long x;
   long long y;
};


long long operator*(const Point &p1, const Point &p2){
  return p1.x*p2.y - p1.y*p2.x;
}

Point operator-(const Point &p1, const Point &p2){
  Point ret;
  ret.x = p1.x - p2.x;
  ret.y = p1.y - p2.y;
  return ret;
}
int n;
Point a[3001];

int bar(int k){

  int ret = n;
  for(int i=1; i<=n; i++)
    if(k!=i){
      Point key = a[i] - a[k];
      int count1 = 0;
      int count2 = 0;
      for(int j=1; j<=n; j++){
        long long temp = key*(a[j]-a[k]);
        if(temp > 0) count1++;
        else if(temp < 0) count2++;
      }
      //cout << count1 << " " << count2 << endl;
      ret = min(ret, min(count1, count2));
    }

  return ret;   
}
void foo(){
  fin >> n;


  for(int i=1; i<=n; i++)
    fin >> a[i].x >> a[i].y;

  if(n<=3){
    for(int i=1; i<=n; i++)
      fout << 0 << endl;
    return;
  }

  for(int i=1; i<=n; i++)
    fout << bar(i) << endl;
}
int main(){
  int M;
  fin >> M;

  cout << M << endl;
  for(int index=1; index<=M; index++){
    fout << "Case #" << index << ": " << endl;
    foo();
  }

  return 0;
}