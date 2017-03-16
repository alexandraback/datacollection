#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
int N,R,C;

int compute(int ang, int lat, int N){
  if(N<=ang)
    return N*2;
  if(N<=ang+lat){
    return ang*2 + (N-ang)*3;
  }
  return ang*2 + lat*3 + (N-ang-lat)*4;
}

int solve(){
  cin>>R>>C>>N;
  int base=0;
  if(R%2==0 || C%2==0){
    base= C*R/2;
  }else{
    base = C*R/2+1;
  }
  if(N<=base)
    return 0;
  if(R==1 || C==1){
    int r=min(R,C);
    int c=max(R,C);
    if(c%2==0){
      if(N==r/2+1)
	return 1;
      else
	return 1 + (N-1-c/2)*2;
    }else{
      return 2 * (N-(c/2+1));
    }
  }

  if(R%2==0 || C%2==0){
    int diff = N-base;
    return compute(2,R+C-4,diff);
  }else{
    int diff1=N - ((R*C)/2+1) ;
    int angoli1=0;
    int lati1=(R/2)*2 + (C/2)*2;    
    int diff2= N- (R*C)/2;
    int angoli2=4;
    int lati2=((R-2)/2)*2 + ((C-2)/2)*2;
    return min(compute(angoli1,lati1,diff1),compute(angoli2,lati2,diff2));
  }
  assert(false);
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
