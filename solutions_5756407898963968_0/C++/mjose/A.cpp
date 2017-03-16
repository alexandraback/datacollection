#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

int main(){

  int T;
  scanf("%d",&T);

  for(int i=1;i<T+1;++i){
    vector<int> first;
    vector<int> second;

    int a1;
    scanf("%d",&a1);

    for(int j=0;j<4;++j){
      int a11,a12,a13,a14;
      scanf("%d %d %d %d",&a11,&a12,&a13,&a14);

      if(j+1 == a1){
        first.push_back(a11);
        first.push_back(a12);
        first.push_back(a13);
        first.push_back(a14);
      }
    }

    int a2;
    scanf("%d",&a2);

    for(int j=0;j<4;++j){
      int a21,a22,a23,a24;
      scanf("%d %d %d %d",&a21,&a22,&a23,&a24);

      if(j+1 == a2){
        for(int f=0;f<4;++f){
          if(first[f] == a21) second.push_back(a21);
          if(first[f] == a22) second.push_back(a22);
          if(first[f] == a23) second.push_back(a23);
          if(first[f] == a24) second.push_back(a24);
        }
      }
    }

    string res;

    if(second.empty()){
      res = "Volunteer cheated!";
    }else if(second.size() == 1){
      ostringstream convert;
      convert << second[0];
      res = convert.str();
    }else{
      res = "Bad magician!";
    }

    printf("Case #%d: %s\n",i,res.c_str()); 

  }
}
