#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class mycomparison
{
public:
  bool operator() (const pair<int, long>& lhs, const pair<int, long>&rhs) const
  {
      if(lhs.second != rhs.second)  return (lhs.second > rhs.second);
      else  return (lhs.first > rhs.first);
  }
};

int main(){
    int T, N, B;
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	priority_queue< pair<int, long>, vector<pair<int, long> >, mycomparison > barber;
	scanf(" %d %d ", &B, &N);
	int *M = new int[B];
	int max = 0;
	for(int i=0; i<B; ++i){
	    scanf(" %d ", &M[i]);
	    if(M[i] > max)  max = M[i];
	}
	long long nr = 1;
	long long time = nr * max;
	int np = 0;
	for(int i=0; i<B; ++i)  np += (time/M[i]);
	while(np < N){
	    nr *= 2;
	    time = nr * max;
	    np = 0;
	    for(int i=0; i<B; ++i)  np += (time/M[i]);
	}
	long long left = nr/2;
	long long right = nr;
	long long mid;
	while(left < right){
	    mid = (left+right)/2;
	    time = mid * max;
	    np = 0;
	    for(int i=0; i<B; ++i)  np += (time/M[i]);
	    if(np < N)	left = mid+1;
	    else if(np > N) right = mid;
	    else    break;
	}
	if(np < N)    nr = mid;
	else	nr = mid-1;
	time = nr * max;
	for(int i=0; i<B; ++i){
	    N -= (time / M[i]);
	    barber.push(make_pair(i, (time/M[i])*M[i]-time));
	}
	while(N > 1){
	    pair<int, long> tmp = barber.top();
	    barber.pop();
	    tmp.second += M[tmp.first];
	    barber.push(tmp);
	    --N;
	}
	printf("Case #%d: %d\n", t, barber.top().first+1);
    }
    return 0;
}
