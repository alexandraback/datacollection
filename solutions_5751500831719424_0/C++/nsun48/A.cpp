#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <deque>
#include <set>
#include <queue>
#include <limits>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define LL int64_t

int DEBUG = 0;
#define MAXM 50
#define INFTY numeric_limits<int>::max()

int minabs(int *freq, int n) {
  int ret=INFTY;
  for (int i=0; i<n; i++) {
    int t=0;
    for (int j=0; j<n; j++) {
      t+=abs(freq[j]-freq[i]);
    }
    ret=min(t, ret);
  }
  return ret;
}

main(int argc, char **argv) {
  FILE *fin = (argc>=2) ? freopen(argv[1], "r", stdin) :
    freopen("A.in", "r", stdin);
  assert( fin!=NULL );
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  if(!DEBUG) freopen("A.out", "w", stdout);

  int T;
  cin >> T;
  for(int ii = 0; ii < T; ii++){
    int N;
    cin >> N;
    char s[N][105];
    int len[N];
    for (int i=0; i<N; i++) {
      cin >> s[i];
      len[i]=strlen(s[i]);
    }
    int freq[N][105];
    char sstr[N][105];
    int tmp[N];
    for (int i=0; i<N; i++) {
      tmp[i]=0;
      for (int j=0; j<105; j++) freq[i][j]=0;
    }
    for (int i=0; i<N; i++) {
      for (int j=0; j<len[i]; j++) {
	if (j==0) {
	  sstr[i][tmp[i]]=s[i][j];
	  freq[i][tmp[i]]++;
	} else {
	  if (s[i][j]==sstr[i][tmp[i]]) {
	    freq[i][tmp[i]]++;
	  } else {
	    tmp[i]++;
	    freq[i][tmp[i]]++;
	    sstr[i][tmp[i]]=s[i][j];
	  }
	}
      }
      sstr[i][tmp[i]+1]='\0';
    }
    bool work=true;
    for (int i=1; i<N; i++) {
      if (strcmp(sstr[i],sstr[i-1])!=0) {
	work=false;
	break;
      }
    }
    cout << "Case #" << ii + 1 << ": ";
    if (work) {
      int ans=0;
      for (int v=0; v<=tmp[0]; v++) {
	int t[N];
	for (int i=0; i<N; i++) t[i]=freq[i][v];
	ans+=minabs(t, N);
      }      
      cout << ans << endl;
    } else {
      cout << "Fegla Won" << endl;
    }
  }
  exit(0);
}

// g++ -g A.cpp; ./a.out A.in 1

// cat ../../A.cpp | sed 's/A/newtask/g' > tmp.cpp



