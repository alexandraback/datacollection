#include<fstream>
#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

#define FL(i, a, b) for(int i = a; i < b; i++)
#define MIN(a, b) ((a > b)? b : a)
#define MAX(a, b) ((a > b)? a : b)

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("file input\n");
    return -1;
  }

  ifstream fin(argv[1]);

  int N;

  int T;
  fin>>T;
  FL(t,0,T) {
    fin>>N;
    int* m = new int[N];
    FL(i,0,N)
      fin>>m[i];

    int ansA = 0;
    FL(i,1,N) {
      if (m[i-1] > m[i]) {
        ansA += m[i-1] - m[i];
      }
    }

    int ansB = 0;
    int bar = 0;
    FL(i,1,N) {
      if (m[i-1] > m[i]) {
        int update = m[i-1] - m[i];
        if (bar < update) {
          bar = update;
        }
      }
    }

//cout<<bar<<endl;

    FL(i,1,N) {
      if (m[i-1] > m[i]) {
        int update = m[i-1] - m[i];
        ansB += MIN(bar, m[i-1]);
//cout<<bar<<" "<<update<<" "<<m[i-1]<<endl;
      } else {
        ansB += MIN(bar, m[i-1]);
      }
//cout<<bar<<" "<<m[i-1]<<endl;
    }

    printf("Case #%d: %d %d\n",t + 1,ansA,ansB);
  }
  return 0;
}

