#include<fstream>
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

#define FL(i, a, b) for(int i = a; i < b; i++)
#define MIN(a, b) ((a > b)? b : a)
#define MAX(a, b) ((a > b)? a : b)

unsigned long long gcdr ( int a, int b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("file input\n");
    return -1;
  }

  ifstream fin(argv[1]);

  long B,N;

  int T;
  fin>>T;
  FL(t,0,T) {
    fin>>B>>N;
//cout<<endl<<N<<endl;
    long* M = new long[B];
    FL(i,0,B) {
      fin>>M[i];
//cout<<M[i]<<" ";
    }
//cout<<endl;

//cout<<"common:";
    unsigned long long common = M[0];
    FL(i,1,B) {
      long long gcd = gcdr(M[0], M[i]);
      unsigned long long new_common = common * (M[i] / gcd);
      if (new_common < common) {
        cout<<common<<" "<<" "<<(M[i] / gcd)<<" "<<new_common<<" QQQQ!!"<<endl;
      }
      common = new_common;
//cout<<" "<<common;
    }
//cout<<endl;

    long long base = 0;
    FL(i,0,B) {
      base += common / M[i];
    }

//cout<<"base: "<<base<<endl;
    N %= base;
    if (N == 0) {
      N = base;
    }
//cout<<"new N: "<<N<<endl;
    int ans = -1;
    if (B>=N) {
      ans = N;
    } else {
      long* remain = new long[B];
      FL(i,0,B) {
        remain[i]=M[i];
      }
      N-=B;

      while(ans == -1) {
        long min_time = 10000000000;
        FL(i,0,B) {
          if (min_time > remain[i])
            min_time = remain[i];
        }

        FL(i,0,B) {
          if (min_time >= remain[i]) {
            N--;
            remain[i]=M[i];
            if (N == 0) {
              ans = i+1;
              break;
            }
          } else {
            remain[i]-=min_time;
          }
        }
      }
    }

    printf("Case #%d: %d\n",t + 1,ans);
  }
  return 0;
}

