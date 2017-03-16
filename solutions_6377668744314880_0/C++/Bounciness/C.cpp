#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define PI 3.14159265
#define eps .000001

int P[3000][2];

int main() {

  int T;
  scanf("%d", &T);
  
  for(int i=1; i<=T; ++i) {
    int N;
    scanf("%d", &N);
    for(int j=0; j<N; ++j) 
      scanf("%d %d", &P[j][0], &P[j][1]);

    printf("Case #%d:\n", i);
    
    if(N==1) {
      printf("0\n");
      continue;
    }
    if(N==2) {
      printf("0\n0\n");
      continue;
    }
    if(N==3) {
      printf("0\n0\n0\n");
      continue;
    }

    for(int j=0; j<N; ++j) {
      vector<double> angles;

      for(int k=0; k<N; ++k) {
	if(k==j)
	  continue;

	double a = atan2(P[k][1]-P[j][1], P[k][0]-P[j][0]);
	//printf("angle between (%d,%d) and (%d,%d) is %.3lf\n", P[j][0], P[j][1], P[k][0], P[k][1], a);
	angles.push_back(a);
      }

      sort(angles.begin(), angles.end());
      //printf("Point %d\n", j);
      for(int k=0; k<N-1; ++k) {
	angles.push_back(angles[k]+2*PI);
	//printf("%.3lf,   ", angles[k]);
      }
      //printf("\n");
      int best = N;

      for(int k=0; k<N-1; k++) {
	double uab = angles[k]+PI + eps;
	//printf("uab=%.3lf\n", uab);
	int lower=k, upper=2*(N-1);
	
	while(lower<upper-1) {
	  int mid = (lower+upper)/2;
	  
	  if(angles[mid]<=uab) {
	    lower=mid;
	  }
	  else {
	    upper=mid;
	  }
	}
	//printf("%d...%d...%.3lf\n", k, lower, angles[lower]);
	int num_equal=0, temp=lower;
	while(angles[temp--]>uab-eps);

	int option1 = N-(lower-k+2);
	int option2 = N-option1+1+num_equal;
	
	if(option1<best)
	  best = option1;
	if(option2<best)
	  best = option2;
      }
      printf("%d\n", best);
    }

  }

  return 0;
}
