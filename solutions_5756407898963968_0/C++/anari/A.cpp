#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
int main(){
  int tnum;cin>>tnum;
  int tcou=0;
  while (tnum--){
    cout<<"Case #"<<++tcou<<": ";
    int m[2];
    for (int t=0;t<2;++t){
      int mask=0;
      int row;cin>>row;--row;
      for (int i=0;i<4;++i)
        for (int j=0;j<4;++j){
          int num;cin>>num;--num;
          if (row==i)
            mask |= (1<<num);
        }
      m[t]=mask;
    }
    int mask=m[0]&m[1];
    if (mask==0)
      cout<<"Volunteer cheated!";
    else{
      for (int i=0;i<16;++i)
        if (mask==(1<<i)){
          cout<<i+1;
          mask=0;
        }
      if (mask!=0)
        cout<<"Bad magician!";
    }
    cout<<endl;
  }
  return 0;
}
