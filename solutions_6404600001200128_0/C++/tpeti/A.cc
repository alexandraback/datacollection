#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    printf("Case #%d: ",n);
    int N;
    int s1=0,sm=0;
    scanf("%d",&N);
    int a;
    scanf("%d",&a);
    vector<int> v(1,a);
    for (int i=1;i<N;++i) {
      int b;
      scanf("%d",&b);
      v.push_back(b);
      int ab=a-b;
      if (ab>0) s1+=ab;
      if (ab>sm) sm=ab;
      a=b;
    }
    int s2=0;
    for (size_t i=0;i<N-1;++i) {
      s2+=min(v[i],sm);
    }
    printf("%d %d\n",s1,s2);
  }
  return 0;
}

