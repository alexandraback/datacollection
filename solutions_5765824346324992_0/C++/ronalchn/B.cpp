#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> ms;

// returns place
long long place(long long minutes) {
  long long place=0;
  for (int i=0;i<ms.size();i++) {
    place += 1+minutes/ms[i];
  }
  return place;
}

long long bsearch(long long find, long long mn, long long mx) {
  if (mn==mx) return mn;
  long long mid = (mn+mx)/2;
  //printf("bs %lld - %lld for %lld, mid=%lld = %lld\n",mn,mx,find,mid,place(mid));
  if (place(mid)<find) return bsearch(find,mid+1,mx);
  else return bsearch(find,mn,mid);
}

int barber(long long N, long long min) {
  N -= place(min-1);
  for (int i=0;i<ms.size();i++) {
    if (min%ms[i]==0) N--;
    if (N==0) return i+1;
  }
}

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    ms.clear();
    int B;
    long long N;
    cin >> B >> N;

    for (int i=0;i<B;i++) {
      long long m;
      cin >> m;
      ms.push_back(m);
    }
    long long minutes = bsearch(N,0,N*100000);
    //printf("min = %lld\n",minutes);

    int ans = barber(N, minutes);
    printf("Case #%d: %d\n",t,ans);
    //return 0;
  }

}
