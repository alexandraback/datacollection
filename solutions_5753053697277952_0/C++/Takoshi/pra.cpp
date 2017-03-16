#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>
#include <complex>
  
#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define INF_LL 9223372036854775
#define EPS 1e-10
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double 

using namespace std;

#define MAX_T 55
#define MAX_N 26

int TEST_CASE;
int N;
int P[MAX_N];
int PSum;

bool check(int d){
  return d*2 <= PSum;
}

void input(){
  cin >> N;
  PSum = 0;
  for(int i = 0; i < N; i++){
    cin >> P[i];
    PSum += P[i];
  }
}

int main(){

  cin >> TEST_CASE;

  for(int testCase = 0; testCase < TEST_CASE; testCase++){
    
    input();

    string ans;

    int flag = 0;
    while(true){
      flag = 0;
      int n, m = 0;
      for(int i = 0; i < N; i++){
	if(0 < P[i])
	  flag++;
	if(m < P[i]){
	  m = P[i];
	  n = i;
	}
      }
      if(flag == 0)
	break;
      if(flag == 2){
	break;
      }
      else{
	ans += ' ';
	ans += 'A' + n;
	P[n]--;
      }
    }

    if(flag == 2){
      while(true){
	bool _F = false;
	ans += ' ';
	for(int i = 0; i < N; i++){
	  if(0 < P[i]){
	    P[i]--;
	    ans += 'A' + i;
	    _F = true;
	  }
	}
	if(!_F){
	  ans.erase(ans.end()-1);
	  break;
	}
      }
    }

    printf("Case #%d:%s\n", testCase+1, ans.c_str());

  }

  return 0;

}
