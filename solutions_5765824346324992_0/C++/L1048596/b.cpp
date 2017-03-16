#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("my.in");
ofstream fout("my.out");

int a[1001];
int t[1001];

int B, n;

bool isOk = false;

int bar(int k){
  for(int i=1; i<=B; i++)
    if(a[i]%k!=0) return false;
  for(int i=1; i<=B; i++){
    a[i] /= k;
    if(a[i] < k) isOk = true;
  }
  return true;
}

int _gcd(int x, int y){
  if(x % y == 0) return y;
  return _gcd(y, x % y);
}
int gcd(int x, int y){
  if(x < y) return _gcd(y, x);
  return _gcd(x, y);
}
int find_min(){
  int minv = t[1];
  for(int i=2; i<=B; i++)
    minv = min(minv, t[i]);

  for(int i=1; i<=B; i++)
    if(minv == t[i]) return i;
}
int foo(){
  int mul = a[1];
  for(int i=2; i<=B; i++){
    int temp = gcd(mul, a[i]);
    mul = mul / temp * a[i];
  }

  cout << mul << endl;
  int sum = 0;
  for(int i=1; i<=B; i++)
    sum = sum + mul / a[i];

  n = n % sum;
  for(int i=1; i<=B; i++) t[i] = 0;
  if(n==0) n+= sum;

  for(int i=1; i<n; i++){
    int k = find_min();
    t[k] += a[k];
  }
  return find_min();
}
int main(){
  int M;
  fin >> M;

  for(int index=1; index<=M; index++){
    fin >> B >> n;
    for(int i=1; i<=B; i++)
      fin >> a[i];

    fout << "Case #" << index << ": " << foo() << endl;
  }
  return 0;
}