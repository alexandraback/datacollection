#include <stdio.h>
#include <algorithm>
using namespace std;

int n,t,s;
int data[26];
int temp_a[26];
int temp_b[26];

int get_max(int a[], int e)
{
  int m = -1;

  for (int i=0; i<n; i++) {
    if (i!=e && (m==-1 || a[m] < a[i])) {
      m = i;
    }
  }

  return m;
}

int main(void)
{
  int i,j,k;
  int max_a,max_b,max_c;

  FILE *in = fopen("input.txt","r");
  FILE *out = fopen("output.txt","w");

  fscanf(in,"%d",&t);
  for (k=0; k<t; k++) {
    fscanf(in,"%d",&n);
    s = 0;
    for (i=0; i<n; i++) {
      fscanf(in,"%d",&data[i]);
      s += data[i];
    }

    fprintf(out,"Case #%d: ", k+1);
    while (1) {
      for (i=0; i<n; i++)
        if (data[i] != 0)
          break;

      if (i==n)
        break;

      max_a = get_max(data,-1);
      max_b = get_max(data,max_a);
      for (i=0; i<n; i++) {
        temp_a[i] = data[i];
        temp_b[i] = data[i];
      }

      temp_a[max_a]--;
      temp_a[max_b]--;
      temp_b[max_a]--;
      max_c = get_max(temp_a,-1);

      if ((float)(s-2)/2.0 >= temp_a[max_c]) {
        data[max_a]--;
        data[max_b]--;
        s -= 2;
        fprintf(out,"%c%c ",max_a+'A',max_b+'A');
      }
      else {
        data[max_a]--;
        s -= 1;
        fprintf(out,"%c ",max_a+'A');
      }
    }
    fprintf(out,"\n");
  }
  return 0;
}
