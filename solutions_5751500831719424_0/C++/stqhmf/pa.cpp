#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cost(vector<int> &v)
{
  sort(v.begin(), v.end());
  int m = v[(v.size()-1)/2];
  int c = 0;
  for ( int i=0; i<v.size(); ++i )
    c += abs(m-v[i]);
  return c;
}

struct Str
{
  string norm;
  vector<int> w;
  void read()
  {
    norm.clear();
    w.clear();
    char buf[101];
    scanf("%s", buf);
    int len = strlen(buf);
    for ( int i=0; i<len; ++i ) {
      if ( norm.empty() || norm[norm.length()-1]!=buf[i] ) {
	norm += buf[i];
	w.push_back(1);
      }
      else {
	++w[w.size()-1];
      }
    }
  }
  void print()
  {
    printf("Str(norm=%s)", norm.c_str());
    for ( int i=0; i<w.size(); ++i ) printf(" %d", w[i]);
    putchar('\n');
  }
} str[100];

int N;

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &N);
    for ( int i=0; i<N; ++i ) {
      str[i].read();
      //str[i].print();
    }
    //putchar('\n');

    bool norm_equal = true;
    for ( int i=1; i<N; ++i ) {
      if ( str[i].norm != str[0].norm ) {
	norm_equal = false;
	break;
      }
    }

    printf("Case #%d: ", t);
    if ( !norm_equal ) {
      puts("Fegla Won");
    }
    else {
      int total_cost = 0;
      int m = str[0].w.size();
      for ( int i=0; i<m; ++i ) {
	vector<int> v;
	for ( int j=0; j<N; ++j ) {
	  v.push_back( str[j].w[i] );
	}
	int c = cost(v);
	total_cost += c;
      }
      printf("%d\n", total_cost);
    }
  }
}
