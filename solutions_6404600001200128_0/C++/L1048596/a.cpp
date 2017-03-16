#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("my.out");


int a[1000];
int n;
int foo(){
  int ret = 0;
  for(int i=1; i<n; i++)
    ret += max(0, a[i-1]-a[i]);
  return ret;
}

int bar(){
  int ret = 0;
  int maxv = 0;
  for(int i=1; i<n; i++){
    maxv = max(maxv, a[i-1]-a[i]);
  }

  for(int i=1; i<n; i++){
    ret += min(maxv, a[i-1]);
  }
  return ret;
}
int main(){
  int M;
  fin >> M;
  for(int index=1; index<=M; index++){
      fin >> n;
      for(int i=0; i<n; i++)
        fin >> a[i];
      fout << "Case #" << index << ": " << foo() << " " << bar() << endl;
  }
  return 0;
}