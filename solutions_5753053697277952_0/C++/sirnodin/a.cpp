#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <functional>
using namespace std;
struct Part{
  char name;
  int count;
  bool operator < (const Part & other) const {
    return count>other.count;
  }
};
int main() {
  size_t TEST_CASES; cin>>TEST_CASES;
  for(size_t CASE=0;CASE<TEST_CASES;++CASE) {
    int N; cin>>N; vector<Part> M(N);
    int sum=0;
    for(int i=0;i<N;++i) {
      cin>>M[i].count; sum+=M[i].count;
      M[i].name='A'+i;
    }
    printf("Case #%ld:",CASE+1);
    while(sum>0) {
      sort(M.begin(),M.end());
      cout<<" ";
      //int half=(sum-2)/2;
      if(M[0].count==M[1].count) {
        if(N==3 && M[0].count==1 && M[2].count==1){
          cout<<M[0].name;
          M[0].count--; if(M[0].count==0) N--;
          sum--;
        }else{
          cout<<M[0].name<<M[1].name;
          M[0].count--; M[1].count--;
          if(M[0].count==0) N--;
          if(M[1].count==0) N--;
          sum-=2;
        }
      }else{
        cout<<M[0].name;
        M[0].count--;
        if(M[0].count==0) N--;
        sum--;
      }
    }
    cout<<endl;
  }
  return 0;
}
