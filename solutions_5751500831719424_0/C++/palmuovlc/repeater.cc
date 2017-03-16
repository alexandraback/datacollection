#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct Sparse{
  char let[100];
  int count[100];
  int nlets;
};

void encode(char *s, Sparse *p) {
  int i, j;

  for(i=0, j=-1; s[i]; i++) {
    
    if( i>0 && s[i] == s[i-1] )
      p->count[j]++;
    else {
      j++;
      p->let[j]   = s[i];
      p->count[j] = 1;
      p->nlets    = j+1;
    }

  }
}


int main(int argc, char *argv[]) {

  int T, N;
  char str[101];
  Sparse spa[100];

  scanf("%d", &T);

  for(int t=1; t<=T; t++) {

    //Read info
    scanf("%d", &N);

    int solution = 0;

    for(int i=0; i<N; i++) {
      scanf("%s", str);
      encode(str, &spa[i]);

      //Check if no solution is possible while reading
      if( i>0 ) {
	if( spa[i].nlets != spa[0].nlets )
	  solution = -1;
      }
    }

    //Print sparse encoding
    /*for(int i=0; i<N; i++) {
      printf("%d: [", i);
      for(int j=0; j<spa[i].nlets; j++)
	printf("(%c,%d)", spa[i].let[j], spa[i].count[j]);
      printf("\n");
      }*/

    if( solution >= 0 ) {

      //Check if same set of letters
      for(int i=0; i<spa[0].nlets && solution >= 0; i++)
	for(int j=1; j<N && solution >= 0; j++)
	  if( spa[j].let[i] != spa[0].let[i] )
	    solution = -1;
      
      //Solve
      if( solution >= 0 ) {
	solution = 0;

	vector<int> values(N);
	for(int i=0; i<spa[0].nlets; i++) {
	  
	  for(int j=0; j<N; j++)
	    values[j] = spa[j].count[i];

	  sort(values.begin(), values.end());
	  
	  int median = values[N/2];
	  
	  for(int j=0; j<N; j++)
	    solution += abs(spa[j].count[i] - median);
	}
      }
    }

    //Print solution
    if( solution < 0 )
      printf("Case #%d: Fegla Won\n", t);
    else 
      printf("Case #%d: %d\n", t, solution);

  }

  return 0;
}
